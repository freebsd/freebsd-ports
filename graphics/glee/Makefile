PORTNAME=	GLee
DISTVERSION=	5.4.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	https://elf-stone.com/downloads/${PORTNAME}/
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cross-platform extension loading library for OpenGL

LICENSE=	BSD2CLAUSE

USES=		gl gmake
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GL=		gl

NO_WRKSUBDIR=	yes

CFLAGS+=	-fPIC
LDFLAGS+=	-Wl,-z,defs -Wl,--as-needed -Wl,--no-undefined -L${LOCALBASE}/lib -lGL

SUB_FILES=	glee.pc

PLIST_FILES=	include/GL/GLee.h \
		lib/libGLee.so \
		lib/libGLee.so.5 \
		lib/libGLee.so.5.4 \
		libdata/pkgconfig/glee.pc

post-install:
	cd ${STAGEDIR}${PREFIX}/lib && \
		${MV} libGLee.so libGLee.so.${DISTVERSION:R} && \
		${LN} -s libGLee.so.${DISTVERSION:R} libGLee.so.${DISTVERSION:R:R} && \
		${LN} -s libGLee.so.${DISTVERSION:R} libGLee.so
	${INSTALL_DATA} ${WRKDIR}/glee.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig

.include <bsd.port.mk>
