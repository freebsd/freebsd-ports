PORTNAME=	curl
PORTVERSION=	7.29.0
DISTVERSIONSUFFIX=	-59.el7_9.2
PORTREVISION=	13
CATEGORIES=	ftp linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Tool for transferring files with URL syntax (Linux CentOS ${LINUX_DIST_VER})
WWW=		https://curl.se/

LICENSE=	MIT

USES=		cpe linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	libssh2 nspr nss openldap
USE_LINUX_RPM=	nolib

CPE_VENDOR=	haxx

DISTFILES_i386=	${LIB_DISTNAMES:S/$/${EXTRACT_SUFX_i386}:amd64,i386/} \
		${PORTNAME}-${DISTVERSION}-59.el7_9.1${EXTRACT_SUFX_i386}:i386
LIB_DISTNAMES=	lib${DISTNAME}

CONFLICTS=	linux-c6-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
