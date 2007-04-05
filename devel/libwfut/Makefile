# New ports collection makefile for:	libwfut
# Date created:				4th April 2007
# Whom:					Oliver Lehmann
#
# $FreeBSD$
#

PORTNAME=	libwfut
PORTVERSION=	0.1.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	worldforge

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	WorldForge update library

LIB_DEPENDS=	sigc-2.0:${PORTSDIR}/devel/libsigc++20 \
		curl.4:${PORTSDIR}/ftp/curl

GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes
MAN1=		wfut.1

.include <bsd.port.mk>
