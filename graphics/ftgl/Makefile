# New ports collection makefile for: ftgl
# Date created:		16 Jan 2004
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	ftgl
PORTVERSION=	2.04
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://homepages.paradise.net.nz/henryj/code/
DISTNAME=	${PORTNAME:U}

MAINTAINER=	tiamat@comset.net
COMMENT=	An OpenGL FreeType fonts rendering library

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

USE_GMAKE=	yes
USE_GL=		yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_WRKSRC=	${WRKDIR}/${DISTNAME}/unix
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-gl-inc=${X11BASE}/include --with-gl-lib=${X11BASE}/lib
BUILD_WRKSRC=	${CONFIGURE_WRKSRC}
INSTALL_WRKSRC=	${CONFIGURE_WRKSRC}
INSTALLS_SHLIB=	yes

do-install:
	${INSTALL_DATA} ${INSTALL_WRKSRC}/src/.libs/lib${PORTNAME}.a ${PREFIX}/lib
	@${MKDIR} ${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${PREFIX}/include/${PORTNAME}

	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/demo/* ${EXAMPLESDIR}
	${PERL} -pi -e 's|%%CC%%|${CC}|g;		\
			s|%%CXX%%|${CXX}|g;		\
			s|%%RM%%|${RM}|g;		\
			s|%%CFLAGS%%|${CFLAGS}|g;	\
			s|%%CXXFLAGS%%|${CXXFLAGS}|g;	\
			s|%%PREFIX%%|${PREFIX}|g;	\
			s|%%X11BASE%%|${X11BASE}|g;	\
			s|%%LOCALBASE%%|${LOCALBASE}|g'	\
	<${FILESDIR}/makefile.ex >${EXAMPLESDIR}/makefile

.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/FTGL.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/FTGL_1_3.gif ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/images
	${INSTALL_DATA} ${WRKSRC}/docs/images/* ${DOCSDIR}/images
.endif

.include <bsd.port.mk>
