# ex:ts=8
# Ports collection makefile for:	jpgraph
# Date created:			Oct 20, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	jpgraph
PORTVERSION=	1.10.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.aditus.nu/jpgraph/downloads/

MAINTAINER=	ports@FreeBSD.org

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
	${INSTALL_DATA} ${WRKSRC}/src/*.php ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/src/Examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
