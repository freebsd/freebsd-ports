# Created by: Leo Vandewoestijne <freebsd@dns-lab.com>
# $FreeBSD$

PORTNAME=	knot
PORTVERSION=	2.5.3
PORTREVISION=	3
CATEGORIES=	dns ipv6
MASTER_SITES=	https://secure.nic.cz/files/knot-dns/ \
		http://dns-lab.com/downloads/knot-dns/
PKGNAMESUFFIX=	2

MAINTAINER=	freebsd@dns-lab.com
COMMENT=	High performance authoritative-only DNS server

LICENSE=	GPLv3

LIB_DEPENDS=	libgnutls.so:security/gnutls \
		liblmdb.so:databases/lmdb \
		libnettle.so:security/nettle \
		liburcu.so:sysutils/liburcu

CONFLICTS=	knot-1.* knot1-[0-6].*

USES=		autoreconf alias compiler:c11 libedit libtool localbase pkgconfig python shebangfix tar:xz
SHEBANG_FILES=	src/utils/pykeymgr/pykeymgr.in
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-rundir=/var/run/knot \
		--with-storage=/var/db/knot \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig \
		--enable-recvmmsg=no

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

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
CPUTYPE=	i686
CFLAGS+=	-march=i686
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1100000
USE_GCC=	yes
.endif
.endif

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

.include <bsd.port.post.mk>
