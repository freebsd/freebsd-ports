# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	ncurses
PORTVERSION=	5.9
PORTREVISION=	2
CATEGORIES=	devel linux
PKGNAMESUFFIX=	-base
SHARE_DISTNAMES=${LINUXNAME}-${DISTVERSIONFULL}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Terminfo database required by Linux ncurses programs

CONFLICTS=	linux-c6-${PORTNAME}-[0-9]*

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${LINUXNAME}-${PORTVERSION}
LINUXNAME=	${PORTNAME}${PKGNAMESUFFIX}
RPMVERSION=	14.20130511.el7_4
USES=		linux:c7
USE_LINUX_RPM=	noarch

.include <bsd.port.mk>
