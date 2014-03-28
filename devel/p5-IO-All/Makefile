# Created by: Elvis Chiang <elvis@sslab.cs.ccu.edu.tw>
# $FreeBSD$

PORTNAME=	IO-All
PORTVERSION=	0.60
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	IO::All combines all of the best Perl IO modules

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-File-ReadBackwards>=0:${PORTSDIR}/devel/p5-File-ReadBackwards \
		p5-IO-String>=1.08:${PORTSDIR}/devel/p5-IO-String
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-File-MimeInfo>=0:${PORTSDIR}/devel/p5-File-MimeInfo \
		p5-MLDBM>=0:${PORTSDIR}/databases/p5-MLDBM

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
