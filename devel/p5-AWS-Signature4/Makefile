# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	AWS-Signature4
PORTVERSION=	1.02
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Create a version4 signature for Amazon Web Services

LICENSE=	ART20 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_ART20=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-TimeDate>=0:devel/p5-TimeDate \
		p5-URI>=1.59:net/p5-URI \
		p5-libwww>=5.835:www/p5-libwww

USES=		perl5
USE_PERL5=	modbuild

NO_ARCH=	yes

.include <bsd.port.mk>
