# New ports collection makefile for:	gtksql
# Version required:			0.2
# Date created:				19 November 1998
# Whom:					Andrey Zakhvatov
#
# $Id$
#

DISTNAME=	gtksql-0.2
CATEGORIES=	databases
MASTER_SITES=	http://www.multimania.com/bbrox/GtkSQL/

MAINTAINER=	andy@icc.surw.chel.su

LIB_DEPENDS=	gtk10.1:${PORTSDIR}/x11-toolkits/gtk10 \
		pq.2:${PORTSDIR}/databases/postgresql

USE_X_PREFIX=	yes

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/gtksql ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/gtksql
.for file in COPYING Changelog README
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/gtksql
.endfor
.endif

.include <bsd.port.mk>
