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

.if !defined(WITHOUT_WAD)
EXTRACT_DEPENDS=unzip:${PORTSDIR}/archivers/unzip
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_SDL=	mixer sdl
USE_X_PREFIX=	yes
USE_GMAKE=	yes

.if defined(WITHOUT_WAD)
PLIST_SUB=	WAD:="@comment "
.else
PLIST_SUB=	WAD:=""
.endif

BROKEN=		"Broken pkg-plist"

pre-everything::
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "      WITHOUT_WAD=yes   Don't install the wad file."
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

.include <bsd.port.mk>
