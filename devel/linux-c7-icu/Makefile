# Created by: David Naylor <dbn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	icu
PORTVERSION=	50.2
DISTVERSIONSUFFIX=	-4.el7_7
PORTREVISION=	1
CATEGORIES=	devel linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	International Components for Unicode (Linux CentOS ${LINUX_DIST_VER})

USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

LIB_DISTNAMES=	lib${PORTNAME}-${DISTVERSIONFULL}

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/lib${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
