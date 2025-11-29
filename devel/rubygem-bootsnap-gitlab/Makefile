PORTNAME=	bootsnap
PORTVERSION=	1.18.6
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Boot large ruby/rails apps faster
WWW=		https://github.com/rails/bootsnap

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-msgpack>=1.2<2:devel/rubygem-msgpack

USES=		gem

PLIST_FILES=	bin/bootsnap

PORTSCOUT=	limit:^1\.18\.

.include <bsd.port.mk>
