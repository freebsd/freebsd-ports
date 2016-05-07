# Created by: Max Khon <fjoe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cint
PORTVERSION=	5.18.00
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	http://root.cern.ch/drupal/sites/default/files/

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	C/C++ interpreter

BROKEN_powerpc64=	Does not build

BUILD_DEPENDS=	bash:shells/bash

EXTRACT_SUFX=	.tgz
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	CC="${CC}" CXX="${CXX}" LDFLAGS="${LDFLAGS}"
USE_GCC=	yes
USES=		gmake readline
USE_LDCONFIG=	${PREFIX}/lib/cint
ALL_TARGET=

INSTALL_ARGS=	--bindir=${STAGEDIR}${PREFIX}/bin\
		--libdir=${STAGEDIR}${PREFIX}/lib/cint\
		--mandir=${STAGEDIR}${PREFIX}/man\
		--docdir=${STAGEDIR}${DOCSDIR}

post-patch:
	${REINPLACE_CMD} 's,#!/bin/bash,#!${LOCALBASE}/bin/bash,' ${WRKSRC}/cint/lib/dll_stl/setup
	${REINPLACE_CMD} 's,make ,${GMAKE} ,' ${WRKSRC}/cint/lib/*/setup

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${LOCALBASE}/bin/bash configure __have_the_proper_shell@

do-install:
	cd ${WRKSRC} && ${LOCALBASE}/bin/bash tool/INSTALLBIN ${INSTALL_ARGS}

.include <bsd.port.mk>
