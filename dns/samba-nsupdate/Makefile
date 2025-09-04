PORTNAME=	nsupdate
DISTVERSION=	9.16.5
PORTREVISION=	1
CATEGORIES=	dns net
MASTER_SITES=	ISC/bind9/${DISTVERSION}
PKGNAMEPREFIX=	samba-
DISTNAME=	bind-${DISTVERSION}

MAINTAINER=	samba@FreeBSD.org
COMMENT=	nsupdate utility with the GSS-TSIG support
WWW=		https://www.isc.org/software/bind

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libuv.so:devel/libuv

USES=		autoreconf compiler:c11 cpe libedit libtool pkgconfig ssl \
		tar:xz

CPE_VENDOR=	isc
CPE_PRODUCT=	bind
CPE_VERSION=	${DISTVERSION:C/-.*//}
.if ${DISTVERSION:M*-*}
CPE_UPDATE=	${DISTVERSION:C/.*-//:tl}
.endif

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--disable-dnstap \
		--disable-fixed-rrset \
		--disable-geoip \
		--disable-largefile \
		--disable-linux-caps \
		--disable-native-pkcs11 \
		--disable-querytrace \
		--disable-shared \
		--disable-symtable \
		--disable-tcp-fastopen \
		--localstatedir=/var \
		--prefix=${PREFIX} \
		--sysconfdir="${PREFIX}/etc/namedb" \
		--with-dlopen=yes \
		--with-openssl=${OPENSSLBASE} \
		--with-readline="-L${LOCALBASE}/lib -ledit" \
		--with-tuning=default \
		--without-json-c \
		--without-libidn2 \
		--without-libxml2 \
		--without-lmdb \
		--without-maxminddb \
		--without-python

MAKE_JOBS_UNSAFE=	yes

EXTRA_PATCHES=	${PATCHDIR}/extrapatch-bind-tools

PLIST_FILES=	bin/${PKGBASE} \
		share/man/man1/${PKGBASE}.1.gz

OPTIONS_DEFINE=		VIOLATE_RFC_2845
OPTIONS_DEFAULT=	GSSAPI_BASE
OPTIONS_SINGLE=		GSSAPI
OPTIONS_SINGLE_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT
OPTIONS_SUB=		yes

GSSAPI_BASE_DESC=	Using Heimdal in base
GSSAPI_HEIMDAL_DESC=	Using security/heimdal
GSSAPI_MIT_DESC=	Using security/krb5
VIOLATE_RFC_2845_DESC=	Disable false TSIG error with Windows or Samba Internal DNS (EXPERIMENTAL)

GSSAPI_BASE_USES=		gssapi
GSSAPI_BASE_CONFIGURE_ON=	--with-gssapi=${GSSAPIBASEDIR} \
				KRB5CONFIG="${KRB5CONFIG}"

GSSAPI_HEIMDAL_USES=		gssapi:heimdal
GSSAPI_HEIMDAL_CONFIGURE_ON=	--with-gssapi=${GSSAPIBASEDIR} \
				KRB5CONFIG="${KRB5CONFIG}"

GSSAPI_MIT_USES=		gssapi:mit
GSSAPI_MIT_CONFIGURE_ON=	--with-gssapi=${GSSAPIBASEDIR} \
				KRB5CONFIG="${KRB5CONFIG}"

VIOLATE_RFC_2845_EXTRA_PATCHES=	${PATCHDIR}/extrapatch-bin_nsupdate_nsupdate.c

post-patch:
	@${REINPLACE_CMD} \
		-e 's|${PORTNAME}|${PKGBASE}|g' \
		${PATCH_WRKSRC}/doc/man/${PORTNAME}.1in

do-install:
	${INSTALL_MAN} ${INSTALL_WRKSRC}/doc/man/${PORTNAME}.1in ${STAGEDIR}${PREFIX}/share/man/man1/${PKGBASE}.1
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/bin/nsupdate/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PKGBASE}

.include <bsd.port.mk>
