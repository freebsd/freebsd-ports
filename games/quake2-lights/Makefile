PORTNAME=	lights
PORTVERSION=	1
CATEGORIES=	games
MASTER_SITES=	http://bfeared.com/library/quake/archive/quakedev/qudos/quake2/mods/:data \
		LOCAL/alepulver/:src
PKGNAMEPREFIX=	${Q2PKGNAMEPREFIX}
DISTNAME=	Lights.v${PORTVERSION}.Linux
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:data,src \
		Lights-Bots${EXTRACT_SUFX}:src

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Lights and weapon effects modification for Quake II

USES=		gmake tar:bzip2
NO_WRKSUBDIR=	yes
BUILD_WRKSRC=	${WRKSRC}/${PORTNAME}/src
ALL_TARGET=	release

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's/__linux__/__unix__/' ${BUILD_WRKSRC}/q_shared.c
	@${REINPLACE_CMD} -e 's/<malloc\.h>/<stdlib.h>/' \
		${BUILD_WRKSRC}/ace/acebot_compress.c

do-install:
	@${MKDIR} ${STAGEDIR}${Q2DIR}/${PORTNAME}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/release/lights/game.so \
		${STAGEDIR}${Q2DIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/lights/pak99.pak \
		${STAGEDIR}${Q2DIR}/${PORTNAME}
	cd ${WRKSRC}/quake2/lights && ${CP} -a autoexec.cfg demos pics \
		sprites ${STAGEDIR}${Q2DIR}/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/quake2/lights/Readme. \
		${STAGEDIR}${DOCSDIR}/readme.txt

.include "${.CURDIR}/../quake2-data/Makefile.include"
.include <bsd.port.mk>
