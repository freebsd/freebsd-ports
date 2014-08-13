# Created by: Marcus von Appen <mva@sysfault.org>
# $FreeBSD: head/games/linux-hdb-demo/Makefile 340092 2014-01-17 18:09:49Z mva $

PORTNAME=	hdb-demo
PORTVERSION=	1.0
CATEGORIES=	games linux
MASTER_SITES=	http://demofiles.linuxgamepublishing.com/hdb/
PKGNAMEPREFIX=	linux-
DISTNAME=	hdb_demo
EXTRACT_SUFX=	.run

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Hyperspace Delivery Boy Demo - deliver mail and packages

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes
USE_LINUX_APPS=	sdl12 sdlmixer mikmod libogg libvorbis xorglibs
NO_CDROM=	Redistribution is limited, see license
NO_BUILD=	yes

DATADIR=	${PREFIX}/lib/${PKGNAMEPREFIX}${PORTNAME}
SUB_FILES=	hdb
PORTDOCS=	README README.licenses README.unixthanks license.txt

.include <bsd.port.pre.mk>

do-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC} && ${TAIL} +377 ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} | \
		${TAR} jxf -

do-build:
	${BRANDELF} -t Linux ${WRKSRC}/bin/Linux/x86/hdb_demo
	${BRANDELF} -t Linux ${WRKSRC}/bin/Linux/x86/hdb_demo.dynamic

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@cd ${WRKSRC}/bin/Linux/x86 && \
		${INSTALL_PROGRAM} hdb_demo hdb_demo.dynamic ${STAGEDIR}${DATADIR}
	@${INSTALL_PROGRAM} ${WRKDIR}/hdb \
		${STAGEDIR}${PREFIX}/bin/${PKGNAMEPREFIX}hdb
	@${CP} -R ${WRKSRC}/Resources ${STAGEDIR}${DATADIR}
	@${CP} -R ${WRKSRC}/music ${STAGEDIR}${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/hyperdemo.mpc ${STAGEDIR}${DATADIR}
	@${INSTALL} -d ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
