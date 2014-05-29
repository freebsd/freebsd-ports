# Created by: Tarasov Alexey <master@preved.cn>
# $FreeBSD$

PORTNAME=	monotone-viz
PORTVERSION=	1.0.2
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://oandrieu.nerim.net/monotone-viz/

MAINTAINER=	lapo@lapo.it
COMMENT=	Visual interface for Monotone VCS with revision graphs

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lablgtk2:${PORTSDIR}/x11-toolkits/ocaml-lablgtk2
RUN_DEPENDS+=	dot:${PORTSDIR}/graphics/graphviz \
		mtn:${PORTSDIR}/devel/monotone \
		lablgtk2:${PORTSDIR}/x11-toolkits/ocaml-lablgtk2

USES=		gmake
USE_OCAML=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--without-local-lablgtk

ALL_TARGET=
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/monotone-viz

NO_STAGE=	yes
.include <bsd.port.mk>
