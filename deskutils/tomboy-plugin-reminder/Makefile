# Created by: Romain Tartiere <romain@blogreen.org>
# $FreeBSD$

PORTNAME=	tomboy-plugin-reminder
PORTVERSION=	0.9.2
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://flukkost.nu/
DISTNAME=	tomboy-reminder-${PORTVERSION}

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Automatically open notes at a given date and time

BUILD_DEPENDS=	tomboy:deskutils/tomboy
RUN_DEPENDS=	tomboy:deskutils/tomboy

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_GMCS=${LOCALBASE}/bin/mcs
MAKE_ARGS=	CSC="${LOCALBASE}/bin/mcs -debug"
USES=		gmake pkgconfig

.include <bsd.port.mk>
