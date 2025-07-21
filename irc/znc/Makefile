PORTNAME=	znc
DISTVERSION=	1.10.1
CATEGORIES=	irc
MASTER_SITES=	https://znc.in/releases/ \
		https://znc.in/releases/archive/

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Advanced IRC bouncer
WWW=		https://wiki.znc.in/ZNC

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	swig>=4.0.1:devel/swig
LIB_DEPENDS=	libcctz.so:devel/cctz \
		libicuuc.so:devel/icu

USES=		compiler:c++17-lang cpe cmake:run iconv pathfix \
		perl5 pkgconfig:both python ssl
USE_PERL5=	build

EXTRACT_AFTER_ARGS=	--exclude ${PORTNAME}-${DISTVERSION}/third_party/cctz \
			--exclude ${PORTNAME}-${DISTVERSION}/third_party/googletest \
			--exclude ${PORTNAME}-${DISTVERSION}/third_party/gtest-parallel \
			--no-same-owner --no-same-permissions

USE_RC_SUBR=	znc

USERS=		znc
GROUPS=		znc

PORTDOCS=	README.md
SUB_FILES=	pkg-message

CMAKE_ON=	WANT_ICU \
		WANT_IPV6 \
		WANT_OPENSSL \
		WANT_PYTHON \
		WANT_SWIG
CMAKE_OFF=	WANT_ARGON
CMAKE_ARGS=	-DOPENSSL_ROOT_DIR=${OPENSSLBASE} \
		-DWANT_PYTHON_VERSION:STRING=python-${PYTHON_VER}

OPTIONS_DEFINE=		CYRUS DOCS NLS PERL TCL
OPTIONS_DEFAULT=	PERL
OPTIONS_SUB=		yes

CYRUS_DESC=		Cyrus SASL module
PERL_DESC=		Perl scripting module
PYTHON_DESC=		Python scripting module
TCL_DESC=		Tcl scripting module

CYRUS_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
CYRUS_CMAKE_BOOL=	WANT_CYRUS

NLS_LIB_DEPENDS=	libboost_locale.so:devel/boost-libs
NLS_USES=		gettext
NLS_CMAKE_BOOL=		WANT_I18N

PERL_USE=		perl5=run
PERL_CMAKE_BOOL=	WANT_PERL WANT_SWIG

TCL_USES=		tcl
TCL_CMAKE_BOOL=		WANT_TCL

post-patch:
	@${REINPLACE_CMD} -e 's|python3|python${PYTHON_VER}|g' \
		${WRKSRC}/znc-buildmod.cmake.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install-NLS-off:
	@${RM} -r ${STAGEDIR}${DATADIR}/translations

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
