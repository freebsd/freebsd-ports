# New ports collection makefile for:	konversation
# Date created:				15 May 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	konversation
PORTVERSION=	0.11
CATEGORIES=	irc kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ponomarew@oberon.net
COMMENT=	A user friendly IRC client for KDE

USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes

CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
