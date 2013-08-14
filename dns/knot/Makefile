# Created by: Leo Vandewoestijne <freebsd@dns-lab.com>
# $FreeBSD$

PORTNAME=	knot
DISTVERSION=	1.3.0r1
CATEGORIES=	dns ipv6
MASTER_SITES=	https://secure.nic.cz/files/knot-dns/ \
		http://www.dns-lab.com/downloads/knot-dns/
DISTNAME=	knot-1.3.0-rc1

MAINTAINER=	freebsd@dns-lab.com
COMMENT=	Knot DNS is a high performance authoritative-only DNS server

LICENSE=	GPLv3

BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison \
		flex>=2.5.35_1:${PORTSDIR}/textproc/flex
LIB_DEPENDS=	urcu:${PORTSDIR}/sysutils/liburcu

USE_AUTOTOOLS=	libtool

USE_LDCONFIG=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${ETCDIR}

SUB_FILES=	pkg-message

USE_RC_SUBR=	${PORTNAME}d

MAN8=		knotc.8 knotd.8 kdig.8 khost.8 knsupdate.8
MAN5=		knot.conf.5

INFO=		knot

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README THANKS

.include <bsd.port.options.mk>

post-install:
	@${MKDIR} ${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/knot.sample.conf ${ETCDIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif
	@${CAT} ${WRKDIR}/pkg-message

.include <bsd.port.mk>
