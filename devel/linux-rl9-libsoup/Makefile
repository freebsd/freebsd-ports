PORTNAME=	libsoup
PORTVERSION=	2.72.0
DISTVERSIONSUFFIX=	-8.el9
CATEGORIES=	devel linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	SOAP (Simple Object Access Protocol) implementation in C (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://libsoup.org/

LICENSE=	LGPL20

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	libgcrypt libpsl
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
