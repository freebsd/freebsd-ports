# Created by: Mike Fisher <Michael_Fisher@URMC.Rochester.edu>
# $FreeBSD$

PORTNAME=	Data-Page-Pageset
PORTVERSION=	1.02
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CHUNZI
PKGNAMEPREFIX=	p5-

MAINTAINER=	Michael_Fisher@URMC.Rochester.edu
COMMENT=	Perl extension to simplify page number lists

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Data-Page>=2:databases/p5-Data-Page \
	p5-Class-Accessor>0:devel/p5-Class-Accessor \
	p5-Carp>0:devel/p5-Carp
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
