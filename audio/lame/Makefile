# ports collection makefile for:   lame
# Date created:        11 January 1998
# Whom:                yoshiaki Uchikawa
#
# $FreeBSD$
#

PORTNAME=	lame
PORTVERSION=	3.91
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://lame.sourceforge.net/pub/
MASTER_SITE_SUBDIR=	lame

MAINTAINER=	yoshiaki@kt.rim.or.jp

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_GTK=	yes
CONFIGURE_ARGS=	--enable-nasm

MAN1=		lame.1

.include <bsd.port.mk>
