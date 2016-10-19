# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	jasper
PORTVERSION=	1.900.1
CATEGORIES=	graphics linux
LIB_DISTFILES=	${PORTNAME}-libs-${PORTVERSION}-${RPMVERSION}${EXTRACT_SUFX}
SRC_DISTFILES=	${DISTNAME}${SRC_SUFX}:SOURCE

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	JPEG-2000 reference implementation (Linux CentOS ${LINUX_DIST_VER})

RPMVERSION=	29.el7
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	jpeg
USE_LINUX_RPM=	yes

DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}-libs-${PORTVERSION}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
