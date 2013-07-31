# $FreeBSD$

PORTNAME=	Clone
PORTVERSION=	0.34
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Clone - recursively copy Perl datatypes

USES=		perl5
USE_PERL5=	patch configure

MAN3=		Clone.3

post-patch:
	${PERL} -pi -e 'm.OPTIMIZE.&&s,.,,sg' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
