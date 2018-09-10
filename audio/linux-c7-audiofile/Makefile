# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	audiofile
PORTVERSION=	0.3.6
PORTREVISION=	1
CATEGORIES=	audio linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Implementation of the Audio File Library (Linux CentOS ${LINUX_DIST_VER})

CONTFLICTS=	linux-c6-${PORTNAME}-[0-9]*

DESCR=		${.CURDIR}/../lib${PORTNAME}/pkg-descr
RPMVERSION=	4.el7
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
