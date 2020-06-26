# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Config-IniHash
PORTVERSION=	3.01.01
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN/Config/JENDA
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for reading and writing INI files

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Hash-Case>=0:devel/p5-Hash-Case \
		p5-Hash-WithDefaults>=0.04:devel/p5-Hash-WithDefaults \
		p5-IO-Stringy>=0:devel/p5-IO-Stringy

USES=		dos2unix perl5
USE_PERL5=	configure

.include <bsd.port.mk>
