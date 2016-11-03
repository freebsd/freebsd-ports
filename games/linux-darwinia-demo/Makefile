# $FreeBSD$

PORTNAME=	darwinia-demo
PORTVERSION=	1.3.0
PORTREVISION=	2
CATEGORIES=	games linux
MASTER_SITES=	http://download.introversion.co.uk/mirror/introversion/darwinia/downloads/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}2-${PORTVERSION}
EXTRACT_SUFX=	.sh

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Real-time action strategy with programs

ONLY_FOR_ARCHS=	i386 amd64
USES=		linux
USE_LINUX=	dri libogg libvorbis sdl12 xorglibs
NO_CDROM=	Redistribution is limited, see license
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DATADIR=	${PREFIX}/lib/${PKGNAMEPREFIX}${PORTNAME}
SUB_FILES=	darwinia

OPTIONS_DEFINE=	DOCS

do-extract:
	@cd ${WRKSRC} && ${TAIL} +376 ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} | \
		${TAR} zxf -

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	@cd ${WRKSRC}/lib && \
		${INSTALL_PROGRAM} darwinia.bin.x86 ${STAGEDIR}${DATADIR} && \
		${INSTALL_DATA} *.dat open-www.sh ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/darwinia \
		${STAGEDIR}${PREFIX}/bin/${PKGNAMEPREFIX}darwinia
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${STAGEDIR}${DOCSDIR}/LICENSE
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/README

.include <bsd.port.mk>
