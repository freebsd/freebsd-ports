# Created by: Leo Vandewoestijne <freebsd@dns-lab.com>
# $FreeBSD$

PORTNAME=	knot
DISTVERSION=	1.3.3
CATEGORIES=	dns ipv6
MASTER_SITES=	https://secure.nic.cz/files/knot-dns/ \
		http://dns-lab.com/downloads/knot-dns/

MAINTAINER=	freebsd@dns-lab.com
COMMENT=	Knot DNS is a high performance authoritative-only DNS server

LICENSE=	GPLv3

BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison \
		flex>=2.5.35_1:${PORTSDIR}/textproc/flex
LIB_DEPENDS=	liburcu.so:${PORTSDIR}/sysutils/liburcu

USE_AUTOTOOLS=	libtool

USE_LDCONFIG=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes

SUB_FILES=	pkg-message

USE_RC_SUBR=	${PORTNAME}d

INFO=		knot

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README THANKS

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/knot.sample.conf ${STAGEDIR}${ETCDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
