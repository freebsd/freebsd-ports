# Created by: Jan Stocker <Jan.Stocker@t-online.de>
# $FreeBSD$

PORTNAME=	egoboo
PORTVERSION=	2.7.5
PORTREVISION=	9
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Linux%20Source%20Distro/${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME:S/-/-data-/}${EXTRACT_SUFX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	3D dungeon crawling adventure in the spirit of NetHack

USES=		gmake dos2unix
USE_SDL=	sdl ttf mixer image
USE_GL=		yes
DOS2UNIX_GLOB=	*.c

WRKSRC=		${WRKDIR}/${DISTNAME}/game
MAKEFILE=	Makefile.unix
MAKE_ARGS=	PREFIX="${STAGEDIR}${PREFIX}"

PLIST_FILES=	bin/${PORTNAME} libexec/${PORTNAME}
PORTDATA=	*

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/egoboo|${DATADIR}|g; \
		s|cp -a|cp -RPp|; s|/usr/libexec|${PREFIX}/libexec|' \
		${WRKSRC}/egoboo.sh

post-install:
	@cd ${WRKDIR}/${DISTNAME:S/-/-data-/} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}

.include <bsd.port.mk>
