# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Bio-Cluster
PORTVERSION=	1.7.3
CATEGORIES=	biology perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	BioPerl cluster modules

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

#TODO: Add Bio::Variation::SNP
BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-BioPerl>=0:biology/p5-BioPerl \
		p5-XML-SAX>=0:textproc/p5-XML-SAX

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
