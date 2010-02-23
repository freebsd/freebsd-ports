# ex:ts=8
# New ports collection makefile for:	walker
# Date created:			May 30, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	walker
PORTVERSION=	3.8
CATEGORIES=	dns
MASTER_SITES=	http://josefsson.org/${PORTNAME}/releases/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Recover zone file information from servers that use DNSSEC

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS \
		${SITE_PERL}/Net/DNS/SEC.pm:${PORTSDIR}/dns/p5-Net-DNS-SEC

USE_PERL5=	yes
NO_BUILD=	yes

MAN1=		walker.1
PLIST_FILES=	bin/walker
PORTDOCS=	index.html

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/walker ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/index.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
