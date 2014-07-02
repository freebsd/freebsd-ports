# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Term-EditLine
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Perl interface to the NetBSD editline library

USES=		perl5
USE_PERL5=	configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto/Term/EditLine/EditLine.so

.include <bsd.port.mk>
