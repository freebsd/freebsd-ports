PORTNAME=	cfitsio
PORTVERSION=	4.5.0
CATEGORIES=	astro
MASTER_SITES=	https://heasarc.gsfc.nasa.gov/FTP/software/fitsio/c/ \
		https://heasarc.gsfc.nasa.gov/FTP/software/fitsio/c/oldvers/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for reading and writing files in FITS data format
WWW=		https://heasarc.gsfc.nasa.gov/fitsio/ \
		https://github.com/HEASARC/cfitsio

LICENSE=	CFITSIO
LICENSE_NAME=	CFITSIO License
LICENSE_FILE=	${WRKSRC}/licenses/License.txt
LICENSE_PERMS=	auto-accept dist-mirror dist-sell pkg-mirror pkg-sell

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		cpe libtool localbase pathfix pkgconfig

CONFIGURE_ARGS=	--enable-reentrant --with-bzip2=/usr
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

CPE_VENDOR=	nasa

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/docs/*.pdf ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
