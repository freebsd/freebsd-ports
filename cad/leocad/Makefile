# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	leocad
PORTVERSION=	0.79.3
CATEGORIES=	cad
MASTER_SITES=	GOOGLE_CODE
DISTFILES=	${PORTNAME}-${PORTVERSION}-src.tgz \
		${LEOCAD_PIECES}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}-src.tgz

MAINTAINER=	nemysis@gmx.ch
COMMENT=	CAD program that uses bricks similar to those found in many toys

LICENSE=	GPLv2

EXTRACT_DEPENDS=${UNZIP_CMD}:${PORTSDIR}/archivers/unzip
LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/${PORTNAME}
LEOCAD_PIECES=	pieces-7114.zip

USES=		gmake pkgconfig shared-mime-info
USE_GL=		glut
USE_GNOME=	gtk20
MAKE_JOBS_SAFE=	yes

MAN1=		leocad.1

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	CREDITS.txt README.txt

DOCSRCDIR2=	${WRKSRC}/docs
DOCSDIR2=	${DOCSDIR}/docs
DOC_FILES2=	LINUX.txt TODO.txt

INSTALLS_ICONS=	yes
ICON_SIZES=	16x16 24x24 32x32 48x48 128x128 256x256

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

post-extract:
	@${UNZIP_CMD} -q -o ${_DISTDIR}/${LEOCAD_PIECES} -d ${WRKDIR}/pieces

post-patch:
	@${REINPLACE_CMD} -e \
		's|-ldl||' ${WRKSRC}/common/module.mk
	@${REINPLACE_CMD} \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		-e 's|%%PTHREAD_CFLAGS%%|${PTHREAD_CFLAGS}|' \
		-e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|' \
		${WRKSRC}/config.mk
	@${REINPLACE_CMD} 's|share/man|man|g' \
		${WRKSRC}/Makefile
.for s in 16 24 32 48 128 256
	@cd ${WRKSRC}/tools/icon && \
		${MV} icon${s}.png ${PORTNAME}_${s}x${s}.png
.endfor
	@cd ${WRKSRC}/tools/icon && ${CP} -a ${PORTNAME}_128x128.png icon128.png

do-configure:
	cd ${WRKSRC} && ${SETENV} PREFIX="${PREFIX}" ${GMAKE} config

post-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/pieces/* ${DATADIR}

.for s in ${ICON_SIZES}
	${MKDIR} ${PREFIX}/share/icons/hicolor/${s}/apps
	${INSTALL_DATA} ${WRKSRC}/tools/icon/${PORTNAME}_${s}.png \
		${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	@${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${DOCSDIR2}
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.include <bsd.port.post.mk>
