# New ports collection makefile for:	mpc
# Date created:		Oct 02 2003
# Whom:			Mark Reidel <ports@mark.reidle.info>
#
# $FreeBSD$
#

PORTNAME=	mpc
PORTVERSION=	0.10.0
CATEGORIES=	audio ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	musicpd

MAINTAINER=	ports@mark.reidel.info
COMMENT=	Command line client for the musicpd

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \

CFLAGS+=	-I${PREFIX}/include

MAN1=		mpc.1

.include <bsd.port.mk>
