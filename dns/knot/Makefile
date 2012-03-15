# New ports collection makefile for:	knot
# Date created:		29 February 2012
# Whom:			Leo Vandewoestijne <freebsd@dns-lab.com>
#
# $FreeBSD$
#

PORTNAME=	knot
PORTVERSION=	1.0.1
CATEGORIES=	dns ipv6
MASTER_SITES=	http://public.nic.cz/files/knot-dns/ \
		http://www.dns-lab.com/downloads/knot-dns/

MAINTAINER=	freebsd@dns-lab.com
COMMENT=	Knot DNS is a high performance authoritative-only DNS server

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison \
		flex>=2.5.35_1:${PORTSDIR}/textproc/flex
LIB_DEPENDS=	urcu.1:${PORTSDIR}/sysutils/userspace-rcu

ONLY_FOR_ARCHS=		i386 amd64
ONLY_FOR_ARCHS_REASON=	will not configure. See ports/165798
CONFIGURE_ARGS=	--sysconfdir=${ETCDIR}
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
USE_OPENSSL=	yes

SUB_FILES=	pkg-message

USE_RC_SUBR=	${PORTNAME}d

MAN8=		knotc.8 knotd.8

PORTDOCS=	AUTHORS ChangeLog CodingStyle COPYING \
		INSTALL KNOWN_ISSUES NEWS README RELNOTES

post-install:
	@${MKDIR} ${ETCDIR}
	@${INSTALL_DATA} ${WRKSRC}/samples/knot.min.conf ${ETCDIR}
	@if [ ! -f ${ETCDIR}/knot.conf ]; then \
		${INSTALL_DATA} ${ETCDIR}/knot.min.conf ${ETCDIR}/knot.conf; \
	fi
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
