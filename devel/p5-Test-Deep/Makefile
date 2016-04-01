# Created by: Alex Kapranoff <alex@kapranoff.ru>
# $FreeBSD$

PORTNAME=	Test-Deep
PORTVERSION=	1.120
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Test data structures for differences deeply

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

NO_ARCH=	yes
REINPLACE_ARGS=	-i ''
USES=		perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -e '/return (/s/;/);/' ${WRKSRC}/lib/Test/Deep/RegexpOnly.pm

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502200
BUILD_DEPENDS+=	p5-Test-Simple>=1.001.014:devel/p5-Test-Simple
RUN_DEPENDS+=	p5-Test-Simple>=1.001.014:devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
