# Created by: Masahiro Teramoto <markun@onohara.to>
# $FreeBSD$

PORTNAME=	DateTime-Calendar-Japanese-Era
PORTVERSION=	0.08001
PORTREVISION=	2
CATEGORIES=	japanese devel perl5
MASTER_SITES=	CPAN

MAINTAINER=	markun@onohara.to
COMMENT=	DateTime Extension for Japanese Eras

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-Class-Data-Inheritable>=0:devel/p5-Class-Data-Inheritable \
		p5-Module-Install>=0.91:devel/p5-Module-Install \
		p5-DateTime>=0:devel/p5-DateTime \
		p5-File-ShareDir>=0:devel/p5-File-ShareDir \
		p5-Params-Validate>=0:devel/p5-Params-Validate \
		p5-YAML-Tiny>=1.38:textproc/p5-YAML-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-YAML>=0:textproc/p5-YAML

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${RM} -rf ${WRKSRC}/inc

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

.include <bsd.port.post.mk>
