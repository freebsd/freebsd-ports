# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wget
DISTVERSION=	1.14
PORTREVISION=	2
CATEGORIES=	ftp www ipv6
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	wget

MAINTAINER=	vd@FreeBSD.org
COMMENT=	Retrieve files from the Net via HTTP(S) and FTP

USES=		charsetfix
USE_XZ=		yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

OPTIONS_RADIO=	SSL
OPTIONS_RADIO_SSL=GNUTLS OPENSSL
OPTIONS_DEFINE=	IPV6 NLS IDN PCRE
OPTIONS_DEFAULT=OPENSSL IDN

PCRE_DESC=	Support Perl regular expressions in addition to POSIX

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENSSL}
USE_OPENSSL=	yes
CONFIGURE_ARGS+=--with-ssl=openssl
CPPFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
.elif ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	gnutls:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=--with-ssl=gnutls
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=--without-ssl
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=--enable-ipv6
.else
CONFIGURE_ARGS+=--disable-ipv6
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS+=--enable-nls
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MIDN}
LIB_DEPENDS+=	idn:${PORTSDIR}/dns/libidn
CONFIGURE_ARGS+=--enable-iri --with-libidn=${LOCALBASE}
.else
CONFIGURE_ARGS+=--disable-iri
.endif

.if ${PORT_OPTIONS:MPCRE}
# Wget will pick pcre automatically and link with it if it is present.
LIB_DEPENDS+=	pcre:${PORTSDIR}/devel/pcre
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.else
CONFIGURE_ENV+=	ac_cv_header_pcre_h=no
.endif

MAN1=		wget.1
INFO=		wget

# eliminate gmakism
post-patch:
	${REINPLACE_CMD} -e 's,$$<,$$(srcdir)/wget.texi,' \
	    		 -e 's,WGETRC = $$(sysconfdir)/wgetrc,&.sample,' \
		${WRKSRC}/doc/Makefile.in
	${REINPLACE_CMD} -e 's,/usr/local/etc/wgetrc,${PREFIX}/etc/wgetrc,' \
			 -e 's,@file{},@file{${PREFIX}},' \
		${WRKSRC}/doc/sample.wgetrc* ${WRKSRC}/doc/wget.texi

.include <bsd.port.mk>
