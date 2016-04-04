# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Marpa-XS
PORTVERSION=	1.008000
PORTREVISION=	2
CATEGORIES=	lang textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JKEGL
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	XS version of Marpa

LICENSE=	LGPL3

BUILD_DEPENDS=	p5-ExtUtils-PkgConfig>=0:devel/p5-ExtUtils-PkgConfig \
		p5-Glib2>=1.223:devel/p5-Glib2 \
		p5-PPI>=1.206:textproc/p5-PPI \
		p5-Task-Weaken>=0:devel/p5-Task-Weaken
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Weaken>=3.004000:devel/p5-Test-Weaken

USE_PERL5=	modbuild
USES=		perl5

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Marpa/XS/XS.so

.include <bsd.port.mk>
