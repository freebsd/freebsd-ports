# $FreeBSD$

PORTNAME=		nsupdate
PORTVERSION=		9.8.6
CATEGORIES=		dns net ipv6
MASTER_SITES=		${MASTER_SITE_ISC}
MASTER_SITE_SUBDIR=	bind9/${ISCVERSION}
PKGNAMEPREFIX=		samba-
DISTNAME=		bind-${ISCVERSION}

MAINTAINER=		timur@FreeBSD.org
COMMENT=		An nsupdate utility with GSS-TSIG support

LICENSE=		ISCL

# ISC releases things like 9.8.0-P1, which our versioning doesn't like
ISCVERSION=		9.8.6

MAKE_JOBS_UNSAFE=	yes

USE_AUTOTOOLS=		autoconf autoheader
USE_OPENSSL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	\
			--prefix=${PREFIX} \
			--sysconfdir="/etc/namedb" \
			--localstatedir=/var \
			--enable-largefile \
			--enable-threads \
			--disable-linux-caps \
			--disable-symtable \
			--disable-shared \
			--without-libxml2 \
			--without-iconv \
			--without-idn \
			--with-randomdev=/dev/random

NO_STAGE=		yes

.include <bsd.port.options.mk>

.include <bsd.port.pre.mk>

.if (${ARCH} == "amd64")
ARCH=		x86_64
.endif

.if ${PORT_OPTIONS:MSIGCHASE}
CONFIGURE_ARGS+=	STD_CDEFINES="-DDIG_SIGCHASE=1"
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.endif

# Enable OpenSSL API
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}
# Try to find appropriate GSSAPI libs
.if defined(KRB5_HOME) && exists(${KRB5_HOME}/lib/libgssapi_krb5.so)
CONFIGURE_ARGS+=	--with-gssapi="${KRB5_HOME}"
.elif defined(HEIMDAL_HOME) && exists(${HEIMDAL_HOME}/lib/libgssapi.so)
CONFIGURE_ARGS+=	--with-gssapi="${HEIMDAL_HOME}"
.elif exists(/usr/lib/libkrb5.so) && exists(/usr/bin/krb5-config)
CONFIGURE_ARGS+=	--with-gssapi="/usr"
.else
LIB_DEPENDS+=		krb5:${PORTSDIR}/security/heimdal
CONFIGURE_ARGS+=	--with-gssapi="${LOCALBASE}"
.endif

MAN1=			${UNIQUENAME}.1

PLIST_FILES=		bin/${UNIQUENAME}

post-patch:
			@${REINPLACE_CMD} \
				-e 's|^SUBDIRS.*|SUBDIRS = lib bin|' \
				-e 's|isc-config.sh installdirs|installdirs|' \
				-e 's|.*INSTALL.*isc-config.*||' \
				-e 's|.*INSTALL.*bind.keys.*||' \
			${WRKSRC}/Makefile.in
			@${REINPLACE_CMD} \
				-e 's|^SUBDIRS.*|SUBDIRS = ${PORTNAME}|' \
				-e 's|^.*check confgen ||' \
			${WRKSRC}/bin/Makefile.in
			@${REINPLACE_CMD} \
				-e 's|${PORTNAME}|${UNIQUENAME}|g' \
			${WRKSRC}/bin/nsupdate/${PORTNAME}.1

do-install:
			${INSTALL_MAN} ${WRKSRC}/bin/nsupdate/${PORTNAME}.1 ${MANPREFIX}/man/man1/${UNIQUENAME}.1
			${INSTALL_PROGRAM} ${WRKSRC}/bin/nsupdate/${PORTNAME} ${PREFIX}/bin/${UNIQUENAME}

.include <bsd.port.post.mk>
