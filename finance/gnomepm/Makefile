# Ports collection Makefile for:	gnomepm
# Date created:				16 July 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomepm
PORTVERSION=	0.9.3
PORTREVISION=	2
CATEGORIES=	finance gnome
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/g/${PORTNAME:S/gnome/gnome-/}
DISTNAME=	${PORTNAME:S/gnome/gnome-/}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A small GNOME app that collects stock information from Yahoo!(c) Finance

LIB_DEPENDS=	ghttp.1:${PORTSDIR}/www/libghttp

WRKSRC=		${WRKDIR}/${PORTNAME:S/gnome/gnome-/}-${PORTVERSION}

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomelibs gnomeprefix
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
