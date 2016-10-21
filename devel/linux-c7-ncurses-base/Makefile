# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	ncurses-base
PORTVERSION=	5.9
CATEGORIES=	devel linux
SRC_DISTFILES=	ncurses-${PORTVERSION}-${RPMVERSION}${SRC_SUFX}:SOURCE

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Terminfo database required by Linux ncurses programs

CONFLICTS=	linux-f10-${PORTNAME}-[0-9]* linux-c6-${PORTNAME}-[0-9]*

RPMVERSION=	13.20130511.el7
USES=		linux:c7
USE_LINUX_RPM=	noarch

DESCR=		${.CURDIR}/../ncurses/pkg-descr

.include <bsd.port.mk>
