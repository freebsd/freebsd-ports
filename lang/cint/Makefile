# Created by: Max Khon <fjoe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cint
PORTVERSION=	5.18.00
PORTREVISION=	11
CATEGORIES=	lang
MASTER_SITES=	http://root.cern.ch/drupal/sites/default/files/

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	C/C++ interpreter

BROKEN_powerpc64=	does not build: cint/include/iosenum.h: segmentation fault (core dumped)

BUILD_DEPENDS=	bash:shells/bash

HAS_CONFIGURE=	yes
CONFIGURE_ENV=	CC="${CC}" CXX="${CXX}" LDFLAGS="${LDFLAGS}" \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}"
USE_GCC=	yes
USES=		gmake readline tar:tgz
USE_LDCONFIG=	${PREFIX}/lib/cint
ALL_TARGET=

# The port does not build with C++11/C++14, so explicitly use an older
# standard.
USE_CXXSTD=	gnu++98

INSTALL_ARGS=	--bindir=${STAGEDIR}${PREFIX}/bin\
		--libdir=${STAGEDIR}${PREFIX}/lib/cint\
		--mandir=${STAGEDIR}${PREFIX}/man\
		--docdir=${STAGEDIR}${DOCSDIR}

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} 's,#!/bin/bash,#!${LOCALBASE}/bin/bash,' ${WRKSRC}/cint/lib/dll_stl/setup
	${REINPLACE_CMD} 's,make ,${GMAKE} ,' ${WRKSRC}/cint/lib/*/setup

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${LOCALBASE}/bin/bash configure __have_the_proper_shell@

do-install:
	cd ${WRKSRC} && ${LOCALBASE}/bin/bash tool/INSTALLBIN ${INSTALL_ARGS}

.include <bsd.port.mk>
