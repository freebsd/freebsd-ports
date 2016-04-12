# Created by: Martin Sugioarto <martin.sugioarto@udo.edu>
# $FreeBSD$

PORTNAME=	iiview
PORTVERSION=	0.31
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	martin.sugioarto@udo.edu
COMMENT=	Thumb viewer application

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libpng.a:graphics/png \
		${LOCALBASE}/lib/libtiff.a:graphics/tiff

USES=		jpeg:build
USE_XORG=	xpm x11

USE_GITHUB=	yes
GH_ACCOUNT=	nakal
WRKSRC=		${WRKDIR}/iiview-${PORTVERSION}

PLIST_FILES=	bin/iiview man/man1/iiview.1.gz

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
