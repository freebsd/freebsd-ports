# $FreeBSD$

PORTNAME=	ming
PORTVERSION=	0.1.5
PORTREVISION=	11
CATEGORIES=	japanese graphics
MASTER_SITES=	http://dist.bsdlab.org/
#MASTER_SITES=	http://blue.ribbon.to/~harpy/ming/jaming/
DISTNAME=	jaming-${PORTVERSION}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	LGPL'ed Flash 4/5 movie output library with Japanese languages support

LIB_DEPENDS=	libpng.so:graphics/png \
		libgif.so:graphics/giflib

CONFLICTS=	ming-*

WRKSRC=		${WRKDIR}/jaming-${PORTVERSION}/src
MAKE_ARGS=	NO_PROFILE=true
USE_LDCONFIG=	yes
USES=		bison uidfix
MAKE_ENV=	WITHOUT_PROFILE=yes __MAKE_CONF=/dev/null SRCCONF=/dev/null

UTILS=		gif2dbl \
		gif2mask \
		listfdb \
		listjpeg \
		listswf \
		makefdb \
		png2dbl \
		swftophp
DOCS=		CHANGES \
		CREDITS \
		README \
		TODO
DOCS_UTIL=	README \
		TODO

OPTIONS_DEFINE=	DOCS

post-extract:
	${SED} -e 's:"\.\./\.\./ming\.h":<ming.h>:g' \
		${WRKSRC}/ming.h > ${WRKSRC}/mingpp.h
	cd ${WRKSRC}/../util && \
	${RM} bindump.c decompile5.c hexdump.c listmp3.c

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/
	cd ${WRKSRC}/actioncompiler; ${MAKE} lex.swf4.c lex.swf5.c swf4compiler.tab.c swf5compiler.tab.c

post-build:
	cd ${WRKSRC}/../util && \
	${CC} ${CFLAGS} -I${PREFIX}/include -I${PREFIX}/include/ming -c *.c
	cd ${WRKSRC}/../util && \
	${CC} ${CFLAGS} -L${PREFIX}/lib -o gif2dbl gif2dbl.o -lm -lz -lgif
	cd ${WRKSRC}/../util && \
	${CC} ${CFLAGS} -L${PREFIX}/lib -o gif2mask gif2mask.o -lm -lz -lgif
	cd ${WRKSRC}/../util && \
	${CC} ${CFLAGS} -L${PREFIX}/lib -o listfdb listfdb.o blocktypes.o
	cd ${WRKSRC}/../util && \
	${CC} ${CFLAGS} -L${PREFIX}/lib -o listjpeg listjpeg.o
	cd ${WRKSRC}/../util && \
	${CC} ${CFLAGS} -L${PREFIX}/lib -o listswf listswf.o blocktypes.o decompile.o read.o -lz
	cd ${WRKSRC}/../util && \
	${CC} ${CFLAGS} -L${PREFIX}/lib -o makefdb makefdb.o blocktypes.o read.o
	cd ${WRKSRC}/../util && \
	${CC} ${CFLAGS} -L${PREFIX}/lib -o png2dbl png2dbl.o -lm -lz -lpng
	cd ${WRKSRC}/../util && \
	${CC} ${CFLAGS} -L${PREFIX}/lib -o swftophp swftophp.o blocktypes.o decompile.o read.o -lm

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/ming/blocks

post-install:
.for f in ${UTILS}
	${INSTALL_PROGRAM} ${WRKSRC}/../util/${f} ${STAGEDIR}${PREFIX}/bin/
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/ming/utils
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/../${f} ${STAGEDIR}${PREFIX}/share/doc/ming/
.endfor
.for f in ${DOCS_UTIL}
	${INSTALL_DATA} ${WRKSRC}/../util/${f} ${STAGEDIR}${PREFIX}/share/doc/ming/utils/
.endfor

.include <bsd.port.mk>
