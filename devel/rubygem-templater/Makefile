# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	templater
PORTVERSION=	1.0.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby code generation framework

LICENSE=	MIT

RUN_DEPENDS=	rubygem-diff-lcs>=1.1.2:${PORTSDIR}/textproc/rubygem-diff-lcs \
		rubygem-extlib>=0.9.5:${PORTSDIR}/devel/rubygem-extlib \
		rubygem-highline>=1.4.0:${PORTSDIR}/devel/rubygem-highline

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
