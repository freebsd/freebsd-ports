# New ports collection makefile for:	glest
# Date created:				2005-10-30
# Whom:					Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	glest
PORTVERSION=	1.2.1.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${PORTNAME}_source_${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}_data_1.2.1${EXTRACT_SUFX}

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Free 3d real-time customizable strategy game

LIB_DEPENDS=	xerces-c.26:${PORTSDIR}/textproc/xerces-c2 \
		vorbis.3:${PORTSDIR}/audio/libvorbis \
		openal.0:${PORTSDIR}/audio/openal
BUILD_DEPENDS=	jam:${PORTSDIR}/devel/jam

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_AUTOTOOLS=	automake:15:env autoconf:259:env
USE_ZIP=	yes
USE_GCC=	3.2+
USE_SDL=	yes
USE_GL=		yes
GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	mk/linux/configure
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

WRKSRC=		${WRKDIR}/${PORTNAME}_source_${PORTVERSION}

LDFLAGS+=	-L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS}
CPPFLAGS+=	-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}
MAKE_ENV=	CC="${CC}" CFLAGS="${CFLAGS} ${CXX}" LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}"
CONFIGURE_ENV=	${MAKE_ENV}

GLESTDIRE=	${PREFIX}/lib/${PORTNAME}

SUB_FILES=	glest-wrapper

post-extract:
	@${FIND} -E ${WRKDIR} -type f -iregex ".*\.(c|cpp|h|txt|sh|ac|sub|ini|m4|jam|guess|rpath)" \
		-print0 | ${XARGS} -0 ${REINPLACE_CMD} -e 's/[[:cntrl:]]*$$//'

post-patch:
	@${REINPLACE_CMD} -e "s|%%ACLOCAL%%|${ACLOCAL}|g" -e "s|%%AUTOCONF%%|${AUTOCONF}|g" \
		${WRKSRC}/mk/linux/autogen.sh
	@${REINPLACE_CMD} -e "s|-lpthread|${PTHREAD_LIBS}|g" \
		${WRKSRC}/mk/linux/configure.ac ${WRKSRC}/mk/linux/mk/autoconf/binreloc.m4
	@${FIND} -E ${WRKDIR} -type f -name '*.bak' -o -name '*.orig' | ${XARGS} ${RM}

pre-configure:
	@cd ${WRKSRC}/mk/linux && ${SH} autogen.sh

do-build:
	@cd ${WRKSRC} && jam -q

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_game/license.txt ${DOCSDIR}/license-data.txt
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_game/readme.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/license.txt ${DOCSDIR}/license-game.txt
.endif
	@${RM} ${WRKDIR}/${PORTNAME}_game/license.txt
	@${RM} ${WRKDIR}/${PORTNAME}_game/readme.txt
	@${MKDIR} ${GLESTDIRE}
	@cd ${WRKDIR}/${PORTNAME}_game && \
		${INSTALL_PROGRAM} ${WRKSRC}/glest ${GLESTDIRE} && \
		${INSTALL_DATA} ${WRKSRC}/mk/linux/glest.ini ${GLESTDIRE} && \
		${INSTALL_SCRIPT} ${WRKDIR}/glest-wrapper ${PREFIX}/bin/glest && \
		${FIND} * -type d -exec ${MKDIR} "${GLESTDIRE}/{}" \; && \
		${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${GLESTDIRE}/{}" \;

post-install:
	@${CHMOD} 666 ${GLESTDIRE}/glest.log
	@${ECHO_MSG}
	@${ECHO_MSG} "* Configuration file ${GLESTDIRE}/glest.ini"
	@${ECHO_MSG}

.include <bsd.port.mk>
