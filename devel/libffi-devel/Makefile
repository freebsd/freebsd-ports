# New ports collection makefile for:	libffi
# Date created:			14, June, 1998
# Whom:				Horance Chou <horance@freedom.ie.cycu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	libffi
PORTVERSION=	1.20
CATEGORIES=	devel
MASTER_SITES=	ftp://sources.redhat.com/pub/libffi/

MAINTAINER=	horance@freera.net
COMMENT=	Foreign Function Interface

USE_INC_LIBTOOL_VER=	13
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=	# empty

CONFLICTS=	gcc-3*

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386" && ${ARCH} != "alpha"
BROKEN=		"Configure fails on !i386 and !alpha"
.endif

.include <bsd.port.post.mk>
