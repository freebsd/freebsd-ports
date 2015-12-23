# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	${LINUX_NAME}-base
PORTVERSION=	5.7
PORTREVISION=	1
CATEGORIES=	devel linux

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Terminfo database required by Linux ncurses programs

USE_LINUX=	c6
USE_LINUX_RPM=	yes
LINUX_NAME=	ncurses

RPMVERSION=	3.20090208.el6
SRC_DISTFILES=	${LINUX_NAME}-${PORTVERSION}-${RPMVERSION}${SRC_SUFX}:SOURCE
DESCR=	${.CURDIR}/../${LINUX_NAME}/pkg-descr

.include <bsd.port.mk>
