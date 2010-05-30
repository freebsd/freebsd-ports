# New ports collection makefile for:	stfl
# Date created:		28 March 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	stfl
PORTVERSION=	0.21
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.clifford.at/stfl/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Structured Terminal Forms Language/Library

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
MAKE_JOBS_SAFE=	yes
ALL_TARGET=	libstfl.so
PLIST_FILES=	lib/libstfl.so.1 lib/libstfl.so include/stfl.h \
		libdata/pkgconfig/stfl.pc
CFLAGS+=	-I${LOCALBASE}/include
LDLIBS+=	-L${LOCALBASE}/lib
MAKE_ENV=	LDLIBS="${LDLIBS}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 602107 || (${OSVERSION} > 700000 && ${OSVERSION} < 700033)
LIB_DEPENDS+=	ncursesw.5:${PORTSDIR}/devel/ncurses
NCURSES_INC=	ncurses/
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|\.a|.so|g;/ranlib/d;\
	s|ar qc|$${CC} $${CFLAGS} ${PTHREAD_LIBS} $${LDLIBS} -shared -fPIC -o|;\
	s|sed -r|sed -E|;s|-Os||;/gcc/d;/-MM/s|-I.|$${CFLAGS}|'\
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|alloca.h|stdlib.h|' ${WRKSRC}/widgets/*.c
	@${REINPLACE_CMD} -e 's|ncursesw/|${NCURSES_INC}|'\
		${WRKSRC}/stfl_internals.h
	@${ECHO_CMD} 'prefix = ${PREFIX}' > ${WRKSRC}/Makefile.cfg

pre-build:
	@cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV}\
		${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} Makefile.deps

post-build:
	@cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV}\
		${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} stfl.pc

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/libstfl.so ${PREFIX}/lib/libstfl.so.1
	@${LN} -sf ${PREFIX}/lib/libstfl.so.1 ${PREFIX}/lib/libstfl.so
	@${INSTALL_DATA} ${WRKSRC}/stfl.h ${PREFIX}/include/
	@${INSTALL_DATA} ${WRKSRC}/stfl.pc ${PREFIX}/libdata/pkgconfig/

.include <bsd.port.post.mk>
