# New ports collection makefile for:	omniORB
# Date created:		14 May 1997
# Whom:			ejc@bazzle.com
# Version required:	2.8.0
#
# $FreeBSD$
#

DISTNAME=	omniORB_280
PKGNAME=	omniORB-2.8.0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.orl.co.uk/pub/omniORB/

MAINTAINER=	ejc@bazzle.com

MAN1=		catior.1 genior.1 nameclt.1 obuildtree.1 ols.1 omake.1 \
		omniNames.1 omniidl2.1 opriv.1 oshadow.1

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_NEWGCC=	YES
USE_GMAKE=	YES
MAKEFILE=	GNUmakefile
ALL_TARGET=	export
MAKE_ENV=	CDEBUGFLAGS="${CFLAGS}" CXXDEBUGFLAGS="${CXXFLAGS}" \
		MKDIRHIER="${WRKSRC}/../bin/scripts/omkdirhier"
ONLY_FOR_ARCHS=	i386
CONFIG_TARGET=	x86_freebsd_3.2

post-patch:
	@${SETENV} LANG=C ${PERL} -pi -e 's/__PLATFORM__/${CONFIG_TARGET}/;' \
		${WRKSRC}/../config/config.mk
	@${SETENV} LANG=C ${PERL} -pi -e 's/^(MKDIRHIER[^=]*)=/$$1?=/;' \
		${WRKSRC}/../mk/unix.mk

do-install:
	cd ${WRKSRC}/../bin && \
		${INSTALL_PROGRAM} ${CONFIG_TARGET}/* ${PREFIX}/bin
	cd ${WRKSRC}/../lib/${CONFIG_TARGET} && \
		find . |cpio -pdum -R ${BINOWN}:${BINGRP} ${PREFIX}/lib
.for m in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/../man/man1/${m} ${PREFIX}/man/man1
.endfor
	${MKDIR} ${PREFIX}/include/omniORB2
	${MKDIR} ${PREFIX}/include/omnithread
	${INSTALL_DATA} ${WRKSRC}/../include/omnithread.h ${PREFIX}/include
	cd ${WRKSRC}/../include && \
		${INSTALL_DATA} omnithread/* ${PREFIX}/include/omnithread; \
		${INSTALL_DATA} omniORB2/* ${PREFIX}/include/omniORB2
	@ cd ${.CURDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/omniORB
	${INSTALL_DATA} ${WRKSRC}/../README.unix ${PREFIX}/share/doc/omniORB
	${INSTALL_DATA} ${WRKSRC}/../README.FreeBSD ${PREFIX}/share/doc/omniORB
	${INSTALL_DATA} ${WRKSRC}/../ReleaseNote_omniORB_280 ${PREFIX}/share/doc/omniORB
	cd ${WRKSRC}/../doc && \
		find . |cpio -pdum -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/omniORB
.endif
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
