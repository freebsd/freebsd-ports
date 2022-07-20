PORTNAME=	tnt
PORTVERSION=	1.2.6
CATEGORIES=	devel math
MASTER_SITES=	http://math.nist.gov/tnt/
DISTNAME=	${PORTNAME}_126
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} tnt120doc.zip
DIST_SUBDIR=	tnt
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	erik@bz.bzflag.bz
COMMENT=	Template Numerical Toolkit

USES=		zip:infozip
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/tnt
	${INSTALL_DATA} ${WRKDIR}/*.h ${STAGEDIR}${PREFIX}/include/tnt
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${UNZIP_CMD} ${DISTDIR}/${DIST_SUBDIR}/tnt120doc.zip \
		-d ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
