# New ports collection makefile for:	uhexen
# Date created:				10 February 2003
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	uhexen
PORTVERSION=	0.601
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://uhexen.sourceforge.net/
DISTNAME=	${PORTNAME}-latest
.if !defined(WITHOUT_WAD)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} hexen.zip
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.endif

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet another port of Hexen, popular game from Raven Softrware

OPTIONS=	NOWAD "Don't install WAD file" off

USE_SDL=	mixer sdl
USE_X_PREFIX=	yes
USE_GMAKE=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not compile on !i386"
.endif

.if defined(WITH_NOWAD)
WITHOUT_WAD=	yes
.endif

.if !defined(WITHOUT_WAD)
EXTRACT_DEPENDS=unzip:${PORTSDIR}/archivers/unzip
.endif

PLIST_FILES=	bin/uhexen %%DATADIR%%/.keep_me %%WAD%%%%DATADIR%%/hexen.wad
PLIST_DIRS=	%%DATADIR%%

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.if defined(WITHOUT_WAD)
PLIST_SUB=	WAD="@comment "
.else
PLIST_SUB=	WAD=""
.endif

pre-everything::
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "      WITH_NOWAD=yes   Don't install the wad file."
	@${ECHO} ""

post-extract:
.if !defined(WITHOUT_WAD)
	@${LOCALBASE}/bin/unzip -qo ${_DISTDIR}/hexen.zip \
 		-d ${WRKSRC}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/uhexen ${PREFIX}/bin
	${MKDIR} ${DATADIR}
.if !defined(WITHOUT_WAD)
	${INSTALL_DATA} ${WRKSRC}/hexen.wad ${DATADIR}
.endif
	${TOUCH} ${DATADIR}/.keep_me

.include <bsd.port.post.mk>
