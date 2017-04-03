# $FreeBSD$

PORTNAME=	Getopt-EX
PORTVERSION=	7.1.20170330
DISTVERSIONPREFIX=	v
CATEGORIES=	devel perl5
PKGNAMEPREFIX=	p5-

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Getopt Extender

LICENSE=	ART10

USES=		perl5
USE_PERL5=	run
USE_GITHUB=	yes
GH_TUPLE=	kaz-utashiro:greple:084c10e
NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	cd ${WRKSRC}/lib && \
	    ${COPYTREE_SHARE} Getopt ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}

.include <bsd.port.mk>
