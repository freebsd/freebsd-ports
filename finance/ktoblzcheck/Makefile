# New ports collection makefile for:    ktoblzcheck
# Date created:         25 November 2003
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ktoblzcheck
PORTVERSION=	1.29
CATEGORIES=	finance german
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	Check bank codes of German banks

USE_GNOME=	gnomehack pkgconfig
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		ktoblzcheck.1

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS=	PYTHON "Install Python bindings" off

.include <bsd.port.options.mk>

.if defined(WITH_PYTHON)
USE_PYTHON=	yes
PLIST_SUB+=	WITH_PYTHON=""
.else
CONFIGURE_ARGS+=--disable-python
PLIST_SUB+=	WITH_PYTHON="@comment "
.endif

.include <bsd.port.mk>
