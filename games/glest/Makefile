# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	glest
PORTVERSION=	3.2.2
PORTREVISION=	12
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20source/${PORTVERSION}
DISTNAME=	${PORTNAME}_source_${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	mmokhi@FreeBSD.org
COMMENT=	Free 3D real-time customizable strategy game

LIB_DEPENDS=	libxerces-c.so:textproc/xerces-c3 \
		libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg
BUILD_DEPENDS=	jam:devel/jam
RUN_DEPENDS=	${LOCALBASE}/${DATADIR_REL}/servers.ini:games/glest-data

USES=		autoreconf:build dos2unix gl localbase lua:51 openal:al,alut \
		pkgconfig sdl xorg zip
USE_SDL=	sdl
USE_GL=		gl glu
USE_XORG=	x11
LLD_UNSAFE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	mk/linux/configure
SUB_FILES=		glest-wrapper pkg-message

JAM_CMD=		${LOCALBASE}/bin/jam -q -a -dx

OPTIONS_DEFINE=	DOCS EDITOR
OPTIONS_SUB=	yes
EDITOR_DESC=	Build map editor

EXTRACT_AFTER_ARGS=	-d ${WRKDIR}/${DISTNAME}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEDITOR}
USE_WX=		2.6+
WX_CONF_ARGS=	relative
HAVE_EDITOR=	true
.endif

pre-extract:
	@${MKDIR} ${WRKDIR}/${DISTNAME}

post-patch:
	@${REINPLACE_CMD} \
		-e 's|PTHREAD_LIBS="-l[$$]flag"|PTHREAD_LIBS="-lpthread"|g' \
		-e 's|pthreads library -l[$$]flag|pthreads library -lpthread|g' \
		-e 's|include/lua5.1|include/lua51|g' \
		-e 's|-llua5.1|-llua-5.1|g' \
		${WRKSRC}/mk/linux/configure.ac \
		${WRKSRC}/mk/linux/mk/autoconf/*
	@${FIND} -E ${WRKDIR} -type f -name '*.bak' -o -name '*.orig' | \
		${XARGS} ${RM}

pre-configure:
	@(cd ${WRKSRC}/mk/linux && ${SH} autogen.sh && \
		${REINPLACE_CMD} -e 's|-llua5.1|-llua-5.1|g' -e 's|.lng||g' \
		${WRKSRC}/${CONFIGURE_SCRIPT} ${WRKSRC}/mk/linux/glest.ini)

do-build:
	@(cd ${WRKSRC} && ${JAM_CMD})

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/docs/code_license.txt \
		${STAGEDIR}${DOCSDIR}/code_license.txt
	${INSTALL_PROGRAM} ${WRKSRC}/glest ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/mk/linux/glest.ini ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/glest-wrapper \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

do-install-EDITOR-on:
	${INSTALL_PROGRAM} ${WRKSRC}/glest_editor ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
