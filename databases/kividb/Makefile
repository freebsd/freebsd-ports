PORTNAME=	kividb
DISTVERSION=	1.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	databases

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Fast, multi-threaded Redis and Valkey
WWW=		https://kividb.io/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo cpe
CPE_VENDOR=	kividb
CPE_PRODUCT=	kividb

USE_GITHUB=	yes
GH_ACCOUNT=	kividbio
GH_PROJECT=	kividb
GH_TAGNAME=	${PORTVERSION}-src

PLIST_FILES=	bin/kividb

.include <bsd.port.mk>
