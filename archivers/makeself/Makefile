# New ports collection makefile for:	makeself
# Date created:		22 Oct 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	makeself
PORTVERSION=	2.1.4
CATEGORIES=	archivers
MASTER_SITES=	http://www.megastep.org/makeself/
EXTRACT_SUFX=	.run

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A neat script to make self-extracting archives

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

EXTRACT_CMD=	${SH}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	--nox11 --target ${WRKSRC}

NO_BUILD=	yes
USE_REINPLACE=	yes

PLIST_FILES=	bin/makeself bin/makeself-header \
		bin/makeself-header.sh bin/makeself.sh

.if !defined(NOPORTDOCS)
PORTDOCS=	README
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|#!/bin/sh|#!${LOCALBASE}/bin/bash|g' ${WRKSRC}/makeself.sh

do-install:
.for i in makeself makeself-header
	${INSTALL_SCRIPT} ${WRKSRC}/${i}.sh ${PREFIX}/bin
	@${LN} -sf ${i}.sh ${PREFIX}/bin/${i}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
