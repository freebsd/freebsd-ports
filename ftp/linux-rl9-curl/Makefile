PORTNAME=	curl
DISTVERSION=	7.76.1
DISTVERSIONSUFFIX=	-31.el9
PORTREVISION=	7
CATEGORIES=	ftp linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Tool for transferring files with URL syntax (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://curl.se/

LICENSE=	MIT

USES=		cpe linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	libidn2 libnghttp2 libpsl libssh libxcrypt nspr nss openldap
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

CPE_VENDOR=	haxx

BIN_DISTNAMES=	${PORTNAME}-${DISTVERSIONFULL}
LIB_DISTNAMES=	lib${PORTNAME}-${DISTVERSIONFULL}

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
