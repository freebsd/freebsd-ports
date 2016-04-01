# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=	zziplib
PORTVERSION=	0.13.62
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}13/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library to provide transparent read access to zipped files

LICENSE=	LGPL21 MPL
LICENSE_COMB=	dual

BUILD_DEPENDS=	zip:archivers/zip

USES=		gmake libtool pathfix pkgconfig python:2,build tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_XMLTO=":"
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

PORTSCOUT=	limit:^0\.

OPTIONS_DEFINE=	SDL
OPTIONS_SUB=	yes

SDL_USE=		SDL=sdl
SDL_CONFIGURE_ENABLE=	sdl

regression-test:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} check)

.include <bsd.port.mk>
