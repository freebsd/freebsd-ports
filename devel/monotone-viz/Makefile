# New ports collection makefile for:   monotone-viz
# Date created:        2 July 2006
# Whom:            Tarasov Alexey <master@preved.cn>
#
# $FreeBSD$
#

PORTNAME=	monotone-viz
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://oandrieu.nerim.net/monotone-viz/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Visual interface for Monotone VCS with revision graphs

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		dot:${PORTSDIR}/graphics/graphviz \
		mtn:${PORTSDIR}/devel/monotone \
		sqlite3:${PORTSDIR}/databases/sqlite3

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_GNOME=	gtk20 libgnomecanvas

ALL_TARGET=

PLIST_FILES=	bin/monotone-viz

.include <bsd.port.mk>

