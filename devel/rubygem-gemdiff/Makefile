# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gemdiff
PORTVERSION=	3.0.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Command-line utility for ruby gems

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-launchy>=2.4<3:devel/rubygem-launchy \
		rubygem-octokit>=4.0<5:net/rubygem-octokit \
		rubygem-thor0>=0.19<1:devel/rubygem-thor0

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/gemdiff

.include <bsd.port.mk>
