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
MASTER_SITE_SUBDIR=	libs
DISTNAME=	${PORTNAME}-${PORTVERSION:R}-src
PATCH_SITES=	http://www.nbpfaus.net/~pfau/ftplib/
PATCHFILES=	${PORTNAME}-${PORTVERSION:R}-${PORTVERSION:E}.patch

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A set of routines that implement the FTP protocol

USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}
PATCH_DIST_STRIP=	-p3
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

PLIST_FILES=	lib/libftp.a lib/libftp.so lib/libftp.so.3 \
		include/ftplib.h

post-patch:
	@${REINPLACE_CMD} -e "s|^CFLAGS =|CFLAGS+=|" \
		-e "s|^LDFALGS =|LDFLAGS+=|" ${WRKSRC}/linux/Makefile

do-build:
	@(cd ${WRKSRC}/linux && ${GMAKE})

do-install:
	@(cd ${WRKSRC}/linux ; \
	  ${INSTALL_DATA} libftp.a libftp.so.3 ${PREFIX}/lib ; \
	  ${LN} -fs ${PREFIX}/lib/libftp.so.3 ${PREFIX}/lib/libftp.so ; \
	  ${INSTALL_DATA} ftplib.h ${PREFIX}/include \
	)

.include <bsd.port.mk>
