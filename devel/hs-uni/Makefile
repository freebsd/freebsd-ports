# New ports collection makefile for:	hs-uni
# Date created:				8th June 2003
# Whom:					Guy Coleman <gtchask@mm.st>
#
# $FreeBSD$
#

PORTNAME=	uni
PORTVERSION=	0.99
CATEGORIES=	devel haskell
MASTER_SITES=	http://www.informatik.uni-bremen.de/htk/download/
PKGNAMEPREFIX=	hs-
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	gtchask@mm.st
COMMENT=	A tool integration framework for Haskell, including Htk

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
RUN_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		wish8.3:${PORTSDIR}/x11-toolkits/tk83

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

ALL_TARGET=	boot packages

do-install:
		@${MKDIR} ${PREFIX}/lib/uni
		@cd ${WRKSRC} && ${GMAKE} prepareexports
		@cd ${WRKSRC} && ${GMAKE} -s --no-print-directory exportnames | \
		   ${SED} 'y/ /\n/; /^$$/d ; s+${PORTNAME}/++g' | \
		   cpio -pdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/lib/uni
		@${SED} 's|#PWD|${PREFIX}/lib/uni|g' < ${FILESDIR}/ghchtk > ${WRKSRC}/ghchtk
		@${SED} 's|#PWD|${PREFIX}/lib/uni|g' < ${FILESDIR}/ghcihtk > ${WRKSRC}/ghcihtk
		@${SED} 's|#PWD|${PREFIX}/lib/uni|g' < ${FILESDIR}/uni-package.conf > ${WRKSRC}/uni-package.conf

		@${INSTALL_DATA} ${WRKSRC}/uni-package.conf ${PREFIX}/lib/uni
		@${INSTALL_SCRIPT} ${WRKSRC}/ghchtk ${PREFIX}/bin
		@${INSTALL_SCRIPT} ${WRKSRC}/ghcihtk ${PREFIX}/bin
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
