PORTNAME=	ldraw
DISTVERSION=	20260831
PORTEPOCH=	1
CATEGORIES=	cad
MASTER_SITES=	https://library.ldraw.org/library/updates/
DISTNAME=	complete
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LDraw-format CAD files representing many of LEGO bricks produced
WWW=		https://www.ldraw.org/

LICENSE=	CC-BY-2.0
LICENSE_FILE=	${WRKSRC}/CAlicense.txt

USES=		zip

NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} 'LDConfig.ldr p parts' ${STAGEDIR}${DATADIR}

post-install: # autoplist: ~37k files all under share/ldraw
	@cd ${STAGEDIR}${PREFIX} && ${FIND} * -type f >> ${TMPPLIST}

.include <bsd.port.mk>
