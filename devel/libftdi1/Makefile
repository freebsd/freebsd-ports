PORTNAME=	libftdi1
PORTVERSION=	1.5
PORTREVISION=	9
CATEGORIES=	devel
MASTER_SITES=	https://www.intra2net.com/en/developer/libftdi/download/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Library (using libusb) to talk to FTDI chips
WWW=		https://www.intra2net.com/en/developer/libftdi/

LICENSE=		GPLv2 LGPL21
LICENSE_COMB=		multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING.GPL
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libconfuse.so:devel/libconfuse

USES=		cmake:insource compiler:c++11-lang gettext-runtime pkgconfig tar:bzip2
USE_LDCONFIG=	yes

PORTDOCS=	ChangeLog README
PORTEXAMPLES=	baud_test bitbang bitbang2 bitbang_cbus bitbang_ft2232 \
		eeprom find_all serial_test simple stream_test

OPTIONS_DEFINE=	PYTHON BOOST DOCS EXAMPLES
OPTIONS_DEFAULT=PYTHON BOOST
OPTIONS_SUB=	yes

BOOST_DESC=	Build with boost
PYTHON_DESC=	Build Python bindings

EXAMPLES_CMAKE_BOOL=	EXAMPLES

PYTHON_USES=		python
PYTHON_CMAKE_BOOL=	PYTHON_BINDINGS
PYTHON_BUILD_DEPENDS=	swig:devel/swig

BOOST_CMAKE_BOOL=	FTDIPP
BOOST_BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:devel/boost-libs
BOOST_PORTEXAMPLES=	find_all_pp

.include <bsd.port.options.mk>

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for fname in ${PORTEXAMPLES}
	${INSTALL_PROGRAM} ${WRKSRC}/examples/${fname} ${STAGEDIR}${EXAMPLESDIR}/
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
