# New ports collection makefile for:   znc
# Date created:        6 March 2008
# Whom:                elvstone@gmail.com
#
# $FreeBSD$
#

PORTNAME=	znc
PORTVERSION=	0.090
CATEGORIES=	irc ipv6
MASTER_SITES=	SF

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	An advanced IRC bouncer

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig
WANT_PERL=	yes

OPTIONS=	DEBUG		"Enable debugging" off \
		IPV6		"Enable IPv6 support" off \
		CARES		"Use c-ares resolver library" off \
		OPENSSL		"Enable OpenSSL support" on \
		EXTRA		"Build extra modules" off \
		PERL		"Enable Perl module support" on \
		TCL		"Enable TCL module support" off \
		TCLALLOWALL	"Allow non-admin users to load TCL module" off \
		SASL		"Enable SASL module support" off

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if defined(WITH_CARES)
LIB_DEPENDS+=		cares.2:${PORTSDIR}/dns/c-ares
.else
CONFIGURE_ARGS+=	--disable-c-ares
.endif

.if defined(WITH_OPENSSL)
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}
PLIST_SUB+=		OPENSSL=""
.else
CONFIGURE_ARGS+=	--disable-openssl
PLIST_SUB+=		OPENSSL="@comment "
.endif

.if defined(WITH_PERL)
USE_PERL5=		yes
PLIST_SUB+=		PERL=""
.else
CONFIGURE_ARGS+=	--disable-perl
PLIST_SUB+=		PERL="@comment "
.endif

.if defined(WITH_TCL)
USE_TCL=		84+
.include "${PORTSDIR}/Mk/bsd.tcl.mk"
CONFIGURE_ARGS+=	--enable-tcl --with-tcl=${TCL_LIBDIR}
PLIST_SUB+=		TCL=""
.else
CONFIGURE_ARGS+=	--without-tcl
PLIST_SUB+=		TCL="@comment "
.endif

.if defined(WITH_TCLALLOWALL)
.if defined(WITHOUT_TCL)
IGNORE=			tcl allow all support requires TCL. Please re-rerun 'make config' and enable TCL
.endif
CXXFLAGS+=		-DMOD_MODTCL_ALLOW_EVERYONE
.endif

.if defined(WITH_SASL)
LIB_DEPENDS+=		sasl2.2:${PORTSDIR}/security/cyrus-sasl2
CONFIGURE_ARGS+=	--enable-sasl
CONFIGURE_ENV+=		LDFLAGS="-L${LOCALBASE}/lib"
PLIST_SUB+=		SASL=""
.else
PLIST_SUB+=		SASL="@comment "
.endif

.if defined(WITH_EXTRA)
USE_ICONV=		yes
CONFIGURE_ARGS+=	--enable-extra
PLIST_SUB+=		EXTRA=""
.else
PLIST_SUB+=		EXTRA="@comment "
.endif

MANCOMPRESSED=	yes
MAN1=		znc.1 znc-buildmod.1 znc-config.1

.include <bsd.port.post.mk>
