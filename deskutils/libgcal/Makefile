# New ports collection makefile for:	libgcal
# Date created:		2009-08-16
# Whom:			Troels Kofoed Jacobsen <tkjacobsen@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libgcal
PORTVERSION=	0.9.5
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	tkjacobsen@gmail.com
COMMENT=	Library allowing communication with google calendar and contacts

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		iconv:${PORTSDIR}/converters/libiconv \
		xml2:${PORTSDIR}/textproc/libxml2

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYING

USE_BZIP2=	yes
USE_CMAKE=	yes
CMAKE_ARGS=	-DCMAKE_INSTALL_PREFIX="${PREFIX}" \
		-DLIB_INSTALL_DIR="${LOCALBASE}/lib" \
		-DENABLE_TESTS=OFF
USE_LDCONFIG=	yes
USE_GCC=	4.2+

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" && (${OSVERSION} >= 700000 && ${OSVERSION} < 800000)
BROKEN=		does not link
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,(libdir)/pkgconfig,(prefix)/libdata/pkgconfig,' \
		${WRKSRC}/Makefile.am

.include <bsd.port.post.mk>
