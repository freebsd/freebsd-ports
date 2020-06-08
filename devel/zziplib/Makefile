# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=	zziplib
DISTVERSIONPREFIX=	v
PORTVERSION=	0.13.71
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library to provide transparent read access to zipped files

LICENSE=	LGPL21 MPL11
LICENSE_COMB=	dual
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LIB
LICENSE_FILE_MPL11=	${WRKSRC}/docs/COPYING.MPL

BUILD_DEPENDS=	gsed:textproc/gsed \
		zip:archivers/zip

USES=		libtool pathfix pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	gdraheim

CONFIGURE_ARGS=	--srcdir=${WRKSRC}
CONFIGURE_ENV=	ac_cv_path_XMLTO=":"
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USE_LDCONFIG=	yes

PORTSCOUT=	limit:^0\.

OPTIONS_DEFINE=	SDL
OPTIONS_SUB=	yes

SDL_CONFIGURE_ENABLE=	sdl
SDL_USE=		SDL=sdl
SDL_USES=		sdl

.include <bsd.port.mk>
