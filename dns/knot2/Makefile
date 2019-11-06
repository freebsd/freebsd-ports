# Created by: Leo Vandewoestijne <freebsd@dns.company>
# $FreeBSD$

PORTNAME=	knot
DISTVERSION=	2.8.3
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	https://secure.nic.cz/files/knot-dns/ \
		https://dns.company/downloads/knot-dns/
PKGNAMESUFFIX?=	2

MAINTAINER=	freebsd@dns.company
COMMENT?=	High performance authoritative-only DNS server

LICENSE=	GPLv3

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON_i386=Uses 64 bit atomics that clang cannot generate on i386

LIB_DEPENDS=	libgnutls.so:security/gnutls \
		liblmdb.so:databases/lmdb \
		libnettle.so:security/nettle \
		liburcu.so:sysutils/liburcu

CONFLICTS=	knot-1.* knot1-[0-6].*

USES=		alias compiler:c11 libedit libtool localbase ncurses pkgconfig python tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-recvmmsg=no \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig

.if !defined(UTILS_ONLY) && !defined(LIB_ONLY)
CONFIGURE_ARGS+=	--with-rundir=/var/run/knot \
			--with-storage=/var/db/knot
USE_RC_SUBR=	${PORTNAME}
SUB_FILES=	pkg-message
.endif

.if defined(UTILS_ONLY) || defined(LIB_ONLY)
CONFIGURE_ARGS+=	--disable-daemon \
			--disable-modules
.endif

.if defined(LIB_ONLY)
CONFIGURE_ARGS+=	--disable-utilities
.endif

USE_LDCONFIG=	yes
LLD_UNSAFE=	yes
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

FASTPARSER_DESC=		Fast zone parser (demanding compilation)
FASTPARSER_CONFIGURE_ENABLE=	fastparser

IDN_CONFIGURE_WITH=		libidn
IDN_LIB_DEPENDS=		libidn2.so:dns/libidn2

MAXMINDDB_DESC=			Enable MaxMind for geodb module
MAXMINDDB_LIB_DEPENDS=		libmaxminddb.so:net/libmaxminddb
MAXMINDDB_CONFIGURE_ENABLE=	maxminddb

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
