PORTNAME=	liblognorm
DISTVERSION=	2.0.7
CATEGORIES=	devel net security
MASTER_SITES=	http://www.liblognorm.com/download/files/download/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Log normalizer
WWW=		https://www.liblognorm.com/

LICENSE=	LGPL21+ APACHE20
LICENSE_COMB=	multi
LICENSE_FILE_APACHE20=	${WRKSRC}/COPYING.ASL20
LICENSE_FILE_LGPL21+ =	${WRKSRC}/COPYING

LIB_DEPENDS=	libfastjson.so:devel/libfastjson \
		libestr.so:devel/libestr

USES=		libtool pathfix pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

SUB_FILES=	pkg-message

OPTIONS_DEFINE=		DOCS

DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx@${PY_FLAVOR}
DOCS_USES=		python
DOCS_CONFIGURE_OFF=	--disable-docs

# Try to fix parallel (-jX) builds
post-patch:
	@${REINPLACE_CMD} -e \
		'/^lognormalizer_DEPENDENCIES/s,=,= $$(lib_LTLIBRARIES),' \
			${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
