# New ports collection makefile for:   monotone-viz
# Date created:        2 July 2006
# Whom:            Tarasov Alexey <master@preved.cn>
#
# $FreeBSD$
#

PORTNAME=	monotone-viz
PORTVERSION=	1.0.2
CATEGORIES=	devel
MASTER_SITES=	http://oandrieu.nerim.net/monotone-viz/

MAINTAINER=	lapo@lapo.it
COMMENT=	Visual interface for Monotone VCS with revision graphs

# BUILD_DEPENDS=	lablgtk2:${PORTSDIR}/x11-toolkits/ocaml-lablgtk2
RUN_DEPENDS+=	dot:${PORTSDIR}/graphics/graphviz \
		mtn:${PORTSDIR}/devel/monotone
# 		lablgtk2:${PORTSDIR}/x11-toolkits/ocaml-lablgtk2

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		Doesn't build with Glib-2.26

USE_GMAKE=	yes
USE_OCAML=	yes
GNU_CONFIGURE=	yes
# following line can (and should) be used only after ports/149958 is closed
#CONFIGURE_ARGS+=	--without-local-lablgtk
# Remove USE_GNOME and enable dependency on lablgtk2 when ports/149958 is fixed
USE_GNOME=	gtk20 libgnomecanvas

ALL_TARGET=
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/monotone-viz

.include <bsd.port.mk>
