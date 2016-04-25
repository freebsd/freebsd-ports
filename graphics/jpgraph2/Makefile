# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jpgraph
PORTVERSION=	3.0.7
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://hem.bredband.net/jpgraph2/
PKGNAMESUFFIX=	2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Draw both "quick and dirty" graphs with a minimum of code

LICENSE=	jpgraph
LICENSE_NAME=	JpGraph license
LICENSE_FILE=	${WRKSRC}/README
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

BROKEN_powerpc64=	Does not build

USES=		tar:bzip2
NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_PHP=	gd

NO_CDROM=	The free version cannot be used in a commercial context

PORTDATA=	*
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} ${WRKSRC}/src/*.php ${STAGEDIR}${DATADIR}
	${CP} ${WRKSRC}/src/*.dat ${STAGEDIR}${DATADIR}
	${CP} -R ${WRKSRC}/src/lang ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -R ${WRKSRC}/docportal/* ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} ${WRKSRC}/src/Examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
