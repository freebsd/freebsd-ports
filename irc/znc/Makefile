# Created by: elvstone@gmail.com
# $FreeBSD$

PORTNAME=	znc
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	irc ipv6
MASTER_SITES=	http://znc.in/releases/

MAINTAINER=	jase@FreeBSD.org
COMMENT=	An advanced IRC bouncer

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USE_RC_SUBR=	znc
USES=		pkgconfig iconv gmake

NO_OPTIONS_SORT=	yes

OPTIONS_DEFINE=	DEBUG IPV6 OPENSSL CYRUS PERL PYTHON TCL
OPTIONS_DEFAULT=	OPENSSL PERL

DEBUG_DESC=	Debugging support
PERL_DESC=	Perl scripting module
PYTHON_DESC=	Python scripting module
TCL_DESC=	Tcl scripting module
CYRUS_DESC=	Cyrus SASL module

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug
.endif

.if empty(PORT_OPTIONS:MIPV6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if ${PORT_OPTIONS:MOPENSSL}
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}
PLIST_SUB+=		OPENSSL=""
.else
CONFIGURE_ARGS+=	--disable-openssl
PLIST_SUB+=		OPENSSL="@comment "
.endif

.if ${PORT_OPTIONS:MPERL}
USES+=			perl5
USE_PERL5+=		run build
CONFIGURE_ARGS+=	--enable-perl
PLIST_SUB+=		PERL=""
BUILD_DEPENDS+=		swig>=2.0.4:${PORTSDIR}/devel/swig20
.else
PLIST_SUB+=		PERL="@comment "
.endif

.if ${PORT_OPTIONS:MTCL}
USE_TCL=		84+
.include "${PORTSDIR}/Mk/bsd.tcl.mk"
CONFIGURE_ARGS+=	--enable-tcl --with-tcl=${TCL_LIBDIR}
PLIST_SUB+=		TCL=""
.else
CONFIGURE_ARGS+=	--without-tcl
PLIST_SUB+=		TCL="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	3.1-3.2
USES+=		perl5
USE_PERL5+=	build
PLIST_SUB+=	PYTHON=""
CONFIGURE_ARGS+=	--enable-python=python-${PYTHON_VER}
BUILD_DEPENDS+=		swig>=2.0.4:${PORTSDIR}/devel/swig20
.else
PLIST_SUB+=	PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MCYRUS}
LIB_DEPENDS+=		sasl2:${PORTSDIR}/security/cyrus-sasl2
CONFIGURE_ARGS+=	--enable-cyrus
LDFLAGS+=		-L${LOCALBASE}/lib
PLIST_SUB+=		CYRUS=""
.else
PLIST_SUB+=		CYRUS="@comment "
.endif

MANCOMPRESSED=	yes
MAN1=		znc.1 znc-buildmod.1

PORTDOCS=	README.md

post-patch:
	@${REINPLACE_CMD} -e \
		's#$$(libdir)/pkgconfig#${PREFIX}/libdata/pkgconfig#' \
		${WRKSRC}/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}"
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
