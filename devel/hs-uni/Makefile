# New ports collection makefile for:	hs-uni
# Date created:				8th June 2003
# Whom:					Guy Coleman <gtchask@mm.st>
#
# $FreeBSD$
#

PORTNAME=	uni
PORTVERSION=	0.99
PORTREVISION=	2
CATEGORIES=	devel haskell
MASTER_SITES=	http://www.informatik.uni-bremen.de/htk/download/
PKGNAMEPREFIX=	hs-
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	gtchask@mm.st
COMMENT=	A tool integration framework for Haskell, including Htk

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
RUN_DEPENDS=	ghc:${PORTSDIR}/lang/ghc

.include <bsd.port.pre.mk>

.if defined(WITH_TK_VER)
.if ${WITH_TK_VER} == "8.0"
RUN_DEPENDS+=	wish8.0:${PORTSDIR}/x11-toolkits/tk80
.elif ${WITH_TK_VER} == "8.1"
RUN_DEPENDS+=	wish8.1:${PORTSDIR}/x11-toolkits/tk81
.elif ${WITH_TK_VER} == "8.2"
RUN_DEPENDS+=	wish8.2:${PORTSDIR}/x11-toolkits/tk82
.elif ${WITH_TK_VER} == "8.3"
RUN_DEPENDS+=	wish8.3:${PORTSDIR}/x11-toolkits/tk83
.else
RUN_DEPENDS+=	wish8.4:${PORTSDIR}/x11-toolkits/tk84
.endif # ${WITH_TK_VER} ==
.else
RUN_DEPENDS+=	wish8.4:${PORTSDIR}/x11-toolkits/tk84
.endif # defined WITH_TK_VER

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-HTk

WRKSRC=		${WRKDIR}/${PORTNAME}

ALL_TARGET=	boot packages

pre-everything::
.if !defined(WITH_TK_VER)
		@${ECHO_MSG}
		@${ECHO_MSG} "If you want to depend on a particular version of"
		@${ECHO_MSG} "Tk hit Ctrl-C now and use \"make WITH_TK_VER=val\""
		@${ECHO_MSG} "Values available: 8.0, 8.1, 8.2, 8.3 and 8.4"
		@${ECHO_MSG}
		@${ECHO_MSG} "Default is 8.4"
		@${ECHO_MSG}
.endif

do-install:
		@${MKDIR} ${PREFIX}/lib/uni
		@cd ${WRKSRC} && ${GMAKE} prepareexports
		@cd ${WRKSRC} && ${GMAKE} -s --no-print-directory exportnames | \
		   ${SED} 'y/ /\n/; /^$$/d ; s+${PORTNAME}/++g' | \
		   ${CPIO} -pdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/lib/uni

		@cd ${PREFIX}/lib/uni && ${FIND} . -type d -print0 | \
			${XARGS} -0 ${CHMOD} 755 # ugly, but necessary

		@${SED} 's|#PWD|${PREFIX}/lib/uni|g' < \
			${FILESDIR}/ghchtk > ${WRKSRC}/ghchtk
		@${SED} 's|#PWD|${PREFIX}/lib/uni|g' < \
			${FILESDIR}/ghcihtk > ${WRKSRC}/ghcihtk
		@${SED} 's|#PWD|${PREFIX}/lib/uni|g' < \
			${FILESDIR}/uni-package.conf > ${WRKSRC}/uni-package.conf

		@${INSTALL_DATA} ${WRKSRC}/uni-package.conf ${PREFIX}/lib/uni
		@${INSTALL_SCRIPT} ${WRKSRC}/ghchtk ${PREFIX}/bin
		@${INSTALL_SCRIPT} ${WRKSRC}/ghcihtk ${PREFIX}/bin

		@${ECHO_MSG}
		@${CAT} ${PKGMESSAGE} | ${SED} -e 's,%%PREFIX%%,${PREFIX},g'
		@${ECHO_MSG}

.include <bsd.port.post.mk>
