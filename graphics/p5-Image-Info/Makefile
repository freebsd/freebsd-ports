# Created by: Shell Hung <shell@shellhung.org>
# $FreeBSD$

PORTNAME=	Image-Info
PORTVERSION=	1.39
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for getting image information

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-IO-String>=0:devel/p5-IO-String \
		p5-XML-LibXML>=0:textproc/p5-XML-LibXML \
		p5-XML-Simple>=0:textproc/p5-XML-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
