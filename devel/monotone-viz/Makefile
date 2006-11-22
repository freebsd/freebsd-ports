# New ports collection makefile for:   monotone-viz
# Date created:        2 July 2006
# Whom:            Tarasov Alexey <master@preved.cn>
#
# $FreeBSD$
#

PORTNAME=	monotone-viz
PORTVERSION=	0.15
CATEGORIES=	devel
MASTER_SITES=	http://oandrieu.nerim.net/monotone-viz/

MAINTAINER=	master@preved.cn
COMMENT=	Visual interface for Monotone VCS with revision graphs

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
   		lablgtk2:${PORTSDIR}/x11-toolkits/ocaml-lablgtk2 \
		dot:${PORTSDIR}/graphics/graphviz \
		mtn:${PORTSDIR}/devel/monotone \
		sqlite3:${PORTSDIR}/databases/sqlite3

GNU_CONFIGURE=	YES
USE_GMAKE=	YES

ALL_TARGET=

.include <bsd.port.mk>
