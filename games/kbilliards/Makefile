# New ports collection makefile for:	kbilliards
# Date created:				15 May 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$

PORTNAME=	kbilliards
PORTVERSION=	0.4.b
PORTREVISION=	1
CATEGORIES=	games kde
MASTER_SITES=	http://members.xoom.virgilio.it/samuele_c/kbilliards/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/b/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Funny billiards simulator game for KDE

USE_KDELIBS_VER=	3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

.include <bsd.port.mk>
