# New ports collection makefile for:	Ming
# Date created:		14 October 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	ming
PORTVERSION=	0.2a
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.opaque.net/ming/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${PORTNAME}-examples${EXTRACT_SUFX}
EXTRACT_SUFX=	.tgz

MAINTAINER=	knu@FreeBSD.org
COMMENT=	LGPL'ed Flash 4/5 movie output library with many languages support

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		ungif.5:${PORTSDIR}/graphics/libungif

CONFLICTS=	ja-ming-*

WRKSRC=		${WRKDIR}/${DISTNAME}/src
MAKE_ARGS=	NOPROFILE=true
INSTALLS_SHLIB=	yes

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

post-extract:
	${LN} -s ${WRKDIR}/${PORTNAME}-examples ${WRKSRC}/../examples
	${SED} -e 's:"\.\./\.\./ming\.h":<ming.h>:g' \
		${WRKSRC}/ming.h > ${WRKSRC}/mingpp.h
	cd ${WRKSRC}/../util && \
	${RM} bindump.c decompile5.c hexdump.c listmp3.c
#	cd ${WRKSRC}/../php_ext && ${LN} -sf ming-4.0.6.c ming.c
	${RM} -rf ${WRKSRC}/../examples/results

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/

post-build:
	cd ${WRKSRC}/../util && \
	${CC} ${CFLAGS} -I${PREFIX}/include -I${PREFIX}/include/ming -c *.c
	cd ${WRKSRC}/../util && \
	${CC} ${CFLAGS} -L${PREFIX}/lib -o gif2dbl gif2dbl.o -lm -lz -lungif
	cd ${WRKSRC}/../util && \
	${CC} ${CFLAGS} -L${PREFIX}/lib -o gif2mask gif2mask.o -lm -lz -lungif
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
	${MKDIR} ${PREFIX}/include/ming/blocks

post-install:
.for f in ${UTILS}
	${INSTALL_PROGRAM} ${WRKSRC}/../util/${f} ${PREFIX}/bin/
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ming/utils
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/../${f} ${PREFIX}/share/doc/ming/
.endfor
.for f in ${DOCS_UTIL}
	${INSTALL_DATA} ${WRKSRC}/../util/${f} ${PREFIX}/share/doc/ming/utils/
.endfor
	${MKDIR} ${PREFIX}/share/examples/ming/common
	${INSTALL_DATA} ${WRKSRC}/../examples/common/* \
		 ${PREFIX}/share/examples/ming/common/
	${MKDIR} ${PREFIX}/share/examples/ming/c
	${INSTALL_DATA} ${WRKSRC}/../examples/c/*.c \
		 ${PREFIX}/share/examples/ming/c/
	${MKDIR} ${PREFIX}/share/examples/ming/c++
	${INSTALL_DATA} ${WRKSRC}/../examples/c++/*.cpp \
		 ${PREFIX}/share/examples/ming/c++/
.endif

.include <bsd.port.mk>
