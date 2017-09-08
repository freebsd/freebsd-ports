# Created by: Leo Vandewoestijne <freebsd@dns-lab.com>
# $FreeBSD$

PORTNAME=	knot
PORTVERSION=	1.6.8
PORTREVISION=	3
CATEGORIES=	dns ipv6
MASTER_SITES=	https://secure.nic.cz/files/knot-dns/ \
		http://dns-lab.com/downloads/knot-dns/
PKGNAMESUFFIX=	1

MAINTAINER=	freebsd@dns-lab.com
COMMENT=	High performance authoritative-only DNS server

LICENSE=	GPLv3

BUILD_DEPENDS=	flex>=2.5.35_1:textproc/flex
LIB_DEPENDS=	liburcu.so:sysutils/liburcu

CONFLICTS=	knot-2.* knot2-.*

USES=		alias bison libtool pkgconfig ssl tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-storage=/var/db/knot \
		--with-rundir=/var/run/knot \
		--with-openssl=${OPENSSLBASE} \
		--enable-recvmmsg=no

USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

USE_RC_SUBR=	${PORTNAME}
SUB_FILES=	pkg-message

USERS=		knot
GROUPS=		knot
SUB_LIST+=	USERS="${USERS}" GROUPS="${GROUPS}"

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README THANKS

OPTIONS_DEFINE=	DNSTAP IDN LMDB

DNSTAP_DESC=		dnstap support (see dnstap.info)
LMDB_DESC=		Enable LMDB backend

DNSTAP_CONFIGURE_ENABLE=	dnstap
DNSTAP_LIB_DEPENDS=	libfstrm.so:devel/fstrm \
			libprotobuf-c.so:devel/protobuf-c

IDN_CONFIGURE_WITH=	libidn
IDN_LIB_DEPENDS=	libidn.so:dns/libidn

LMDB_CONFIGURE_ENABLE=	lmdb
LMDB_LIB_DEPENDS=	liblmdb.so:databases/lmdb

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
