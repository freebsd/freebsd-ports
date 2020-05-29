# Created by: Matthias Fechner <mfechner@FreeBSD.org>
# $FreeBSD$

PORTNAME=	faraday_middleware-aws-signers-v4
#PORTVERSION=	0.2.0.beta
DISTVERSION=	0.2.0.beta
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Faraday middleware for AWS Signature Version 4

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-aws-sdk-resources>=3.0.0:devel/rubygem-aws-sdk-resources \
		rubygem-faraday0>0.9<1.0:www/rubygem-faraday0

USES=		gem shebangfix
USE_RUBY=	yes
SHEBANG_FILES=	bin/setup

NO_ARCH=	yes

.include <bsd.port.mk>
