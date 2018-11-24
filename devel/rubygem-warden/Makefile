# Created by: Ryan Steinmetz <rpsfa@rit.edu>
# $FreeBSD$

PORTNAME=	warden
PORTVERSION=	1.2.8
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Rack middleware that provides authentication for rack applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

# Change from rubygem-rack>=2.0.6 to rubygem-rack>=1.6 as a workround for www/gitlab-ce
# Ref: https://lists.freebsd.org/pipermail/svn-ports-head/2018-November/193262.html
RUN_DEPENDS=	rubygem-rack>=1.6:www/rubygem-rack

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
