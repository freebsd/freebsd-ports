# New ports collection makefile for:	omniORB
# Date created:		14 May 1997
# Whom:			ejc@bazzle.com
# Version required:	2.2.0
#
# $FreeBSD$
#

DISTNAME=	omniORB_2.2.0
PKGNAME=	omniORB-2.2.0	
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.orl.co.uk/pub/omniORB/

MAINTAINER=	ejc@bazzle.com

MAN1=		omniidl2.1 nameclt.1 omniNames.1 catior.1 genior.1

BROKEN_ELF=	yes

pre-patch:
	${TOUCH} ${WRKSRC}/mk/freebsd_3.0.mk
	${LN} -s ${WRKSRC}/mk/freebsd_3.0.mk ${WRKDIR}/${DISTNAME}/mk/config.mk
	${MKDIR} ${WRKSRC}/src/tool/omniidl2/omniidl2
	${TOUCH} ${WRKSRC}/src/tool/omniidl2/omniidl2/Makefile
	${TOUCH} ${WRKSRC}/Makefile

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/man1/* ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/include/omniORB2
	${MKDIR} ${PREFIX}/include/omnithread
	${INSTALL_DATA} ${WRKSRC}/include/omnithread.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/omniORB2/* ${PREFIX}/include/omniORB2
	${INSTALL_DATA} ${WRKSRC}/include/omnithread/* ${PREFIX}/include/omnithread
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/omniORB
	${INSTALL_DATA} ${WRKSRC}/README.unix ${PREFIX}/share/doc/omniORB
	(cd ${WRKSRC}/doc; find . |cpio -pdumv ${PREFIX}/share/doc/omniORB)
.endif
	${LDCONFIG} -m $(PREFIX)/lib

.include <bsd.port.mk>
