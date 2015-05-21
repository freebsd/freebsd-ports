# Created by: Troels Kofoed Jacobsen <tkjacobsen@gmail.com>
# $FreeBSD$

PORTNAME=	libgcal
PORTVERSION=	0.9.6
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library allowing communication with Google calendar and contacts

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libxml2.so:${PORTSDIR}/textproc/libxml2

USES=		cmake iconv tar:bzip2
CMAKE_ARGS=	-DLIB_INSTALL_DIR="${LOCALBASE}/lib" \
		-DENABLE_TESTS=OFF
USE_LDCONFIG=	yes

.include <bsd.port.mk>
