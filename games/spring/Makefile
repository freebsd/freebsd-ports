# New ports collection makefile for:	spring
# Date created:		10 Jan 2008
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	spring
PORTVERSION=	0.76b1
PORTREVISION=	1
CATEGORIES=	games java
MASTER_SITES=	http://spring.clan-sy.com/dl/ \
		http://www.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}_${PORTVERSION}_src

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	TA Spring is a project aiming to create a new RTS

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		openal.0:${PORTSDIR}/audio/openal \
		GLEW.1:${PORTSDIR}/graphics/glew \
		boost_thread.4:${PORTSDIR}/devel/boost \
		IL.1:${PORTSDIR}/graphics/devil \
		ogg.5:${PORTSDIR}/audio/libogg \
		vorbis.4:${PORTSDIR}/audio/libvorbis
BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip

USE_BZIP2=	yes
USE_SDL=	sdl
USE_PYTHON=	2.4+
USE_GL=		yes
USE_GMAKE=	yes

USE_JAVA=	yes
JAVA_VERSION=	1.5+

USE_SCONS=	yes
SCONS_ARGS=	prefix="${PREFIX}" datadir="share/${PORTNAME}" \
		bindir="bin"
SCONS_BUILDENV=	JAVA_INC="${JAVA_HOME}/include" ${SCONS_ENV}

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}

PORTDOCS=	README.html

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/include|${LOCALBASE}/include|' \
		${WRKSRC}/rts/build/scons/config.py
	@${REINPLACE_CMD} -e 's|"make "|"${GMAKE} "|' ${WRKSRC}/SConstruct
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|' \
		${WRKSRC}/rts/System/Platform/Linux/UnixFileSystemHandler.cpp

do-configure:
	@cd ${BUILD_WRKSRC} && ${SETENV} ${SCONS_BUILDENV} ${SCONS_BIN} \
		${SCONS_ENV} ${SCONS_ARGS} configure

post-install:
	@${MKDIR} ${PREFIX}/etc/spring
	@${ECHO_CMD} '$$HOME/.spring' > ${PREFIX}/etc/spring/datadir
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.mk>
