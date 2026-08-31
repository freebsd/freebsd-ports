PORTNAME=	cfitsio
PORTVERSION=	4.7.0
CATEGORIES=	astro
MASTER_SITES=	https://heasarc.gsfc.nasa.gov/FTP/software/fitsio/c/ \
		https://heasarc.gsfc.nasa.gov/FTP/software/fitsio/c/oldvers/ \
		https://heasarc.gsfc.nasa.gov/FTP/software/fitsio/c/docs/:docs
DISTFILES=	cfitsio-${PORTVERSION}${EXTRACT_SUFX}
DIST_SUBDIR=	cfitsio/${PORTVERSION}
EXTRACT_ONLY=	cfitsio-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for reading and writing files in FITS data format
WWW=		https://heasarc.gsfc.nasa.gov/fitsio/ \
		https://github.com/HEASARC/cfitsio

LICENSE=	CFITSIO
LICENSE_NAME=	CFITSIO License
LICENSE_FILE=	${WRKSRC}/licenses/License.txt
LICENSE_PERMS=	auto-accept dist-mirror dist-sell pkg-mirror pkg-sell

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		cpe libtool localbase pkgconfig

CONFIGURE_ARGS=	--enable-reentrant --with-bzip2=/usr
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

CPE_VENDOR=	nasa

OPTIONS_DEFINE=	DOCS

DOCS_DISTFILES=	cfitsio.pdf:docs \
		fitsio.pdf:docs \
		fpackguide.pdf:docs \
		quick.pdf:docs

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/*.pdf ${STAGEDIR}${DOCSDIR}/

# maintainer section:

.if defined(MAINTAINER_MODE)
DISTFILES+=	cfitsio.pdf:docs \
		fitsio.pdf:docs \
		fpackguide.pdf:docs \
		quick.pdf:docs
.endif

.include <bsd.port.mk>
