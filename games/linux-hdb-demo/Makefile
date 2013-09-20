# Created by: Marcus von Appen <mva@sysfault.org>
# $FreeBSD$

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

NO_STAGE=	yes
.include <bsd.port.pre.mk>

do-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC} && ${TAIL} +377 ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} | \
		${TAR} jxf -

do-build:
	${BRANDELF} -t Linux ${WRKSRC}/bin/Linux/x86/hdb_demo
	${BRANDELF} -t Linux ${WRKSRC}/bin/Linux/x86/hdb_demo.dynamic

do-install:
	@${MKDIR} ${DATADIR}
	@cd ${WRKSRC}/bin/Linux/x86 && \
		${INSTALL_PROGRAM} hdb_demo hdb_demo.dynamic ${DATADIR}
	@${INSTALL_PROGRAM} ${WRKDIR}/hdb ${PREFIX}/bin/${PKGNAMEPREFIX}hdb
	@${CP} -R ${WRKSRC}/Resources ${DATADIR}
	@${CP} -R ${WRKSRC}/music ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/hyperdemo.mpc ${DATADIR}
.if !defined (NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
