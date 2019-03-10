# $FreeBSD$

PORTNAME=	Shell-Config-Generate
PORTVERSION=	0.33
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Portably generate config for any shell

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Shell-Guess>=0.09:devel/p5-Shell-Guess \
		p5-Test2-Suite>=0.000118:devel/p5-Test2-Suite

USES=		perl5
USE_PERL5=	configure

PLIST_FILES=	${SITE_PERL_REL}/Shell/Config/Generate.pm \
		${SITE_MAN3_REL}/Shell::Config::Generate.3.gz

.include <bsd.port.mk>
