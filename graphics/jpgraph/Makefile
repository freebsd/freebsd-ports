# ex:ts=8
# Ports collection makefile for:	jpgraph
# Date created:			Oct 20, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	jpgraph
PORTVERSION=	1.12.2
CATEGORIES=	graphics
MASTER_SITES=	http://www.aditus.nu/jpgraph/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Draw both "quick and dirty" graphs with a minimum of code

NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if !exists(${LOCALBASE}/bin/php) && !exists(${LOCALBASE}/libexec/apache/libphp4.so)
BROKEN=	"need PHP 4.04 or above"
.endif

.if !exists(${LOCALBASE}/lib/libgd.a)
BROKEN=	"PHP have to build with GD support"
.endif

do-install:
	@${MKDIR} ${DATADIR}
	${CP} ${WRKSRC}/src/*.php ${DATADIR}
	${CP} ${WRKSRC}/src/*.inc ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/ ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/src/Examples/ ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
