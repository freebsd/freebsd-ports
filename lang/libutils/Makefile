# ex:ts=8
# Ports collection makefile for:	libutils
# Date created:			May 6, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libutils
PORTVERSION=	1.0.3
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	http://savannah.gnu.org/download/nsl/ \
		http://iling.nw.ru/~artem/downloads/ \
		http://unixpages.org/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Support lib for Tensile/NSL

USE_GMAKE=	yes
USE_LIBTOOL_VER=15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
MAKE_ARGS=	CFLAGS="${CFLAGS}"
INSTALLS_SHLIB=	yes

MAN3=		libutils.3

.include <bsd.port.mk>
