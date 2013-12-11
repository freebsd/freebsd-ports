# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=	zziplib
PORTVERSION=	0.13.62
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}13/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library to provide transparent read access to zipped files

LICENSE=	LGPL21 MPL
LICENSE_COMB=	dual

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip

OPTIONS_DEFINE=	SDL

USE_BZIP2=	yes
USES=		pathfix pkgconfig gmake
USE_PYTHON_BUILD=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ENV=	ac_cv_path_XMLTO=":"
USE_LDCONFIG=	yes

PORTSCOUT=	limit:^0\.

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSDL}
USE_SDL=	sdl
CONFIGURE_ARGS+=--enable-sdl
PLIST_SUB+=	SDL=""
.else
PLIST_SUB+=	SDL="@comment "
.endif

.include <bsd.port.pre.mk>

test check:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} check)

.if !defined(WITHOUT_TESTS)
post-build::	test
.endif

.include <bsd.port.post.mk>
