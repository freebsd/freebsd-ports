# $FreeBSD$

PORTNAME=	libosmocore
PORTVERSION=	1.2.0
CATEGORIES=	devel
MASTER_SITES=	http://git.osmocom.org/libosmocore/snapshot/ \
		http://chaosophia.net/downloads/osmocom/${PORTNAME}/

MAINTAINER=	koue@chaosophia.net
COMMENT=	Common library for all Osmocom projects

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libpcsclite.so:devel/pcsc-lite \
		libtalloc.so:devel/talloc

USES=		alias autoreconf gmake libtool pathfix pkgconfig python:2.7 \
		shebangfix

GNU_CONFIGURE=	yes
LDFLAGS+=	-lexecinfo
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
PORTDOCS=	*
SHEBANG_FILES=	utils/conv_codes_gsm.py utils/conv_gen.py
python_OLD_CMD=	/usr/bin/python2

OPTIONS_DEFINE=	DOCS DOXYGEN

DOXYGEN_IMPLIES=		DOCS
DOXYGEN_BUILD_DEPENDS=		dot:graphics/graphviz \
				doxygen:devel/doxygen
DOXYGEN_CONFIGURE_ENV_OFF=	ac_cv_path_DOXYGEN=false

post-patch:
	${ECHO_CMD} ${PORTVERSION} > ${WRKSRC}/.tarball-version
	@${REINPLACE_CMD} -e '/#pragma GCC diagnostic/d' \
		${WRKSRC}/src/application.c \
		${WRKSRC}/src/gb/gprs_bssgp.c \
		${WRKSRC}/src/gb/gprs_bssgp_bss.c
	@${REINPLACE_CMD} -e 's/python2/${PYTHON_VERSION}/' \
		-e 's,(AM_V_GEN)python ,(AM_V_GEN)${PYTHON_VERSION} ,' \
		${WRKSRC}/include/Makefile.am \
		${WRKSRC}/src/gsm/Makefile.am \
		${WRKSRC}/tests/Makefile.am

.include <bsd.port.mk>
