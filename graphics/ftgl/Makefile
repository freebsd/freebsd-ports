# New ports collection makefile for: ftgl
# Date created:		16 Jan 2004
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	ftgl
PORTVERSION=	2.09
CATEGORIES=	graphics
MASTER_SITES=	http://homepages.paradise.net.nz/henryj/code/
DISTNAME=	${PORTNAME}-${PORTVERSION:C/([[:digit:]])$/.\1/}

MAINTAINER=	ip@doom.homeunix.org
COMMENT=	An OpenGL FreeType fonts rendering library

BUILD_DEPENDS=	${LOCALBASE}/bin/doxygen:${PORTSDIR}/devel/doxygen
LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

USE_GMAKE=	yes
USE_GL=		yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME:U}
CONFIGURE_WRKSRC=	${WRKSRC}/unix
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-gl-inc=${X11BASE}/include --with-gl-lib=${X11BASE}/lib
BUILD_WRKSRC=	${CONFIGURE_WRKSRC}
INSTALL_WRKSRC=	${CONFIGURE_WRKSRC}
MAKE_ENV=	MKDIR="${MKDIR}"

.ifdef (NOPORTDOCS)
DO_INSTALL_DOCS=\#
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PORTDOCS%%|${DO_INSTALL_DOCS}|' \
		${BUILD_WRKSRC}/Makefile

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/demo/* ${EXAMPLESDIR}
	@${SED} -e 's|%%CC%%|${CC}|g;			\
		    s|%%CXX%%|${CXX}|g;			\
		    s|%%RM%%|${RM}|g;			\
		    s|%%CFLAGS%%|${CFLAGS}|g;		\
		    s|%%CXXFLAGS%%|${CXXFLAGS}|g;	\
		    s|%%PREFIX%%|${PREFIX}|g;		\
		    s|%%X11BASE%%|${X11BASE}|g;		\
		    s|%%LOCALBASE%%|${LOCALBASE}|g'	\
	<${FILESDIR}/makefile.ex >${EXAMPLESDIR}/makefile

.include <bsd.port.mk>
