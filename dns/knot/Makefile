# Created by: Leo Vandewoestijne <freebsd@dns-lab.com>
# $FreeBSD$

PORTNAME=	knot
DISTVERSION=	1.1.3
CATEGORIES=	dns ipv6
MASTER_SITES=	https://secure.nic.cz/files/knot-dns/ \
		http://www.dns-lab.com/downloads/knot-dns/

MAINTAINER=	freebsd@dns-lab.com
COMMENT=	Knot DNS is a high performance authoritative-only DNS server

LICENSE=	GPLv3

BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison \
		flex>=2.5.35_1:${PORTSDIR}/textproc/flex
LIB_DEPENDS=	urcu:${PORTSDIR}/sysutils/userspace-rcu

CONFIGURE_ARGS=	--sysconfdir=${ETCDIR}
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
USE_AUTOTOOLS=	libtool
USE_OPENSSL=	yes

.include <bsd.port.pre.mk>

SUB_FILES=	pkg-message

USE_RC_SUBR=	${PORTNAME}d

MAN8=		knotc.8 knotd.8
MAN5=		knot.conf.5

INFO=		knot

PORTDOCS=	AUTHORS ChangeLog CodingStyle \
		INSTALL KNOWN_ISSUES NEWS README RELNOTES

post-install:
	@${MKDIR} ${ETCDIR}
	@${INSTALL_DATA} ${WRKSRC}/samples/knot.min.conf ${ETCDIR}
	@${INSTALL_DATA} ${WRKSRC}/samples/knot.full.conf ${ETCDIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif
	@${CAT} ${WRKDIR}/pkg-message

.include <bsd.port.post.mk>
