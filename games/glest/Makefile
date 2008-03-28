# New ports collection makefile for:	glest
# Date created:				2005-10-30
# Whom:					Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	glest
PORTVERSION=	3.1.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-source-${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free 3d real-time customizable strategy game

LIB_DEPENDS=	xerces-c.27:${PORTSDIR}/textproc/xerces-c2 \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		openal.0:${PORTSDIR}/audio/openal \
		alut.1:${PORTSDIR}/audio/freealut
BUILD_DEPENDS=	jam:${PORTSDIR}/devel/jam
RUN_DEPENDS=	${DATADIR}/configuration.xml:${PORTSDIR}/games/glest-data

USE_AUTOTOOLS=	automake:15:env autoconf:261:env
USE_BZIP2=	yes
USE_DOS2UNIX=	yes
USE_SDL=	yes
USE_GL=		yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
			LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
SUB_FILES=		glest-wrapper pkg-message

JAM_CMD=		${LOCALBASE}/bin/jam -qa

OPTIONS=	EDITOR	"Build map editor"	off

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

post-patch:
	@${REINPLACE_CMD} -e "s|%%ACLOCAL%%|${ACLOCAL}|g" -e "s|%%AUTOCONF%%|${AUTOCONF}|g" \
		${WRKSRC}/autogen.sh
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|PTHREAD_LIBS="-l[$$]flag"|PTHREAD_LIBS="${PTHREAD_LIBS}"|g ; \
		s|pthreads library -l[$$]flag|pthreads library ${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure.ac ${WRKSRC}/mk/autoconf/*
	@${FIND} -E ${WRKDIR} -type f -name '*.bak' -o -name '*.orig' | ${XARGS} ${RM}

pre-configure:
	@cd ${WRKSRC} && ${SH} autogen.sh

do-build:
	@cd ${WRKSRC} && ${JAM_CMD}

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/license.txt ${DOCSDIR}/license-game.txt
.endif
	@${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/glest ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/glest.ini ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/glest-wrapper ${PREFIX}/bin/${PORTNAME}

.if defined(HAVE_EDITOR)
	${INSTALL_PROGRAM} ${WRKSRC}/glest_editor ${PREFIX}/bin/
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
