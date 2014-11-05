# Created by: Leo Vandewoestijne <freebsd@dns-lab.com>
# $FreeBSD$

PORTNAME=	knot
PORTVERSION=	1.6.0
CATEGORIES=	dns ipv6
MASTER_SITES=	https://secure.nic.cz/files/knot-dns/ \
		http://dns-lab.com/downloads/knot-dns/

MAINTAINER=	freebsd@dns-lab.com
COMMENT=	Knot DNS is a high performance authoritative-only DNS server

LICENSE=	GPLv3

BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison \
		flex>=2.5.35_1:${PORTSDIR}/textproc/flex
LIB_DEPENDS=	liburcu.so:${PORTSDIR}/sysutils/liburcu

USES=		alias libtool

USE_LDCONFIG=	yes

USE_OPENSSL=		yes
WITH_OPENSSL_PORT=	yes

INSTALL_TARGET=	install-strip

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-storage=/var/db/knot
CONFIGURE_ARGS+=	--with-rundir=/var/run/knot

OPTIONS_DEFINE=	FASTPARSER IDNA

FASTPARSER_CONFIGURE_ENABLE=	fastparser
FASTPARSER_DESC=		Fast zone parser (demanding compilation)

IDNA_CONFIGURE_WITH=	libidn
IDNA_DESC=		IDN support in knot utilities
IDNA_LIB_DEPENDS=	libidn.so:${PORTSDIR}/dns/libidn

SUB_FILES=	pkg-message

USE_RC_SUBR=	${PORTNAME}

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README THANKS

USERS=		knot
GROUPS=		knot
SUB_LIST+=	USERS="${USERS}" GROUPS="${GROUPS}"

post-patch:
	@${REINPLACE_CMD} 's|$$(INSTALL) -d $$(DESTDIR)/\@run_dir\@|#$$(INSTALL) -d $$(DESTDIR)/\@run_dir\@|' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} 's|$$(INSTALL) -d $$(DESTDIR)/\@storage_dir\@|#$$(INSTALL) -d $$(DESTDIR)/\@storage_dir\@|' \
		${WRKSRC}/src/Makefile.in
	@${RM} -rf ${WRKSRC}/src/zscanner/scanner.c

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/knot.sample.conf ${STAGEDIR}${ETCDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
