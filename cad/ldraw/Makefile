# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ldraw
PORTVERSION=	201501
PORTEPOCH=	1
CATEGORIES=	cad
MASTER_SITES=	http://www.ldraw.org/library/updates/
DISTNAME=	complete
DIST_SUBDIR=	ldraw/${PORTVERSION}

MAINTAINER=	koalative@gmail.com
COMMENT=	LDraw parts library

LICENSE=	CDDL CC-BY-NC-SA-2.0
LICENSE_COMB=	dual
LICENSE_FILE_CC-BY-NC-SA-2.0=	${WRKSRC}/CAlicense.txt

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		dos2unix gmake zip:infozip
DOS2UNIX_GLOB=	*.h makefile mklist.c *.txt *.dat

PORTDATA=	*
PORTDOCS=	Readme.txt
OPTIONS_DEFINE=	DOCS

SUB_FILES=	pkg-message

BUILD_WRKSRC=	${WRKSRC}/mklist
MAKEFILE=	makefile

post-extract-script:
	@(cd ${WRKSRC} && ${UNZIP_CMD} -qo -d \
		${WRKSRC}/mklist ${WRKSRC}/mklist1_6.zip)
	@(cd ${WRKSRC}/mklist/include && ${MV} * ..)

post-patch:
	@${REINPLACE_CMD} -e 's|CC=gcc|CC?=gcc|' \
		-e 's|CFLAGS=|CFLAGS?=|' \
		${WRKSRC}/mklist/makefile
	@${REINPLACE_CMD} -e 's|PARTS|parts|' \
		${WRKSRC}/mklist/mklist.c

do-install:
.for f in models p parts LDCfgalt.ldr LDConfig.ldr LDConfig_TLG.ldr
	@(cd ${WRKSRC} ; ${COPYTREE_SHARE} ${f} ${STAGEDIR}${DATADIR})
.endfor

	${INSTALL_PROGRAM} ${WRKSRC}/mklist/mklist ${STAGEDIR}${DATADIR}
	@(cd ${STAGEDIR}${DATADIR} && ./mklist -d)

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
