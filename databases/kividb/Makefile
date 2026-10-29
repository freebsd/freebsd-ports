PORTNAME=	kividb
PORTVERSION=	1.1.2
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	databases

PATCH_SITES=	https://github.com/kividbio/kividb/commit/
PATCHFILES=	bda8603b065a8385fe05f623a10183d2069ecec5.patch:-p1

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

PLIST_FILES=	bin/kividb

.include <bsd.port.mk>
