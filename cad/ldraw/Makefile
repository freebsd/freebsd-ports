# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	ldraw
PORTVERSION=	201301
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

USE_ZIP=	yes
USES=		gmake

PORTDOCS=	Readme.txt

OPTIONS_DEFINE=	DOCS

SUB_FILES=	pkg-message

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-extract-script:
	@(cd ${WRKSRC} && ${UNZIP_CMD} -qo -d ${WRKSRC}/mklist1_4 ${WRKSRC}/mklist1_4.zip)

post-patch:
	@${REINPLACE_CMD} -e 's|CC=gcc|CC?=gcc|' \
		-e 's|CFLAGS=|CFLAGS?=|' \
		${WRKSRC}/mklist1_4/makefile
	@${REINPLACE_CMD} -e 's|PARTS|parts|' \
		${WRKSRC}/mklist1_4/mklist.c

do-build:
	@(cd ${WRKSRC}/mklist1_4 ; ${GMAKE} ${MAKE_ENV})

do-install:
.for f in models p parts LDCfgalt.ldr LDConfig.ldr LDConfig_TLG.ldr
	@(cd ${WRKSRC} ; ${COPYTREE_SHARE} ${f} ${DATADIR})
.endfor

	${INSTALL_SCRIPT} ${WRKSRC}/mklist1_4/mklist ${DATADIR}
	@(cd ${DATADIR} ; ./mklist -n)

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

	@${FIND} ${DATADIR}/ ! -type d | ${SED} 's|^${PREFIX}/||' >> ${TMPPLIST}
	@${FIND} -ds ${DATADIR}/ -type d | \
		${SED} -E -e 's,(.*),@unexec ${RMDIR} "\1" 2>/dev/null || true,' >> ${TMPPLIST}

	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
