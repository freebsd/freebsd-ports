PORTNAME=	libunistring
PORTVERSION=	0.9.10
DISTVERSIONSUFFIX=	-15.el9
CATEGORIES=	devel linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Unicode string library (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://www.gnu.org/software/libunistring/

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
