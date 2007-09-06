# New ports collection makefile for:	glest
# Date created:				2005-10-30
# Whom:					Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	glest
PORTVERSION=	2.0.1
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
RUN_DEPENDS=	${DATADIR}/configuration.xml:${PORTSDIR}/games/glest-data

USE_XLIB=	yes
USE_AUTOTOOLS=	automake:15:env autoconf:259:env
USE_ZIP=	yes
USE_DOS2UNIX=	yes
USE_GCC=	3.2+
USE_SDL=	yes
USE_GL=		yes
GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	mk/linux/configure
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
			LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
EXTRACT_AFTER_ARGS=	-d ${WRKSRC}
SUB_FILES=		glest-wrapper pkg-message

JAM_CMD=		${LOCALBASE}/bin/jam -qa

.include <bsd.port.pre.mk>

pre-extract:
	@${MKDIR} ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e "s|%%ACLOCAL%%|${ACLOCAL}|g" -e "s|%%AUTOCONF%%|${AUTOCONF}|g" \
		${WRKSRC}/mk/linux/autogen.sh
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|PTHREAD_LIBS="-l[$$]flag"|PTHREAD_LIBS="${PTHREAD_LIBS}"|g ; \
		s|pthreads library -l[$$]flag|pthreads library ${PTHREAD_LIBS}|g' \
		${WRKSRC}/mk/linux/configure.ac ${WRKSRC}/mk/linux/mk/autoconf/*
	@${FIND} -E ${WRKDIR} -type f -name '*.bak' -o -name '*.orig' | ${XARGS} ${RM}

pre-configure:
	@cd ${WRKSRC}/mk/linux && ${SH} autogen.sh

do-build:
	@cd ${WRKSRC} && ${JAM_CMD}

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/license.txt ${DOCSDIR}/license-game.txt
.endif
	@${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/glest ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/mk/linux/glest.ini ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/glest-wrapper ${PREFIX}/bin/${PORTNAME}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
