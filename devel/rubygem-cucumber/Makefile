# $FreeBSD$

PORTNAME=	cucumber
PORTVERSION=	1.3.8
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Behaviour Driven Development with elegance and joy

RUN_DEPENDS=	rubygem-builder>=2.1.2:${PORTSDIR}/devel/rubygem-builder \
		rubygem-diff-lcs>=1.1.3:${PORTSDIR}/textproc/rubygem-diff-lcs \
		rubygem-gherkin>=2.12.1:${PORTSDIR}/textproc/rubygem-gherkin \
		rubygem-multi_json>=1.7.5:${PORTSDIR}/devel/rubygem-multi_json \
		rubygem-multi_test>=0.0.2:${PORTSDIR}/devel/rubygem-multi_test

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES+=	bin/cucumber


.include <bsd.port.mk>
