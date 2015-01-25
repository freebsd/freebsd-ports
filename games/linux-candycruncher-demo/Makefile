# Created by: Marcus von Appen <mva@sysfault.org>
# $FreeBSD$

PORTNAME=	candycruncher-demo
PORTVERSION=	1.56
CATEGORIES=	games linux
MASTER_SITES=	http://demofiles.linuxgamepublishing.com/candycruncher/
PKGNAMEPREFIX=	linux-
DISTNAME=	candycruncher_demo
EXTRACT_SUFX=	.run

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Candy Cruncher Demo - a fast puzzle game with lots of candies

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes
USE_LINUX_APPS=	alsalib jpeg libogg libvorbis mikmod sdl12 sdlmixer xorglibs
NO_CDROM=	Redistribution is limited, see license
NO_BUILD=	yes

DATADIR=	${PREFIX}/lib/${PKGNAMEPREFIX}${PORTNAME}
SUB_FILES=	candycruncher
PORTDOCS=	README README.licenses README.unixthanks license.txt
LIBFILES=	libcrypto.so.0.9.8 libgrapple-0.9.so.2 liblua.so liblualib.so \
		libssl.so.0.9.8

BROKEN=		Does not fetch

do-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC} && ${TAIL} +377 ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} | \
		${TAR} jxf -

do-build:
	${BRANDELF} -t Linux ${WRKSRC}/bin/Linux/x86/Bin/candycruncher_demo

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/Bin
	@cd ${WRKSRC}/bin/Linux/x86/Bin && \
		${INSTALL_PROGRAM} candycruncher_demo ${STAGEDIR}${DATADIR}/Bin
	@${INSTALL_PROGRAM} ${WRKDIR}/candycruncher \
		${STAGEDIR}${PREFIX}/bin/${PKGNAMEPREFIX}candycruncher
	@${CP} -R ${WRKSRC}/Resources ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}/lib/lib1
	@cd ${WRKSRC}/lib/lib1/ && \
		${CP} ${LIBFILES} ${STAGEDIR}${DATADIR}/lib/lib1
	@${INSTALL} -d ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
