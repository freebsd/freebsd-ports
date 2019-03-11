# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	strictures
PORTVERSION=	2.000006
PORTEPOCH=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:HAARG
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Turn on strict and make all warnings fatal

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

OPTIONS_DEFINE=	STRICTURES_EXTRA
OPTIONS_DEFAULT=STRICTURES_EXTRA

STRICTURES_EXTRA_DESC=		Enable full set of strictures (recommended)
STRICTURES_EXTRA_BUILD_DEPENDS=	p5-bareword-filehandles>=0:devel/p5-bareword-filehandles \
				p5-indirect>=0:devel/p5-indirect \
				p5-multidimensional>=0:devel/p5-multidimensional
STRICTURES_EXTRA_RUN_DEPENDS=	${STRICTURES_EXTRA_BUILD_DEPENDS}

.include <bsd.port.mk>
