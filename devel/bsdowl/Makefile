# Created by: Michael Le Barbier GrÃ¼newald <michipili@gmail.com>
# $FreeBSD$

PORTNAME=	bsdowl
PORTVERSION=	2.2.1
CATEGORIES=	devel
MASTER_SITES=	http://github.com/michipili/bsdowl/releases/download/v${PORTVERSION}/

MAINTAINER=	michipili@gmail.com
COMMENT=	BSD Make macros for TeX, OCaml, noweb and more

LICENSE=	CeCILL-Bv1
LICENSE_NAME=	CeCILL B, Version 1.0
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	gm:${PORTSDIR}/graphics/GraphicsMagick
BUILD_DEPENDS=	gm:${PORTSDIR}/graphics/GraphicsMagick

USES=		tar:xz uidfix

HAS_CONFIGURE=	yes
MAKE_ENV+=	MAKEFLAGS=-r

.include <bsd.port.mk>
