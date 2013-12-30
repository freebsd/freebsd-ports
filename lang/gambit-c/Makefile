# Created by: Rob Zinkov
# $FreeBSD$

PORTNAME=	gambit-c
DISTVERSION=	v4_6_6
PORTEPOCH=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.iro.umontreal.ca/~gambit/download/gambit/v4.6/source/
DISTNAME=	gambc-${DISTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pmn@bakarika.net
COMMENT=	Gambit programming system where the compiler generates portable C code

LICENSE=	APACHE20

MAN1=		gsi.1

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS =--enable-single-host --enable-gcc-opts
CONFIGURE_ARGS+=--prefix=${PREFIX} --docdir=${PREFIX}/share/doc/gambit-c
CONFIGURE_ARGS+=--libdir=${PREFIX}/lib/gambit-c/ --includedir=${PREFIX}/include/gambit-c
CONFIGURE_ARGS+=--enable-interpreter-name=gsi-gambit  --enable-compiler-name=gsc-gambit

INFO=		gambit-c


USE_LDCONFIG=	${PREFIX}/lib/gambit-c

PLIST_SUB+=	GSI_INC=include/gambit-c
PLIST_SUB+=	GSI_DOC=share/doc/gambit-c
PLIST_SUB+=	GSI_LIB=lib/gambit-c

# This is needed because 4.2 < gcc -v < 4.4 has optimisations that make the
# build take more than 20Gb of virtual memory.
CFLAGS+=	-fno-move-loop-invariants

NO_STAGE=	yes
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

.include <bsd.port.mk>
