# Created by: Michael Moll <kvedulv@kvedulv.de>
# $FreeBSD$

PORTNAME=	classifier-reborn
PORTVERSION=	2.0.4
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Classifier module for Bayesian and other types of classifications

LICENSE=	LGPL21

RUN_DEPENDS=	rubygem-fast-stemmer>=1.0.0:${PORTSDIR}/devel/rubygem-fast-stemmer

PLIST_FILES=	bin/bayes.rb bin/summarize.rb

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
