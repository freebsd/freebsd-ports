# Created by: Romain Tartiere <romain@blogreen.org>
# $FreeBSD$

PORTNAME=	tomboy-plugin-todo
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://romain.blogreen.org/distfiles/
DISTNAME=	tomboy-todo-${PORTVERSION}

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Highlight FIXME, TODO, and XXX in your notes

BUILD_DEPENDS=	tomboy:deskutils/tomboy
RUN_DEPENDS=	tomboy:deskutils/tomboy

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_GMCS=${LOCALBASE}/bin/mcs
USES=		gmake pkgconfig

.include <bsd.port.mk>
