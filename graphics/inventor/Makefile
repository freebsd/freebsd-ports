# Created by: Christian Gusenbauer
# $FreeBSD$

PORTNAME=	inventor
PORTVERSION=	2.1.5.p10
PORTREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=	ftp://oss.sgi.com/projects/inventor/download/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.p/-/}
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	c47g@gmx.at
COMMENT=	SGI's Open Inventor (TM)

LICENSE=	LGPL21

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2 \
		libjpeg.so:${PORTSDIR}/graphics/jpeg

CONFLICTS=	Coin-[0-9]* SoXt-[0-9]*

USE_XORG=	x11 xi
USE_GL=		glu glw
USES=		iconv gmake motif
USE_LDCONFIG=	yes
ONLY_FOR_ARCHS=	i386 amd64
MAKE_JOBS_UNSAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_ENV=	LD_LIBRARY_PATH=${WRKSRC}/lib:${WRKSRC}/libSoXt \
		INSTALL_STRIP=${STRIP} \
		IVROOT=${STAGEDIR}
MAKEFILE=	GNUmakefile

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DEBUG

DEBUG_MAKE_ENV=	LIBTYPE=debug

.include <bsd.port.options.mk>

.if !(${OPSYS} == FreeBSD && ${OSVERSION} < 900033)
MAKE_ENV+=	VLDOPTS=-Wl,--add-needed
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%CC%%|${CC}|g ;\
			      s|%%CXX%%|${CXX}|g ; \
			      s|%%CXXFLAGS%%|${CXXFLAGS}|g'  ${WRKSRC}/make/ivcommondefs
	@${REINPLACE_CMD} -e 's|%%ICONV_LIB%%|${ICONV_LIB}|' \
	    ${WRKSRC}/lib/GNUmakefile

.include <bsd.port.mk>
