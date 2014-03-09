# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	ldraw
PORTVERSION=	201302
PORTEPOCH=	1
CATEGORIES=	cad
MASTER_SITES=	http://www.ldraw.org/library/updates/
DISTNAME=	complete
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	LDraw parts library

LICENSE=	CDDL CCbyNCSA2
LICENSE_COMB=	dual
LICENSE_NAME_CCbyNCSA2=Attribution-NonCommercial-ShareAlike 2.0 Unported
LICENSE_FILE_CCbyNCSA2=${WRKSRC}/CAlicense.txt
LICENSE_PERMS_CCbyNCSA2=dist-mirror pkg-mirror auto-accept

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		dos2unix gmake zip:infozip
DOS2UNIX_GLOB=	*.h makefile mklist.c *.txt *.dat

PORTDOCS=	Readme.txt

OPTIONS_DEFINE=	DOCS

SUB_FILES=	pkg-message

post-extract-script:
	@(cd ${WRKSRC} && ${UNZIP_CMD} -qo -d ${WRKSRC}/mklist ${WRKSRC}/mklist1_6.zip)
	@(cd ${WRKSRC}/mklist/include && ${MV} * ..)

post-patch:
	@${REINPLACE_CMD} -e 's|CC=gcc|CC?=gcc|' \
		-e 's|CFLAGS=|CFLAGS?=|' \
		${WRKSRC}/mklist/makefile
	@${REINPLACE_CMD} -e 's|PARTS|parts|' \
		${WRKSRC}/mklist/mklist.c

do-build:
	@(cd ${WRKSRC}/mklist ; ${GMAKE} ${MAKE_ENV})

do-install:
.for f in models p parts LDCfgalt.ldr LDConfig.ldr LDConfig_TLG.ldr
	@(cd ${WRKSRC} ; ${COPYTREE_SHARE} ${f} ${STAGEDIR}${DATADIR})
.endfor

	${INSTALL_PROGRAM} ${WRKSRC}/mklist/mklist ${STAGEDIR}${DATADIR}
	@(cd ${STAGEDIR}${DATADIR} ; ./mklist -d)

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

	@cd ${STAGEDIR}${PREFIX} && ${FIND} ${DATADIR_REL}\
		-type f >> ${TMPPLIST} && \
		${FIND} ${DATADIR_REL} -type d -o -type l | ${SORT} -r | \
		${SED} 's|^|@dirrm |' >> ${TMPPLIST}

.include <bsd.port.mk>
