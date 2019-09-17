# Created by: Sergei Vyshenski
# $FreeBSD$

PORTNAME=	SPOPS
PORTVERSION=	0.87
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CWINTERS
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Simple Perl Object Persistence with Security

LICENSE=	ART10 GPLv2+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Accessor>=0.17:devel/p5-Class-Accessor \
		p5-Class-Date>=1:devel/p5-Class-Date \
		p5-Class-Factory>=1:devel/p5-Class-Factory \
		p5-Class-Fields>=0.140:devel/p5-Class-Fields \
		p5-Class-ISA>=0.32:devel/p5-Class-ISA \
		p5-Devel-StackTrace>=0.90:devel/p5-Devel-StackTrace \
		p5-Log-Dispatch>=2:devel/p5-Log-Dispatch \
		p5-Log-Log4perl>=0.35:devel/p5-Log-Log4perl

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
