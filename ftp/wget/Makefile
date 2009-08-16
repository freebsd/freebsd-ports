# Ports collection makefile for:  wget
# Date created:			  31 December 1996
# Whom:				  Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wget
DISTVERSION=	1.11.4
PORTREVISION=	1
CATEGORIES=	ftp www ipv6
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	wget

MAINTAINER=	vd@FreeBSD.org
COMMENT=	Retrieve files from the Net via HTTP(S) and FTP

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"
MAKE_JOBS_SAFE=	yes

OPTIONS=	GNUTLS "Support for SSL via GnuTLS" Off \
		IPV6 "Support for IPv6" On \
		NLS "Native Language Support with gettext" On \
		OPENSSL "Support for SSL via OpenSSL" On

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_OPENSSL)
.if !defined(WITHOUT_GNUTLS)
IGNORE=		GNUTLS and OPENSSL are mutually exclusive, enable at most one of them
.endif
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=--with-ssl
CPPFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
.elif !defined(WITHOUT_GNUTLS)
LIB_DEPENDS+=	gnutls:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=--with-ssl=gnutls
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=--without-ssl
.endif

.if !defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=--enable-ipv6
.else
CONFIGURE_ARGS+=--disable-ipv6
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ARGS+=--enable-nls
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB=	NLS="@comment "
.endif

MAN1=		wget.1
INFO=		wget

post-patch:
	${RM} -f ${WRKSRC}/doc/wget.info* ${WRKSRC}/po/*.mo ${WRKSRC}/po/*.gmo
	@# eliminate gmakism
	${REINPLACE_CMD} -e 's,$$<,$$(srcdir)/wget.texi,' \
		${WRKSRC}/doc/Makefile.in
	${REINPLACE_CMD} -e 's,/usr/local/etc/wgetrc,${PREFIX}/etc/wgetrc,' \
			 -e 's,@file{},@file{${PREFIX}},' \
		${WRKSRC}/doc/sample.wgetrc* ${WRKSRC}/doc/wget.texi

.include <bsd.port.post.mk>
