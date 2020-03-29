# $FreeBSD$

PORTNAME=	netgen
DISTVERSION=	1.5.146
CATEGORIES=	cad
PKGNAMESUFFIX=	-lvs

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tool for comparing netlists (a process known as LVS)

LICENSE=	GPLv1
LICENSE_FILE=	${WRKSRC}/Copying

RUN_DEPENDS=	bash:shells/bash

USES=		gmake python:3.6+ shebangfix tar:tgz tcl tk xorg
USE_GITHUB=	yes
GH_ACCOUNT=	RTimothyEdwards
SHEBANG_FILES=	tcltk/netgen.sh.in
USE_XORG=	x11

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	HAVE_PYTHON3=yes
CONFIGURE_ARGS=	--with-interpreter=tcl --with-tcl=${LOCALBASE}/lib/tcl8.6 --with-tk=${LOCALBASE}/lib/tk8.6 --with-x

post-patch:
	@${REINPLACE_CMD} -e 's|^#!/bin/env python3$$|#!${PYTHON_CMD}|' ${WRKSRC}/python/*.py

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/netgen/tcl/netgenexec ${STAGEDIR}${PREFIX}/lib/netgen/tcl/tclnetgen.so

.include <bsd.port.mk>
