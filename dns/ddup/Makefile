# New ports collection makefile for:	ddup
# Version required:	2.0.4
# Date created:		30 September 1999
# Whom:			cjm2
#
# $FreeBSD$
#

DISTNAME=	ddup-2.0.4
CATEGORIES=	net
MASTER_SITES=	ftp://gandy.dyndns.org/pub/ddup/

MAINTAINER=	cjm2@altavista.net

WRKSRC=		${WRKDIR}/ddup-nic

MAN1=		ddup.1
MANCOMPRESSED=	no

post-configure:
	@${PERL} -pi.orig -e 's:/etc/ddup.conf:${PREFIX}/etc/ddup.conf:' \
		${WRKSRC}/INSTALL-C

post-install:
	${INSTALL_MAN} ${FILESDIR}/ddup.1 ${PREFIX}/man/man1
	strip ${PREFIX}/sbin/ddup

.include <bsd.port.mk>
