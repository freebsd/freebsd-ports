# ex:ts=8
# Ports collection makefile for:	ftplib
# Date created:			Feb 11, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ftplib
PORTVERSION=	3.1.1
CATEGORIES=	ftp
MASTER_SITES=	http://www.nbpfaus.net/~pfau/ftplib/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}-src
PATCH_SITES=	http://www.nbpfaus.net/~pfau/ftplib/
PATCHFILES=	${PORTNAME}-${PORTVERSION:R}-${PORTVERSION:E}.patch

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A set of routines that implement the FTP protocol

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}/linux
PATCH_DIST_STRIP=	-p3
USE_GMAKE=	yes
MAKE_ARGS+=	DEBUG="${CFLAGS}" LDFLAGS="${LDFLAGS} -L."
INSTALLS_SHLIB=	yes

PLIST_FILES=	lib/libftp.so lib/libftp.so.3 \
		include/ftplib.h bin/qftp bin/ftpdir bin/ftpget \
		bin/ftplist bin/ftprm bin/ftpsend

do-install:
	@(cd ${WRKSRC} ; \
		${INSTALL_PROGRAM} qftp ${PREFIX}/bin ; \
		${INSTALL_DATA} libftp.so.3 ${PREFIX}/lib ; \
		${LN} -fs ${PREFIX}/lib/libftp.so.3 ${PREFIX}/lib/libftp.so ; \
		${INSTALL_DATA} ftplib.h ${PREFIX}/include ; \
		for i in ftpdir ftpget ftplist ftprm ftpsend; do \
  		  ${LN} -s qftp ${PREFIX}/bin/$$i ; done \
	)

.include <bsd.port.mk>
