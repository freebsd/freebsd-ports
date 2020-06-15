# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Term-App-Roles
PORTVERSION=	0.031
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Collection of roles for terminal-based application

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Moo>=0:devel/p5-Moo \
		p5-Term-App-Util-Color>=0:devel/p5-Term-App-Util-Color \
		p5-Term-App-Util-Interactive>=0.002:devel/p5-Term-App-Util-Interactive \
		p5-Term-App-Util-Size>=0:devel/p5-Term-App-Util-Size \
		p5-Term-Detect-Software>=0:devel/p5-Term-Detect-Software

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
