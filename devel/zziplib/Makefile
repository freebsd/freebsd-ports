# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=	zziplib
PORTVERSION=	0.13.62
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}13/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library to provide transparent read access to zipped files

LICENSE=	LGPL21 MPL
LICENSE_COMB=	dual

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip

USES=		tar:bzip2 pathfix pkgconfig gmake libtool
USE_PYTHON_BUILD=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_XMLTO=":"
USE_LDCONFIG=	yes

PORTSCOUT=	limit:^0\.

OPTIONS_DEFINE=	SDL
OPTIONS_SUB=	yes

SDL_USE=		SDL=sdl
SDL_CONFIGURE_ENABLE=	sdl

.include <bsd.port.pre.mk>

test check:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} check)

.if !defined(WITHOUT_TESTS)
post-build::	test
.endif

post-install:
.for lib in zzip zzipmmapped zzipfseeko zzipwrap
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib${lib}.so
.endfor

.include <bsd.port.post.mk>
