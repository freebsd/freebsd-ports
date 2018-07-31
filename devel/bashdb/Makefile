# $FreeBSD$

PORTNAME=	bashdb
DISTVERSION=	4.4-0.94
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Source-code debugger for bash

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	bash:shells/bash

USES=		gmake python shebangfix
SHEBANG_GLOB=	*.py
GNU_CONFIGURE=	yes
NO_BUILD=	yes
NO_ARCH=	yes

INFO=	bashdb

post-install:
	@${REINPLACE_CMD} -i '' 's|#!/bin/bash|#!${LOCALBASE}/bin/bash|' \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
