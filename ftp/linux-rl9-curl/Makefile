PORTNAME=	curl
DISTVERSION=	7.76.1
DISTVERSIONSUFFIX=	-31.el9_6.1
PORTREVISION=	11
CATEGORIES=	ftp linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Tool for transferring files with URL syntax (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://curl.se/

LICENSE=	MIT

USES=		cpe linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	libnghttp2 libssh nspr nss openldap
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
