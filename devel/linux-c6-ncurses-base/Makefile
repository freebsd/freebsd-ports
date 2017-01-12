# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	${LINUX_NAME}-base
PORTVERSION=	5.7
PORTREVISION=	3
CATEGORIES=	devel linux

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Terminfo database required by Linux ncurses programs

LINUX_NAME=	ncurses
RPMVERSION=	4.20090207.el6
USES=		linux:c6
USE_LINUX_RPM=	nolib

SRC_DISTFILES=	${LINUX_NAME}-${PORTVERSION}-${RPMVERSION}${SRC_SUFX}:SOURCE
DESCR=		${.CURDIR}/../${LINUX_NAME}/pkg-descr

.include <bsd.port.mk>
