# New ports collection makefile for:	glest
# Date created:				2005-10-30
# Whom:					Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	glest
PORTVERSION=	2.0.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_source_${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Free 3d real-time customizable strategy game

LIB_DEPENDS=	xerces-c.26:${PORTSDIR}/textproc/xerces-c2 \
		vorbis.3:${PORTSDIR}/audio/libvorbis \
		openal.0:${PORTSDIR}/audio/openal \
		alut.0:${PORTSDIR}/audio/freealut
BUILD_DEPENDS=	jam:${PORTSDIR}/devel/jam
RUN_DEPENDS=	${X11BASE}/lib/${PORTNAME}/configuration.xml:${PORTSDIR}/games/glest-data

USE_X_PREFIX=	yes
USE_AUTOTOOLS=	automake:15:env autoconf:259:env
USE_ZIP=	yes
USE_GCC=	3.2+
USE_SDL=	yes
USE_GL=		yes
GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	mk/linux/configure
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
			LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

GLESTDIRE=	lib/${PORTNAME}

PLIST_SUB=	GLESTDIRE=${GLESTDIRE}
SUB_FILES=	glest-wrapper

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=	does not build on 4.x
.endif

post-extract:
	@${FIND} -E ${WRKDIR} -type f -iregex ".*\.(c|cpp|h|txt|sh|ac|sub|ini|m4|jam|guess|rpath)" \
		-print0 | ${XARGS} -0 ${REINPLACE_CMD} -e 's/[[:cntrl:]]*$$//'

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
	@cd ${WRKSRC} && jam -q

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/license.txt ${DOCSDIR}/license-game.txt
.endif
	${MKDIR} ${PREFIX}/${GLESTDIRE}
	${INSTALL_PROGRAM} ${WRKSRC}/glest ${PREFIX}/${GLESTDIRE}
	${INSTALL_DATA} ${WRKSRC}/mk/linux/glest.ini ${PREFIX}/${GLESTDIRE}
	${INSTALL_SCRIPT} ${WRKDIR}/glest-wrapper ${PREFIX}/bin/glest

post-install:
	@${ECHO_MSG}
	@${ECHO_MSG} "* Configuration file ${PREFIX}/${GLESTDIRE}/glest.ini"
	@${ECHO_MSG}

.include <bsd.port.post.mk>
