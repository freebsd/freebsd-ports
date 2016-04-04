# Created by: Will Andrews <andrews@technologist.com>
# $FreeBSD$

PORTNAME=	makeself
PORTVERSION=	2.2.0
CATEGORIES=	archivers
MASTER_SITES=	http://cdn.megastep.org/makeself/
EXTRACT_SUFX=	.run

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Neat script to make self-extracting archives

RUN_DEPENDS=	bash:shells/bash

EXTRACT_CMD=	${SH}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	--nox11 --target ${WRKSRC}

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/makeself bin/makeself-header \
		bin/makeself-header.sh bin/makeself.sh

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|#!/bin/sh|#!${LOCALBASE}/bin/bash|g' ${WRKSRC}/makeself.sh

do-install:
.for i in makeself makeself-header
	${INSTALL_SCRIPT} ${WRKSRC}/${i}.sh ${STAGEDIR}${PREFIX}/bin
	@${LN} -sf ${i}.sh ${STAGEDIR}${PREFIX}/bin/${i}
.endfor

.include <bsd.port.mk>
