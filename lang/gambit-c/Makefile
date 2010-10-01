# New ports collection makefile for:	gambc
# Date created:        			28 December 2006
# Whom:					Rob Zinkov
#
# $FreeBSD$
#

PORTNAME=	gambit-c
DISTVERSION=	v4_6_0
PORTEPOCH=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.iro.umontreal.ca/~gambit/download/gambit/v4.6/source/
DISTNAME=	gambc-${DISTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pmn@bakarika.net
COMMENT=	Gambit programming system where the compiler generates portable C code

MAN1= gsi.1

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS =	--enable-single-host --enable-gcc-opts
CONFIGURE_ARGS+=	--prefix=${PREFIX} --docdir=${PREFIX}/share/doc/gambit-c
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/gambit-c/ --includedir=${PREFIX}/include/gambit-c
CONFIGURE_ARGS+=	--enable-interpreter-name=gsi-gambit  --enable-compiler-name=gsc-gambit

INFO=	gambit-c

MAKE_JOBS_SAFE=	yes

.include <bsd.port.pre.mk>

# This is needed because 4.2 < gcc -v < 4.4 has optimisations that make the
# build take more than 20Gb of virtual memory.
.if ${OSVERSION} >= 700042
CFLAGS+=	-fno-move-loop-invariants
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^\(FLAGS_OBJ = \).*|\1 ${CFLAGS}|' ${WRKSRC}/makefile.in
	@${REINPLACE_CMD} -e 's|^\(FLAGS_DYN = \).*|\1 ${CFLAGS}|' ${WRKSRC}/makefile.in
	@${REINPLACE_CMD} -e 's|^\(FLAGS_OBJ = \).*|\1 ${CFLAGS}|' ${WRKSRC}/lib/makefile.in
	@${REINPLACE_CMD} -e 's|^\(FLAGS_DYN = \).*|\1 ${CFLAGS}|' ${WRKSRC}/lib/makefile.in
	@${REINPLACE_CMD} -e 's|^\(FLAGS_OBJ = \).*|\1 ${CFLAGS}|' ${WRKSRC}/gsi/makefile.in
	@${REINPLACE_CMD} -e 's|^\(FLAGS_DYN = \).*|\1 ${CFLAGS}|' ${WRKSRC}/gsi/makefile.in
	@${REINPLACE_CMD} -e 's|^\(FLAGS_OBJ = \).*|\1 ${CFLAGS}|' ${WRKSRC}/gsc/makefile.in
	@${REINPLACE_CMD} -e 's|^\(FLAGS_DYN = \).*|\1 ${CFLAGS}|' ${WRKSRC}/gsc/makefile.in

post-configure:
	@${MV} ${WRKSRC}/makefile ${WRKSRC}/Makefile

.include <bsd.port.post.mk>
