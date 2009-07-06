# New ports collection makefile for:	glest
# Date created:				2005-10-30
# Whom:					Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	glest
PORTVERSION=	3.2.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_source_${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free 3d real-time customizable strategy game

LIB_DEPENDS=	xerces-c.27:${PORTSDIR}/textproc/xerces-c2 \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		openal.0:${PORTSDIR}/audio/openal \
		alut.1:${PORTSDIR}/audio/freealut
BUILD_DEPENDS=	jam:${PORTSDIR}/devel/jam
RUN_DEPENDS=	${DATADIR}/servers.ini:${PORTSDIR}/games/glest-data

USE_AUTOTOOLS=	automake:15:env autoconf:262:env
USE_ZIP=	yes
USE_DOS2UNIX=	yes
USE_LUA=	5.1
USE_SDL=	yes
USE_GL=		yes
GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	mk/linux/configure
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
			LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
SUB_FILES=		glest-wrapper pkg-message

JAM_CMD=		${LOCALBASE}/bin/jam -qa

OPTIONS=	EDITOR	"Build map editor"	off

EXTRACT_AFTER_ARGS=	-d ${WRKDIR}/${DISTNAME}

.include <bsd.port.pre.mk>

.if defined(WITH_EDITOR)
USE_WX=		2.6+
WX_CONF_ARGS=	relative
WANT_UNICODE=	yes
PLIST_SUB+=	EDITOR=""
HAVE_EDITOR=	true
.else
PLIST_SUB+=	EDITOR="@comment "
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
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/code_license.txt ${DOCSDIR}/code_license.txt
.endif
	@${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/glest ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/mk/linux/glest.ini ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/glest-wrapper ${PREFIX}/bin/${PORTNAME}

.if defined(HAVE_EDITOR)
	${INSTALL_PROGRAM} ${WRKSRC}/glest_editor ${PREFIX}/bin/
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
