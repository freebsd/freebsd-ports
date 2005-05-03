# New ports collection makefile for:	U-Hexen
# Date created:				10 February 2003
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	uhexen
PORTVERSION=	0.601
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://uhexen.sourceforge.net/
DISTNAME=	${PORTNAME}-latest

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Yet another port of Hexen, popular game from Raven Software

USE_SDL=	mixer sdl
USE_X_PREFIX=	yes
USE_GMAKE=	yes

OPTIONS=	NOWAD "Do not install demo-version WAD file" off

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not compile on !i386"
.endif

.if !defined(WITH_NOWAD)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} hexen.zip
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip
PLIST_SUB=	WAD=""
.else
PLIST_SUB=	WAD="@comment "
.endif

PLIST_FILES=	bin/uhexen %%DATADIR%%/.keep_me %%WAD%%%%DATADIR%%/hexen.wad
PLIST_DIRS=	%%DATADIR%%

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-extract:
.if !defined(WITH_NOWAD)
	@${LOCALBASE}/bin/unzip -qo ${_DISTDIR}/hexen.zip \
		-d ${WRKSRC}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/uhexen ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
.if !defined(WITH_NOWAD)
	${INSTALL_DATA} ${WRKSRC}/hexen.wad ${DATADIR}
.endif
	@${TOUCH} ${DATADIR}/.keep_me

.include <bsd.port.post.mk>
