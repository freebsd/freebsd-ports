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

USE_GMAKE=	YES
MAKEFILE=	GNUmakefile
ALL_TARGET=	export

do-install:
	(cd ${WRKSRC}/../bin/x86_freebsd_3.2; find . |cpio -pdum ${PREFIX}/bin)
	(cd ${WRKSRC}/../lib/x86_freebsd_3.2; find . |cpio -pdum ${PREFIX}/lib)
	${INSTALL_MAN} ${WRKSRC}/../man/man1/* ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/include/omniORB2
	${MKDIR} ${PREFIX}/include/omnithread
	${INSTALL_DATA} ${WRKSRC}/../include/omnithread.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/../include/omnithread/* ${PREFIX}/include/omnithread
	${INSTALL_DATA} ${WRKSRC}/../include/omniORB2/* ${PREFIX}/include/omniORB2
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/omniORB
	${INSTALL_DATA} ${WRKSRC}/../README.unix ${PREFIX}/share/doc/omniORB
	${INSTALL_DATA} ${WRKSRC}/../README.FreeBSD ${PREFIX}/share/doc/omniORB
	${INSTALL_DATA} ${WRKSRC}/../ReleaseNote_omniORB_280 ${PREFIX}/share/doc/omniORB
	(cd ${WRKSRC}/../doc; find . |cpio -pdum ${PREFIX}/share/doc/omniORB)
.endif
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>

