# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	glest
PORTVERSION=	3.2.2
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20source/${PORTVERSION}
DISTNAME=	${PORTNAME}_source_${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free 3D real-time customizable strategy game

LIB_DEPENDS=	libxerces-c.so:${PORTSDIR}/textproc/xerces-c3 \
		libvorbis.so:${PORTSDIR}/audio/libvorbis
BUILD_DEPENDS=	jam:${PORTSDIR}/devel/jam
RUN_DEPENDS=	${DATADIR}/servers.ini:${PORTSDIR}/games/glest-data

USES=		dos2unix openal:al,alut pkgconfig zip lua:51
USE_AUTOTOOLS=	automake:env autoconf:env
USE_SDL=	yes
USE_GL=		yes
GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	mk/linux/configure
CPPFLAGS+=		-I${LOCALBASE}/include
LIBS+=			-L${LOCALBASE}/lib
SUB_FILES=		glest-wrapper pkg-message

JAM_CMD=		${LOCALBASE}/bin/jam -qa

OPTIONS_DEFINE=	DOCS EDITOR
OPTIONS_SUB=	yes
EDITOR_DESC=	Build map editor

EXTRACT_AFTER_ARGS=	-d ${WRKDIR}/${DISTNAME}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEDITOR}
USE_WX=		2.6+
WX_CONF_ARGS=	relative
WANT_UNICODE=	yes
HAVE_EDITOR=	true
.endif

pre-extract:
	@${MKDIR} ${WRKDIR}/${DISTNAME}

post-patch:
	@${REINPLACE_CMD} -e "s|%%ACLOCAL%%|${ACLOCAL}|g" -e "s|%%AUTOCONF%%|${AUTOCONF}|g" \
		${WRKSRC}/mk/linux/autogen.sh
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' -e \
		's|PTHREAD_LIBS="-l[$$]flag"|PTHREAD_LIBS="${PTHREAD_LIBS}"|g' -e \
		's|pthreads library -l[$$]flag|pthreads library ${PTHREAD_LIBS}|g' -e \
		's|include/lua5.1|include/lua51|g' -e 's|-llua5.1|-llua-5.1|g' \
			${WRKSRC}/mk/linux/configure.ac ${WRKSRC}/mk/linux/mk/autoconf/*
	@${FIND} -E ${WRKDIR} -type f -name '*.bak' -o -name '*.orig' | ${XARGS} ${RM}

pre-configure:
	@cd ${WRKSRC}/mk/linux && ${SH} autogen.sh && \
		${REINPLACE_CMD} -e 's|-llua5.1|-llua-5.1|g' -e 's|.lng||g' \
			${WRKSRC}/${CONFIGURE_SCRIPT} ${WRKSRC}/mk/linux/glest.ini

do-build:
	@cd ${WRKSRC} && ${JAM_CMD}

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/code_license.txt ${STAGEDIR}${DOCSDIR}/code_license.txt
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/glest ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/mk/linux/glest.ini ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/glest-wrapper ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.if ${PORT_OPTIONS:MEDITOR}
	${INSTALL_PROGRAM} ${WRKSRC}/glest_editor ${STAGEDIR}${PREFIX}/bin/
.endif

.include <bsd.port.mk>
