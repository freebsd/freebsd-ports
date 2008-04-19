# Ports collection makefile for:	ffff
# Date created:				Sep 20, 2006
# Whom:					rossiya@gmail.com
#
# $FreeBSD$
#

PORTNAME=	ffff
PORTVERSION=	323
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SFE
DISTNAME=	FFFF${PORTVERSION}-src

MAINTAINER=	rossiya@gmail.com
COMMENT=	A fast mandelbrot fractal generator


USE_DOS2UNIX=	yes
USE_GL=		glut
USE_ZIP=	yes

SOURCE=		FFFF3 FragmentProgram FragmentProgramARB10 GPUProgram \
		PixelBuffer VertexProgram VertexProgramATI VertexProgramNV \
		extensions vpext

CXXFLAGS+=	-I${LOCALBASE}/include/GL ${PTHREAD_CFLAGS} \
		-D__linux__
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

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
BROKEN=		Does not compile with GCC 4.2
.endif

.include <bsd.port.post.mk>
