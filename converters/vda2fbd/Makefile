# New ports collection makefile for:	vda2fbd
# Date created:		19 April 2003
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	vda2fbd
PORTVERSION=	1.0
CATEGORIES=	converters cad
MASTER_SITES=	http://www.dhondt.de/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An add-on converter for CalculiX

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" YACC="${YACC}"

PORTDOCS=	model.ps.gz
PLIST_FILES=	bin/vda2fbd

post-build:
	cd ${WRKSRC}/../doc && ${GZIP_CMD} -c model.ps > model.ps.gz

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vda2fbd ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/model.ps.gz ${DOCSDIR}
.endif

.include <bsd.port.mk>
