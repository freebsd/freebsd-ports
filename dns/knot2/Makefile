# Created by: Leo Vandewoestijne <freebsd@dns.company>
# $FreeBSD$

PORTNAME=	knot
DISTVERSION=	2.9.3
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	https://secure.nic.cz/files/knot-dns/ \
		https://dns.company/downloads/knot-dns/
PKGNAMESUFFIX?=	2

MAINTAINER=	freebsd@dns.company
COMMENT?=	High performance authoritative-only DNS server

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	knot-1.* knot1-[0-6].*

BUILD_DEPENDS=	autoconf>=2.65:devel/autoconf

LIB_DEPENDS=	libgnutls.so:security/gnutls \
		liblmdb.so:databases/lmdb

USES=		alias libtool localbase pkgconfig tar:xz

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-recvmmsg=no \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig \
		--mandir=${MANPREFIX}/man

.if !defined(UTILS_ONLY) && !defined(LIB_ONLY)
CONFIGURE_ARGS+=	--with-rundir=/var/run/knot \
			--with-storage=/var/db/knot
USE_RC_SUBR=	${PORTNAME}
SUB_FILES=	pkg-message
USES+=		libedit
LIB_DEPENDS+=	liburcu.so:sysutils/liburcu
.endif

.if defined(UTILS_ONLY) || defined(LIB_ONLY)
CONFIGURE_ARGS+=	--disable-daemon \
			--disable-modules
.endif

.if defined(LIB_ONLY)
CONFIGURE_ARGS+=	--disable-utilities
.endif

USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

USERS=		knot
GROUPS=		knot
SUB_LIST+=	USERS="${USERS}" GROUPS="${GROUPS}"

PORTDOCS=	COPYING NEWS README

OPTIONS_DEFINE=			DNSTAP DOCS

.if !defined(LIB_ONLY)
OPTIONS_DEFINE+=		IDN
.endif

.if !defined(UTILS_ONLY) && !defined(LIB_ONLY)
OPTIONS_DEFINE+=		FASTPARSER MAXMINDDB
.endif

DNSTAP_DESC=			dnstap support (see dnstap.info)
DNSTAP_CONFIGURE_ENABLE=	dnstap
DNSTAP_CONFIGURE_WITH=		module-dnstap=yes
DNSTAP_LIB_DEPENDS=		libprotobuf-c.so:devel/protobuf-c \
				libfstrm.so:devel/fstrm
# XXX: because `kdig_CPPFLAGS += $(DNSTAP_CFLAGS)' line is missing from
# `src/Makefile.am' file (and thus pre-generated `src/Makefile.in') which
# should contain "$libfstrm_CFLAGS $libprotobuf_c_CFLAGS" set by configure
# script, provide it here explicitly as patching those files would result
# in higher line count.  Ideally this bug should be fixed upstream.
DNSTAP_CPPFLAGS=		-I${LOCALBASE}/include

DOCS_USES+=			python
DOCS_CONFIGURE_OFF=		--disable-documentation

FASTPARSER_DESC=		Fast zone parser (demanding compilation)
FASTPARSER_CONFIGURE_ENABLE=	fastparser

IDN_CONFIGURE_WITH=		libidn
IDN_CONFIGURE_OFF=		--without-libidn
IDN_LIB_DEPENDS=		libidn2.so:dns/libidn2

MAXMINDDB_DESC=			Enable MaxMind for geodb module
MAXMINDDB_LIB_DEPENDS=		libmaxminddb.so:net/libmaxminddb
MAXMINDDB_CONFIGURE_ENABLE=	maxminddb

.include <bsd.port.options.mk>

.if ${ARCH} == i386
USES+=				autoreconf
EXTRA_PATCHES+=			${PATCHDIR}/extrapatch-configure.ac
.endif

post-patch:
.if !defined(UTILS_ONLY) && !defined(LIB_ONLY)
	@${REINPLACE_CMD} 's|$$(INSTALL) -d $$(DESTDIR)/\@run_dir\@|#$$(INSTALL) -d $$(DESTDIR)/\@run_dir\@|' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} 's|$$(INSTALL) -d $$(DESTDIR)/\@storage_dir\@|#$$(INSTALL) -d $$(DESTDIR)/\@storage_dir\@|' \
		${WRKSRC}/src/Makefile.in
	@${RM} -r ${WRKSRC}/src/zscanner/scanner.c
.endif

post-install:
.if !defined(UTILS_ONLY) && !defined(LIB_ONLY)
	${MV} ${STAGEDIR}${ETCDIR}/knot.sample.conf \
		${STAGEDIR}${ETCDIR}/knot.conf.sample
	@${MKDIR} ${STAGEDIR}/var/run/knot ${STAGEDIR}/var/db/knot
.endif
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
