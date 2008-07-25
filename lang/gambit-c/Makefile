# New ports collection makefile for:	gambc
# Date created:        			28 December 2006
# Whom:					Rob Zinkov
#
# $FreeBSD$
#

PORTNAME=	gambc
DISTVERSION=	v4_2_6
PORTEPOCH=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.iro.umontreal.ca/~gambit/download/gambit/v4.2/source/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pmn@bakarika.net
COMMENT=	Gambit programming system where the compiler generates portable C code

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_ARGS=	PREFIX="${PREFIX}"

CONFIGURE_ARGS=	--enable-single-host --enable-gcc-opts

INFO=	gambit-c

post-patch:
	@${REINPLACE_CMD} -e 's|^\(install: install-pre install-recursive\) install-post|\1|' ${WRKSRC}/makefile.in
	@${REINPLACE_CMD} -e 's|^\(FLAGS_OBJ = \).*|\1 ${CFLAGS}|' ${WRKSRC}/makefile.in
	@${REINPLACE_CMD} -e 's|^\(FLAGS_DYN = \).*|\1 ${CFLAGS}|' ${WRKSRC}/makefile.in
	@${REINPLACE_CMD} -e 's|^\(FLAGS_OBJ = \).*|\1 ${CFLAGS}|' ${WRKSRC}/lib/makefile.in
	@${REINPLACE_CMD} -e 's|^\(FLAGS_DYN = \).*|\1 ${CFLAGS}|' ${WRKSRC}/lib/makefile.in
	@${REINPLACE_CMD} -e 's|^\(FLAGS_OBJ = \).*|\1 ${CFLAGS}|' ${WRKSRC}/gsi/makefile.in
	@${REINPLACE_CMD} -e 's|^\(FLAGS_DYN = \).*|\1 ${CFLAGS}|' ${WRKSRC}/gsi/makefile.in
	@${REINPLACE_CMD} -e 's|^\(FLAGS_OBJ = \).*|\1 ${CFLAGS}|' ${WRKSRC}/gsc/makefile.in
	@${REINPLACE_CMD} -e 's|^\(FLAGS_DYN = \).*|\1 ${CFLAGS}|' ${WRKSRC}/gsc/makefile.in

pre-configure:
	@${REINPLACE_CMD} -e 's|/4.2.6||' ${WRKSRC}/configure

post-configure:
	@${CP} ${WRKSRC}/makefile ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/v4.2.6||' ${WRKSRC}/makefile
	@${REINPLACE_CMD} -e 's|/v4.2.6||' ${WRKSRC}/Makefile

	@${REINPLACE_CMD} -e 's|/v4.2.6||' ${WRKSRC}/include/makefile
	@${REINPLACE_CMD} -e 's|/include|/include/Gambit-C|' ${WRKSRC}/include/makefile

	@${REINPLACE_CMD} -e 's|/v4.2.6||' ${WRKSRC}/lib/makefile

	@${REINPLACE_CMD} -e 's|/lib/|tempstr|' ${WRKSRC}/lib/makefile
	@${REINPLACE_CMD} -e 's|/lib|/lib/Gambit-C|' ${WRKSRC}/lib/makefile
	@${REINPLACE_CMD} -e 's|tempstr|/lib/|' ${WRKSRC}/lib/makefile

	@${REINPLACE_CMD} -e 's|/v4.2.6||' ${WRKSRC}/bin/makefile
	@${REINPLACE_CMD} -e 's|/v4.2.6||' ${WRKSRC}/gsc/makefile
	@${REINPLACE_CMD} -e 's|/v4.2.6||' ${WRKSRC}/gsi/makefile
	@${REINPLACE_CMD} -e 's| gsc | gsc-gambit |' ${WRKSRC}/bin/makefile
	@${REINPLACE_CMD} -e 's|/gsc |/gsc-gambit |' ${WRKSRC}/bin/makefile
	@${REINPLACE_CMD} -e 's|EXECUTABLE = gsc|EXECUTABLE = gsc-gambit|' ${WRKSRC}/gsc/makefile

	@${REINPLACE_CMD} -e 's|/v4.2.6||' ${WRKSRC}/doc/makefile

	@${REINPLACE_CMD} -e 's|/doc|/share/doc/Gambit-C|' ${WRKSRC}/doc/makefile

	@${REINPLACE_CMD} -e 's|PACKAGE_SUBDIR = /v4.2.6|PACKAGE_SUBDIR = |' ${WRKSRC}/misc/makefile

	@${REINPLACE_CMD} -e 's|/v4.2.6|/share/emacs/site-lisp|' ${WRKSRC}/misc/makefile

	@${REINPLACE_CMD} -e 's|/syntax-case.scm|/share/Gambit-C/syntax-case.scm|' ${WRKSRC}/misc/makefile
	@${REINPLACE_CMD} -e 's|/v4.2.6||' ${WRKSRC}/makefile

.include <bsd.port.mk>
