# ports collection Makefile for: weedns_sc
# Whom:			Matthias Andree <matthias.andree@gmx.de>
# Date created:		2003-05-22
#
# $FreeBSD$
#

PORTNAME=	weedns_sc
PORTVERSION=	1.19
CATEGORIES=	dns perl5
MASTER_SITES=	http://www.weedns.com/clients/
EXTRACT_SUFX=	.tgz

MAINTAINER=	matthias.andree@gmx.de
COMMENT=	Client to update whyi.org dynamic DNS service

RUN_DEPENDS=	${SITE_PERL}/HTTP/Request/Common.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
		${SITE_PERL}/URI/Escape.pm:${PORTSDIR}/net/p5-URI

USE_PERL5=	yes
USE_REINPLACE=	yes
NO_BUILD=	yes

post-patch:
		${REINPLACE_CMD} "s|^#!/usr/bin/perl|#!${PERL}|" ${WRKSRC}/bin/skeleton_client.pl
		${REINPLACE_CMD} "s|^#!/usr/bin/perl|#!${PERL}|" ${WRKSRC}/bin/smtp_ip.pl

do-install:
		${MKDIR} ${PREFIX}/bin
		${MKDIR} ${PREFIX}/etc
		${MKDIR} ${SITE_PERL}/WeedNS
		${INSTALL_SCRIPT} ${WRKSRC}/bin/skeleton_client.pl ${PREFIX}/bin
		${INSTALL_SCRIPT} ${WRKSRC}/bin/smtp_ip.pl ${PREFIX}/bin
		${INSTALL_SCRIPT} ${WRKSRC}/lib/WeedNS/Client.pm ${SITE_PERL}/WeedNS
.if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}
		${INSTALL_MAN} ${WRKSRC}/skeleton_client.html ${DOCSDIR}
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	"requires Perl 5.6+. Install lang/perl5, run use.perl port, retry"
.endif

.include <bsd.port.post.mk>
