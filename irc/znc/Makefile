# Created by: elvstone@gmail.com
# $FreeBSD$

PORTNAME=	znc
PORTVERSION=	1.6.6
PORTREVISION=	1
CATEGORIES=	irc ipv6
MASTER_SITES=	https://znc.in/releases/ \
		https://znc.in/releases/archive/

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Advanced IRC bouncer

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lib cpe gmake iconv pathfix pkgconfig

USE_RC_SUBR=	znc

GNU_CONFIGURE=	yes
SUB_FILES=	pkg-message
MAKE_ENV=	V=1

PORTDOCS=	README.md

USERS=		znc
GROUPS=		znc

OPTIONS_DEFINE=	CHARSET CYRUS DEBUG DOCS IPV6 OPENSSL PERL PYTHON TCL
OPTIONS_DEFAULT=	CHARSET OPENSSL PERL
OPTIONS_SUB=	yes

CHARSET_DESC=	Character encoding support via ICU
CYRUS_DESC=	Cyrus SASL module
DEBUG_DESC=	Debugging support
PERL_DESC=	Perl scripting module
PYTHON_DESC=	Python scripting module
TCL_DESC=	Tcl scripting module

CHARSET_CONFIGURE_OFF=	--disable-charset
CHARSET_LIB_DEPENDS=	libicuuc.so:devel/icu
CYRUS_CONFIGURE_ON=	--enable-cyrus
CYRUS_LDFLAGS=	-L${LOCALBASE}/lib
CYRUS_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
DEBUG_CONFIGURE_ON=	--enable-debug
IPV6_CONFIGURE_OFF=	--disable-ipv6
OPENSSL_CONFIGURE_OFF=	--disable-openssl
OPENSSL_CONFIGURE_ON=	--with-openssl=${OPENSSLBASE}
OPENSSL_USES=	ssl
PERL_BUILD_DEPENDS=	swig30>=3.0.0:devel/swig30
PERL_CONFIGURE_ENABLE=	perl
PERL_CONFIGURE_ON=	--enable-swig
PERL_USE=	perl5=build,run
PERL_USES=	perl5
PYTHON_BUILD_DEPENDS=	swig30>=3.0.0:devel/swig30
PYTHON_CONFIGURE_ON=	--enable-python=python-${PYTHON_VER} --enable-swig
PYTHON_USE=	perl5=build
PYTHON_USES=	perl5 python:3.4+
TCL_CONFIGURE_ENABLE=	tcl
TCL_CONFIGURE_ON=	--with-tcl=${TCL_LIBDIR}
TCL_USES=	tcl

# Instead of using bundled swig generated files, delete them to force
# regeneration using swig 2.0.11+ (fixes port compilation using clang)
#
pre-configure-PERL-on:
	@${RM} ${WRKSRC}/modules/modperl/ZNC.cpp

pre-configure-PYTHON-on:
	@${RM} ${WRKSRC}/modules/modpython/_znc_core.cpp

post-patch:
	@${REINPLACE_CMD} -e \
		's#/usr/local#${LOCALBASE}#' ${WRKSRC}/configure

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
