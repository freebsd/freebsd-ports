PORTNAME=	kividb
PORTVERSION=	1.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	databases

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Fast, multi-threaded Redis and Valkey
WWW=		https://kividb.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	armv7 i386
NOT_FOR_ARCHS_REASON=	build currently failing

USES=		cargo cpe
CPE_VENDOR=	kividb
CPE_PRODUCT=	kividb

USE_GITHUB=	yes
GH_ACCOUNT=	kividbio
GH_PROJECT=	kividb

.include "${.CURDIR}/Makefile.crates"

PLIST_FILES=	bin/kividb

.include <bsd.port.mk>
