# New ports collection makefile for: allegrogl
# Date created:		22 Jan 2004
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	allegrogl
PORTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	alleggl-${PORTVERSION}

MAINTAINER=	tiamat@comset.net
COMMENT=	OpenGL inteface for Allegro library

LIB_DEPENDS=	alleg.41:${PORTSDIR}/devel/allegro

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GL=		yes
USE_X_PREFIX=	yes
USE_AUTOCONF_VER=253
GNU_CONFIGURE=	yes
MAKEFILE=	makefile
ALL_TARGET=	lib

WRKSRC=		${WRKDIR}/alleggl

ALLEGRO_CONFIG?=${LOCALBASE}/bin/allegro-config

post-patch:
	@${REINPLACE_CMD} -e 's|%%GMAKE%%|${GMAKE}|g; \
			      s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure.in
	@${REINPLACE_CMD} -e 's|%%ALLEGRO_CONFIG%%|${ALLEGRO_CONFIG}|g' \
		${WRKSRC}/make/makefile.unx

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/unix/libagl.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/include/alleggl.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/alleggl_config.h ${PREFIX}/include
	@${MKDIR} ${PREFIX}/include/allegrogl
	${INSTALL_DATA} ${WRKSRC}/include/allegrogl/*.h \
		${PREFIX}/include/allegrogl
	@${MKDIR} ${PREFIX}/include/allegrogl/GLext
	${INSTALL_DATA} ${WRKSRC}/include/allegrogl/GLext/*.h \
		${PREFIX}/include/allegrogl/GLext

	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examp/* ${EXAMPLESDIR}
	@${PERL} -pi -e 's|%%CC%%|${CC}|g; \
			 s|%%RM%%|${RM}|g; \
			 s|%%CFLAGS%%|${CFLAGS}|g; \
			 s|%%PREFIX%%|${PREFIX}|g; \
			 s|%%X11BASE%%|${X11BASE}|g; \
			 s|%%ALLEGRO_CONFIG%%|${ALLEGRO_CONFIG}|g' \
		<${PATCHDIR}/makefile.ex >${EXAMPLESDIR}/makefile

.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
