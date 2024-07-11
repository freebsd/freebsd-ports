PORTNAME=	curl
PORTVERSION=	7.76.1
DISTVERSIONSUFFIX=	-29.el9_4
PORTREVISION=	5
CATEGORIES=	ftp linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Tool for transferring files with URL syntax (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://curl.se/

LICENSE=	MIT

USES=		cpe linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	libidn2 libnghttp2 libpsl libxcrypt nspr nss openldap
USE_LINUX_RPM=	nolib

CPE_VENDOR=	haxx

LIB_DISTNAMES=	lib${DISTNAME}

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
