# Ports collection makefile for:	ffff
# Date created:				Sep 20, 2006
# Whom:					rossiya@gmail.com
#
# $FreeBSD$
#

PORTNAME=	ffff
PORTVERSION=	323
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/FFFF%203.2.3
DISTNAME=	FFFF${PORTVERSION}-src

MAINTAINER=	rossiya@gmail.com
COMMENT=	A fast mandelbrot fractal generator

USE_XORG=	x11 xmu xext
USE_DOS2UNIX=	yes
USE_GL=		gl glut
USE_ZIP=	yes

SOURCE=		FFFF3 FragmentProgram FragmentProgramARB10 GPUProgram \
		PixelBuffer VertexProgram VertexProgramATI VertexProgramNV \
		extensions vpext

CXXFLAGS+=	-I${LOCALBASE}/include/GL -D__linux__  -msse -msse2 -m3dnow -I${LOCALBASE}/include/ \
		${PTHREAD_CFLAGS} 
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS} -lglut -lGL -lXext -lX11 -lXmu \
		 -lGLU -lm

PLIST_FILES=	bin/ffff

# contains x86 assembler
ONLY_FOR_ARCHS=	i386

do-build:
.for f in ${SOURCE}
	${CXX} ${CXXFLAGS} -c ${WRKSRC}/${f}.cpp -o ${WRKSRC}/${f}.obj
.endfor
	${CXX} ${LDFLAGS} ${SOURCE:C/(.*)/${WRKSRC}\/\1.obj/} -o ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
