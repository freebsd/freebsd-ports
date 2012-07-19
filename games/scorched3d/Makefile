#
# Ports collection makefile for:	scorched3d
# Date created:				Jan 5, 2003
# Whom:					mdodd
#
# $FreeBSD$

PORTNAME=	scorched3d
PORTVERSION=	0.${SCORCH_VERSION}${SCORCH_REVISION}
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Version%20${SCORCH_VERSION}
DISTNAME=	Scorched3D-${SCORCH_VERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A 3D version of the classic DOS game Scorched Earth

LICENSE=	GPLv2

LIB_DEPENDS=	GLEW.1:${PORTSDIR}/graphics/glew \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		fftw3.6:${PORTSDIR}/math/fftw3 \
		fftw3f.6:${PORTSDIR}/math/fftw3-float \
		expat.6:${PORTSDIR}/textproc/expat2

OPTIONS_DEFINE=	MYSQL

WRKSRC=		${WRKDIR}/scorched

USE_GL=		glu
USE_OPENAL=	al alut
USE_SDL=	mixer net sdl
USE_WX=		2.4+
WX_CONF_ARGS=	absolute
USE_PERL5=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	aclocal automake autoconf
ACLOCAL_ARGS=	-I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	--add-missing --copy --force --foreign
CONFIGURE_ARGS=	--datadir=${DATADIR}
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

SCORCH_VERSION=		43.3d
SCORCH_REVISION=	# none

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql
.endif

post-extract:
	@${RM} -f ${WRKSRC}/src/client/GLEXT/[a-z]*

post-patch:
	@${REINPLACE_CMD} -e \
		'/^CPPFLAGS=/s|^|#|g ; \
		 /^LDFLAGS=/s|^|#|g ; \
		 /if test/s|==|=|' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e \
		'/GL_LIBS/s|"-lGL -lGLU"|"-lGL -lGLU -lGLEW"| ; \
		 /if test/s|==|=|' ${WRKSRC}/*.m4
	@${REINPLACE_CMD} -e \
		's|std::exit|exit|' ${WRKSRC}/src/common/common/main.h
	@${REINPLACE_CMD} -e \
		's|"glew.h"|<GL/glew.h>|' ${WRKSRC}/src/client/GLEXT/GLState.h
	@${REINPLACE_CMD} -e \
		'/GLEXT\\glew.c/d ; \
		 /GLEXT\\glew.h/d ; \
		 /GLEXT\\glxew.h/d ; \
		 /GLEXT\\wglew.h/d' ${WRKSRC}/src/client/scorchedc/scorchedc.vcxproj

pre-configure:
	@cd ${WRKSRC}/scripts && ${PERL} createAMMakefile.pl

.include <bsd.port.mk>
