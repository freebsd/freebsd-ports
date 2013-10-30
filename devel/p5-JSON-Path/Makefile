# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	JSON-Path
PORTVERSION=	0.204
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Search nested hashref/arrayref structures using JSONPath

BUILD_DEPENDS=	p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter \
    		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-Lvalue>=0:${PORTSDIR}/devel/p5-Lvalue
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

post-patch::
	@${RM} ${WRKSRC}/lib/JSON/Path.pm.orig

.include <bsd.port.mk>
