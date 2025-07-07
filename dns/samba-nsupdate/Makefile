PORTNAME=		nsupdate
PORTVERSION=		9.16.5
PORTREVISION=		1
CATEGORIES=		dns net
MASTER_SITES=		ISC/bind9/${ISCVERSION}
PKGNAMEPREFIX=		samba-
DISTNAME=		bind-${ISCVERSION}

MAINTAINER=		ports@FreeBSD.org
COMMENT=		nsupdate utility with the GSS-TSIG support
WWW=		https://www.isc.org/software/bind

LICENSE=		MPL20
LICENSE_FILE=		${WRKSRC}/COPYRIGHT

LIB_DEPENDS=		libuv.so:devel/libuv

USES=			autoreconf compiler:c11 cpe libedit libtool pkgconfig ssl tar:xz

# ISC releases things like 9.8.0-P1, which our versioning doesn't like
ISCVERSION=		9.16.5

CPE_VENDOR=		isc
CPE_PRODUCT=		bind
CPE_VERSION=		${ISCVERSION:C/-.*//}
.if ${ISCVERSION:M*-*}
CPE_UPDATE=		${ISCVERSION:C/.*-//:tl}
.endif

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	\
			--prefix=${PREFIX} \
			--sysconfdir="${PREFIX}/etc/namedb" \
			--localstatedir=/var \
			--disable-largefile \
			--disable-linux-caps \
			--disable-shared \
			--disable-symtable \
			--disable-dnstap \
			--disable-fixed-rrset \
			--disable-geoip \
			--disable-native-pkcs11 \
			--disable-querytrace \
			--disable-tcp-fastopen \
			--with-tuning=default \
			--with-dlopen=yes \
			--with-readline="-L${LOCALBASE}/lib -ledit" \
			--with-openssl=${OPENSSLBASE} \
			--without-maxminddb \
			--without-libxml2 \
			--without-lmdb  \
			--without-json-c \
			--without-python \
			--without-libidn2

EXTRA_PATCHES=		${PATCHDIR}/extrapatch-bind-tools

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFAULT=	GSSAPI_BASE

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

PLIST_FILES=		bin/${PKGBASE} \
			share/man/man1/${PKGBASE}.1.gz

.include <bsd.port.pre.mk>

post-patch:
		@${REINPLACE_CMD} \
			-e 's|${PORTNAME}|${PKGBASE}|g' \
		${PATCH_WRKSRC}/doc/man/${PORTNAME}.1in

do-install:
		${INSTALL_MAN} ${INSTALL_WRKSRC}/doc/man/${PORTNAME}.1in ${STAGEDIR}${PREFIX}/share/man/man1/${PKGBASE}.1
		${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/bin/nsupdate/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PKGBASE}

.include <bsd.port.post.mk>
