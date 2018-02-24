# Created by: Leo Vandewoestijne <freebsd@dns-lab.com>
# $FreeBSD$

PORTNAME=	knot
DISTVERSION=	2.6.5
CATEGORIES=	dns ipv6
MASTER_SITES=	https://secure.nic.cz/files/knot-dns/ \
		https://dns.company/downloads/knot-dns/
PKGNAMESUFFIX=	2

MAINTAINER=	freebsd@dns-lab.com
COMMENT=	High performance authoritative-only DNS server

LICENSE=	GPLv3

LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libidn2.so:dns/libidn2 \
		liblmdb.so:databases/lmdb \
		libnettle.so:security/nettle \
		liburcu.so:sysutils/liburcu

CONFLICTS=	knot-1.* knot1-[0-6].*

USES=		alias compiler:c11 libedit libtool localbase ncurses pkgconfig python shebangfix tar:xz
GNU_CONFIGURE=	yes
SHEBANG_FILES=	src/utils/pykeymgr/pykeymgr.in
CONFIGURE_ARGS=	--with-rundir=/var/run/knot \
		--with-storage=/var/db/knot \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig \
		--enable-recvmmsg=no
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
USE_RC_SUBR=	${PORTNAME}
SUB_FILES=	pkg-message

USERS=		knot
GROUPS=		knot
SUB_LIST+=	USERS="${USERS}" GROUPS="${GROUPS}"

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README THANKS

OPTIONS_DEFINE=			DNSTAP FASTPARSER IDN

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
IDN_LIB_DEPENDS=		libidn.so:dns/libidn

post-patch:
	@${REINPLACE_CMD} 's|$$(INSTALL) -d $$(DESTDIR)/\@run_dir\@|#$$(INSTALL) -d $$(DESTDIR)/\@run_dir\@|' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} 's|$$(INSTALL) -d $$(DESTDIR)/\@storage_dir\@|#$$(INSTALL) -d $$(DESTDIR)/\@storage_dir\@|' \
		${WRKSRC}/src/Makefile.in
	@${RM} -r ${WRKSRC}/src/zscanner/scanner.c

post-install:
	${MV} ${STAGEDIR}${ETCDIR}/knot.sample.conf \
		${STAGEDIR}${ETCDIR}/knot.conf.sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
