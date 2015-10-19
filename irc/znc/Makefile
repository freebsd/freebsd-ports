# Created by: elvstone@gmail.com
# $FreeBSD$

PORTNAME=	znc
PORTVERSION=	1.6.1
CATEGORIES=	irc ipv6
MASTER_SITES=	http://znc.in/releases/ \
		http://znc.in/releases/archive/

MAINTAINER=	jase@FreeBSD.org
COMMENT=	Advanced IRC bouncer

LICENSE=	APACHE20

GNU_CONFIGURE=	yes
USE_RC_SUBR=	znc
USES=		compiler:c++11-lib cpe gmake iconv pkgconfig

NO_OPTIONS_SORT=	yes

OPTIONS_DEFINE=	DEBUG IPV6 OPENSSL CYRUS PERL PYTHON TCL CHARSET DOCS
OPTIONS_DEFAULT=	OPENSSL PERL
OPTIONS_SUB=	yes

CYRUS_DESC=	Cyrus SASL module
DEBUG_DESC=	Debugging support
PERL_DESC=	Perl scripting module
PYTHON_DESC=	Python scripting module
CHARSET_DESC=	Character encoding support via ICU
TCL_DESC=	Tcl scripting module

CYRUS_CONFIGURE_ON=	--enable-cyrus
CYRUS_LDFLAGS=	-L${LOCALBASE}/lib
CYRUS_LIB_DEPENDS=	libsasl2.so:${PORTSDIR}/security/cyrus-sasl2
DEBUG_CONFIGURE_ON=	--enable-debug
IPV6_CONFIGURE_OFF=	--disable-ipv6
PERL_BUILD_DEPENDS=	swig30>=3.0.0:${PORTSDIR}/devel/swig30
PERL_CONFIGURE_ENABLE=	perl
PERL_CONFIGURE_ON=	--enable-swig
PERL_USES=	perl5
PYTHON_BUILD_DEPENDS=	swig30>=3.0.0:${PORTSDIR}/devel/swig30
PYTHON_CONFIGURE_ON=	--enable-python=python-${PYTHON_VER} --enable-swig
PYTHON_USES=	perl5 python:3
OPENSSL_CONFIGURE_OFF=	--disable-openssl
CHARSET_CONFIGURE_OFF=	--disable-charset
CHARSET_LIB_DEPENDS=	libicuuc.so.55:${PORTSDIR}/devel/icu \
			libicudata.so.55:${PORTSDIR}/devel/icu
TCL_CONFIGURE_ENABLE=	tcl

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENSSL}
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}
.endif

.if ${PORT_OPTIONS:MPERL}
USE_PERL5+=		run build
.endif

.if ${PORT_OPTIONS:MTCL}
USES+=			tcl
CONFIGURE_ARGS+=	--with-tcl=${TCL_LIBDIR}
.endif

.if ${PORT_OPTIONS:MPYTHON}
USE_PERL5+=		build
.endif

PORTDOCS=		README.md

pre-configure:
# No need to cast to char** in AM_ICONV, fixes charset/iconv detection
# and by extension, successfully builds charset module
	@${REINPLACE_CMD} -e \
		's#(char \*\*)##g' \
		${WRKSRC}/configure
# Instead of using bundled swig generated files, delete them to force
# regeneration using swig 2.0.11+ (fixes port compilation using clang)
.if ${PORT_OPTIONS:MPERL}
	@${RM} ${WRKSRC}/modules/modperl/ZNC.cpp
.endif
.if ${PORT_OPTIONS:MPYTHON}
	@${RM} ${WRKSRC}/modules/modpython/_znc_core.cpp
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's#$$(libdir)/pkgconfig#${PREFIX}/libdata/pkgconfig#' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's#/usr/local#${LOCALBASE}#' ${WRKSRC}/configure

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}"
.endif

.include <bsd.port.mk>
