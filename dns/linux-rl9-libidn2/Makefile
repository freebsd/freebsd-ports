PORTNAME=	libidn2
PORTVERSION=	2.3.0
DISTVERSIONSUFFIX=	-7.el9
CATEGORIES=	dns devel linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Implementation of IDNA2008 internationalized domain names (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://www.gnu.org/software/libidn/\#libidn2 \
		https://gitlab.com/libidn/libidn2

LICENSE=	GPLv3

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	libunistring
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
