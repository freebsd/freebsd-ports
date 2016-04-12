# Created by: tdb
# $FreeBSD$

PORTNAME=	atheme-services
PORTVERSION=	7.2.6
CATEGORIES=	irc
MASTER_SITES=	http://atheme.github.io/downloads/

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	Set of services for IRC networks

USES=		tar:bzip2 pkgconfig pathfix gmake
PATHFIX_MAKEFILEIN=	Makefile
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-fhs-paths \
		--sysconfdir=${PREFIX}/etc/atheme \
		--localstatedir=/var \
		--disable-gtk-doc \
		--enable-large-net
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USERS=		ircservices
GROUPS=		ircservices

LIB_DEPENDS+=	libmowgli-2.so:devel/libmowgli2

USE_RC_SUBR=	atheme-services

OPTIONS_DEFINE=	CONTRIB CRACKLIB DOCS LDAP NLS PCRE PERL
OPTIONS_DEFAULT=	CRACKLIB DOCS LDAP NLS PCRE PERL

CONTRIB_DESC=	Enable contrib modules
CRACKLIB_DESC=	Use cracklib for checking password strength

OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCONTRIB}
CONFIGURE_ARGS+=	--enable-contrib
.else
CONFIGURE_ARGS+=	--disable-contrib
.endif

.if ${PORT_OPTIONS:MCRACKLIB}
LIB_DEPENDS+=	libcrack.so:security/cracklib
CONFIGURE_ARGS+=	--with-cracklib
.else
CONFIGURE_ARGS+=	--without-cracklib
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=	--with-ldap
.else
CONFIGURE_ARGS+=	--without-ldap
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS+=	--enable-nls
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

.if ${PORT_OPTIONS:MPCRE}
LIB_DEPENDS+=	libpcre.so:devel/pcre
CONFIGURE_ARGS+=	--with-pcre
.else
CONFIGURE_ARGS+=	--without-pcre
.endif

.if ${PORT_OPTIONS:MPERL}
USES+=		perl5
CONFIGURE_ARGS+=	--with-perl
.else
CONFIGURE_ARGS+=	--without-perl
.endif

post-install:
# Treat atheme.motd like atheme.conf. So don't install it directly,
# but instead copy it from atheme.motd.example if it doesn't exist,
# and only remove it at deinstall time if it's unchanged.
	@${RM} ${STAGEDIR}${PREFIX}/etc/atheme/atheme.motd
# These are just to satisfy check-orphans
	@${RMDIR} ${STAGEDIR}/var/lib/atheme
	@${RMDIR} ${STAGEDIR}/var/lib
	@${RMDIR} ${STAGEDIR}/var/log/atheme
	@${RMDIR} ${STAGEDIR}/var/run/atheme
.if !${PORT_OPTIONS:MDOCS}
	@${RM} -Rf ${STAGEDIR}${PREFIX}/share/doc/atheme
.endif

.include <bsd.port.mk>
