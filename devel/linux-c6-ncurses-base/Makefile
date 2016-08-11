# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	${LINUX_NAME}-base
PORTVERSION=	5.7
PORTREVISION=	2
CATEGORIES=	devel linux

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Terminfo database required by Linux ncurses programs

USE_LINUX=	c6
USE_LINUX_RPM=	nolib
LINUX_NAME=	ncurses

RPMVERSION=	4.20090207.el6
SRC_DISTFILES=	${LINUX_NAME}-${PORTVERSION}-${RPMVERSION}${SRC_SUFX}:SOURCE
DESCR=	${.CURDIR}/../${LINUX_NAME}/pkg-descr

.include <bsd.port.mk>
