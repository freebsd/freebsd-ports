# Created by: elvstone@gmail.com
# $FreeBSD$

PORTNAME=	znc
PORTVERSION=	1.7.5
PORTREVISION=	3
CATEGORIES=	irc
MASTER_SITES=	https://znc.in/releases/ \
		https://znc.in/releases/archive/

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Advanced IRC bouncer

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lib cpe cmake:run iconv pathfix pkgconfig python:3.5+

USE_RC_SUBR=	znc

SUB_FILES=	pkg-message

PORTDOCS=	README.md

USERS=		znc
GROUPS=		znc

OPTIONS_DEFINE=	CHARSET CYRUS DEBUG DOCS IPV6 NLS OPENSSL PERL PYTHON TCL
OPTIONS_DEFAULT=	CHARSET OPENSSL PERL PYTHON
OPTIONS_SUB=	yes

CHARSET_DESC=	Character encoding support via ICU
CYRUS_DESC=	Cyrus SASL module
DEBUG_DESC=	Debugging support
PERL_DESC=	Perl scripting module
PYTHON_DESC=	Python scripting module
TCL_DESC=	Tcl scripting module

CHARSET_CMAKE_BOOL=	WANT_ICU
CHARSET_LIB_DEPENDS=	libicuuc.so:devel/icu
CYRUS_CMAKE_BOOL=	WANT_CYRUS
CYRUS_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
DEBUG_VARS=		CMAKE_BUILD_TYPE=Debug
IPV6_CMAKE_BOOL=	WANT_IPV6
NLS_CMAKE_BOOL=		WANT_I18N
NLS_LIB_DEPENDS=	libboost_locale.so:devel/boost-libs
NLS_USES=		gettext
OPENSSL_CMAKE_BOOL=	WANT_OPENSSL
OPENSSL_CMAKE_ON=	-DOPENSSL_ROOT_DIR=${OPENSSLBASE}
OPENSSL_USES=	ssl
PERL_BUILD_DEPENDS=	swig30>=3.0.0:devel/swig30
PERL_CMAKE_BOOL=	WANT_PERL WANT_SWIG
PERL_USE=	perl5=build,run
PERL_USES=	perl5
PYTHON_CMAKE_BOOL=	WANT_PYTHON WANT_SWIG
PYTHON_CMAKE_ON=	-DWANT_PYTHON_VERSION:STRING=python-${PYTHON_VER}
PYTHON_BUILD_DEPENDS=	swig30>=3.0.0:devel/swig30
PYTHON_IMPLIES=	CHARSET
PYTHON_USE=	perl5=build
PYTHON_USES=	perl5
TCL_CMAKE_BOOL=	WANT_TCL
TCL_USES=	tcl

post-patch:
	@${REINPLACE_CMD} -e 's|python3|python${PYTHON_VER}|g' \
		${WRKSRC}/znc-buildmod.cmake.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

post-install-NLS-off:
	@${RM} -r ${STAGEDIR}${DATADIR}/translations

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
