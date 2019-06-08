# Created by: David Naylor <dbn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	icu
PORTVERSION=	50.1.2
PORTREVISION=	1
CATEGORIES=	devel linux
LIB_DISTNAMES=	${LINUXNAME}-${DISTVERSIONFULL}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	International Components for Unicode (Linux CentOS ${LINUX_DIST_VER})

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${LINUXNAME}-${PORTVERSION}
LINUXNAME=	lib${PORTNAME}
RPMVERSION=	17.el7
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
