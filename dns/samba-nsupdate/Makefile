# $FreeBSD$

PORTNAME=		nsupdate
PORTVERSION=		9.13.3
PORTREVISION=	1
CATEGORIES=		dns net ipv6
MASTER_SITES=		ISC/bind9/${ISCVERSION}
PKGNAMEPREFIX=		samba-
DISTNAME=		bind-${ISCVERSION}

MAINTAINER=		timur@FreeBSD.org
COMMENT=		nsupdate utility with GSS-TSIG support

LICENSE=		MPL20
LICENSE_FILE=		${WRKSRC}/COPYRIGHT

USES=			compiler:c11 cpe libedit autoreconf libtool pkgconfig ssl
# ISC releases things like 9.8.0-P1, which our versioning doesn't like
ISCVERSION=		9.13.3

CPE_VENDOR=		isc
CPE_VERSION=		${ISCVERSION:C/-.*//}
.if ${ISCVERSION:M*-*}
CPE_UPDATE=		${ISCVERSION:C/.*-//:tl}
.endif

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	\
			--prefix=${PREFIX} \
			--sysconfdir="${PREFIX}/etc/namedb" \
			--localstatedir=/var \
			--enable-largefile \
			--enable-threads \
			--disable-linux-caps \
			--disable-symtable \
			--with-dlopen=yes \
			--with-readline="-L${LOCALBASE}/lib -ledit" \
			--with-openssl=${OPENSSLBASE} \
			--disable-shared \
			--without-libxml2 \
			--without-iconv \
			--without-idn

CONFIGURE_ENV+=		STD_CDEFINES="-DDIG_SIGCHASE=1" ACLOCAL_AMFLAGS="-I m4"

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFAULT=	GSSAPI_BASE

OPTIONS_DEFINE=		IPV6
OPTIONS_SINGLE=		GSSAPI
OPTIONS_SINGLE_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT

OPTIONS_SUB=		yes

GSSAPI_BASE_DESC=	Using Heimdal in base
GSSAPI_HEIMDAL_DESC=	Using security/heimdal
GSSAPI_MIT_DESC=	Using security/krb5

GSSAPI_BASE_CONFIGURE_ON=\
			--with-gssapi=${GSSAPIBASEDIR} KRB5CONFIG="${KRB5CONFIG}"
GSSAPI_BASE_USES=	gssapi

GSSAPI_HEIMDAL_CONFIGURE_ON=\
			--with-gssapi=${GSSAPIBASEDIR} KRB5CONFIG="${KRB5CONFIG}"
GSSAPI_HEIMDAL_USES=	gssapi:heimdal

GSSAPI_MIT_CONFIGURE_ON=\
			--with-gssapi=${GSSAPIBASEDIR} KRB5CONFIG="${KRB5CONFIG}"
GSSAPI_MIT_USES=	gssapi:mit

IPV6_CONFIGURE_ENABLE=	ipv6

PLIST_FILES=		bin/${PKGBASE} \
			man/man1/${PKGBASE}.1.gz

.include <bsd.port.pre.mk>

post-patch:
		@${REINPLACE_CMD} \
			-e 's|^SUBDIRS.*|SUBDIRS = lib bin|' \
			-e 's|isc-config.sh installdirs|installdirs|' \
			-e 's|.*INSTALL.*isc-config.*||' \
			-e 's|.*INSTALL.*bind.keys.*||' \
		${PATCH_WRKSRC}/Makefile.in
		@${REINPLACE_CMD} \
			-e 's|^SUBDIRS.*|SUBDIRS = ${PORTNAME} \\|' \
			-e 's|^.*check confgen ||' \
			-e '/tests$$/d' \
		${PATCH_WRKSRC}/bin/Makefile.in
		@${REINPLACE_CMD} \
			-e 's|${PORTNAME}|${PKGBASE}|g' \
		${PATCH_WRKSRC}/bin/nsupdate/${PORTNAME}.1

do-install:
		${INSTALL_MAN} ${INSTALL_WRKSRC}/bin/nsupdate/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1/${PKGBASE}.1
		${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/bin/nsupdate/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PKGBASE}

.include <bsd.port.post.mk>
