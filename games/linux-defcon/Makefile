# Created by: Marcus von Appen <mva@sysfault.org
# $FreeBSD$

PORTNAME=	defcon
PORTVERSION=	1.42
PORTREVISION=	2
CATEGORIES=	games linux
MASTER_SITES=	http://download.introversion.co.uk/defcon/linux/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Defcon for Linux

ONLY_FOR_ARCHS=	i386 amd64
USES=		linux
USE_LINUX=	dri libogg libvorbis sdl12 xorglibs
NO_CDROM=	Redistribution is limited, see license
NO_BUILD=	yes

DATADIR=	${PREFIX}/lib/${PKGNAMEPREFIX}${PORTNAME}
SUB_FILES=	defcon

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	@cd ${WRKSRC}/lib && \
		${INSTALL_PROGRAM} defcon.bin.x86 ${STAGEDIR}${DATADIR} && \
		${INSTALL_DATA} *.dat open-www.sh ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/defcon \
		${STAGEDIR}${PREFIX}/bin/${PKGNAMEPREFIX}defcon
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/license.txt ${STAGEDIR}${DOCSDIR}/license.txt
	${INSTALL_DATA} ${WRKSRC}/manual.pdf ${STAGEDIR}${DOCSDIR}/manual.pdf

.include <bsd.port.mk>
