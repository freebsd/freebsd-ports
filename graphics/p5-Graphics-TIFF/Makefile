# created by: cmt@FreeBSD.org

PORTNAME=	Graphics-TIFF
PORTVERSION=	16
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	Perl extension for the libtiff library

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-ExtUtils-Depends>0:devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>0:devel/p5-ExtUtils-PkgConfig
LIB_DEPENDS=	libtiff.so:graphics/tiff

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
