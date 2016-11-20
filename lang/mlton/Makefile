# Created by: Stephen Weeks <sweeks@sweeks.com>
# $FreeBSD$

# Previouly maintained by Jesper Louis Andersen
# (jesper.louis.andersen@gmail.com) and Geoffrey Mainland
# (mainland@apeiron.net)
#
# Because MLton is written in SML, it needs an SML compiler to build.
# It is easiest to use another (earlier) binary version of MLton as
# the SML compiler.  So, this Makefile fetches and installs an
# alread-built version of MLton, BOOT_DIST, to use for bootstrapping.

PORTNAME=	mlton
PORTVERSION=	20100608
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	SF http://www.tbrk.org/distfiles/
DISTFILES=	${SRC_DIST} ${BOOT_DIST}
EXTRACT_ONLY=	${SRC_DIST}

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Optimizing Standard ML compiler

LIB_DEPENDS=	libgmp.so:math/gmp
RUN_DEPENDS=	bash:shells/bash
BUILD_DEPENDS=	bash:shells/bash

LICENSE_FILE=	doc/license/MLton-LICENSE

OPTIONS_DEFINE=	SMLNJ MINGW32 DOCS
SMLNJ_DESC=	Bootstrap with SML/NJ (can take >15 hours)
MINGW32_DESC=	Add the mingw32 target (requires wine)

MAKE_JOBS_UNSAFE=	yes
USES=		gmake shebangfix
USE_GCC=	any

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	gsed:textproc/gsed \
		htmldoc:textproc/htmldoc
USE_TEX=	latex:build
.else
INSTALL_TARGET=	install-no-docs remove-docs
ALL_TARGET=	all-no-docs
.endif

SRC_DIST=	${DISTNAME}.src.tgz

.if ${PORT_OPTIONS:MSMLNJ}
BROKEN=	${DISTNAME}-${PORTVERSION} does not bootstrap properly with smlnj
.endif

.if ${PORT_OPTIONS:MSMLNJ}
BUILD_DEPENDS+=	smlnj>=110.65:lang/smlnj
BOOT_DIST=
MAKE_ENV+=	SMLNJ_DEVEL=yes
.if ! ${PORT_OPTIONS:MDOCS}
ALL_TARGET=	smlnj-mlton all-no-docs
.else
ALL_TARGET=	smlnj-mlton all
.endif
.else
BOOT_DIST=	${PORTNAME}-${PORTVERSION}-1.${MACHINE_ARCH}-freebsd${OSRELMAJ}.${BOOT_SUF}
.endif

.if ${PORT_OPTIONS:MMINGW32}
BUILD_DEPENDS+=	wine:emulators/wine \
		mingw32-gcc:devel/mingw32-gcc \
		${LOCALBASE}/mingw32/lib/libgmp.a:math/mingw32-libgmp
RUN_DEPENDS+=	mingw32-gcc:devel/mingw32-gcc \
		${LOCALBASE}/mingw32/lib/libgmp.a:math/mingw32-libgmp

PLIST_SUB+=	MINGW32CROSS=""
.else
PLIST_SUB+=	MINGW32CROSS="@comment "
.endif

# MINGW32 requires wine, which doesn't have an official amd64 port
.if ${PORT_OPTIONS:MSMLNJ} || ${PORT_OPTIONS:MMINGW32}
ONLY_FOR_ARCHS=	i386
.else
ONLY_FOR_ARCHS=	i386 amd64
.endif

BOOT_WRKSRC=	${WRKDIR}/mlton-bootstrap

MAKE_ARGS=	DESTDIR='' \
		PATH=${WRKSRC}/build/bin:${BOOT_WRKSRC}/bin:${PATH} \
		PREFIX=${PREFIX}

.if ${ARCH} == "i386"
MLTON_ARCH=	"x86"
.elif ${ARCH} == "amd64"
MLTON_ARCH=	"x64"
.endif

BOOT_EXTRACT=	--bzip2
BOOT_SUF=	tbz

post-extract:
	@${CP} ${FILESDIR}/add-local-cross ${WRKSRC}/bin/
	@${CHMOD} 755 ${WRKSRC}/bin/add-local-cross
.if ${PORT_OPTIONS:MSMLNJ}
	@${CP} ${FILESDIR}/upgrade-basis.sml ${WRKSRC}/mlton/
	@for f in `ls ${FILESDIR}/ml.* ${FILESDIR}/mlb.*`; do \
		${CP} $$f ${WRKSRC}/mlton/front-end/; \
	done
	@for f in `ls ${FILESDIR}/yacc.*`; do \
		${CP} $$f ${WRKSRC}/mlyacc/src/; \
	done
.else
	@${MKDIR} ${BOOT_WRKSRC}
	@${TAR} xf ${DISTDIR}/${BOOT_DIST} ${BOOT_EXTRACT} -C ${BOOT_WRKSRC}
.endif

post-patch:
	@${REINPLACE_CMD} 's/CC := gcc -std=gnu99/CC := ${CC} -std=gnu99/g' \
		${WRKSRC}/runtime/Makefile \
		${BOOT_WRKSRC}/lib/mlton/sml/mlnlffi-lib/Makefile
	@${REINPLACE_CMD} 's/gcc -v/${CC} -v/g' ${WRKSRC}/runtime/util/Makefile
	@${REINPLACE_CMD} 's/CC = gcc -std=gnu99/CC = ${CC} -std=gnu99/g' ${WRKSRC}/runtime/util/Makefile
.if ${ARCH} == "i386"
	@${REINPLACE_CMD} 's/ram-slop 0\.7/max-heap 800m/g' ${WRKSRC}/mlton/Makefile
.else
	@${REINPLACE_CMD} 's/ram-slop 0\.7/max-heap 2g/g' ${WRKSRC}/mlton/Makefile
.endif
.if ! ${PORT_OPTIONS:MSMLNJ}
	@${REINPLACE_CMD} -e \
		"s|/usr/local/lib/mlton|${BOOT_WRKSRC}/lib/mlton|;s|/usr/local|${LOCALBASE}|" \
		${BOOT_WRKSRC}/bin/mlton
	@${REINPLACE_CMD} -e "s|"$$"dir/../lib/mlton|${BOOT_WRKSRC}/lib/mlton|" \
		${BOOT_WRKSRC}/bin/mlton
	@${REINPLACE_CMD} -e "s|"$$"dir/../lib|${BOOT_WRKSRC}/lib/mlton|" \
		${WRKSRC}/bin/mlton-script
.endif
	@${REINPLACE_CMD} -e "s|no-mllex|${BOOT_WRKSRC}/bin/mllex|" \
		${WRKSRC}/mlton/front-end/Makefile \
		${WRKSRC}/mlyacc/Makefile
	@${REINPLACE_CMD} -e "s|no-mlyacc|${BOOT_WRKSRC}/bin/mlyacc|" \
		${WRKSRC}/mlton/front-end/Makefile \
		${WRKSRC}/mlyacc/Makefile
	@${REINPLACE_CMD} -e "s|! mlton |! ${BOOT_WRKSRC}/bin/mlton |" \
		${WRKSRC}/bin/upgrade-basis
	@${REINPLACE_CMD} -e \
		"s|/usr/local|${LOCALBASE}|" \
		${WRKSRC}/runtime/Makefile \
		${WRKSRC}/runtime/bytecode/Makefile \
		${WRKSRC}/runtime/cenv.h \
		${WRKSRC}/bin/add-cross \
		${WRKSRC}/bin/add-local-cross \
		${WRKSRC}/bin/regression \
		${WRKSRC}/bin/mlton-script \
		${WRKSRC}/doc/guide/PortingMLton \
		${WRKSRC}/doc/guide/SelfCompiling \
		${WRKSRC}/doc/guide/Installation \
		${WRKSRC}/regression/parse.sml
	@${REINPLACE_CMD} -e \
		"s|gcc|${CC}|" \
		${WRKSRC}/bin/add-cross \
		${WRKSRC}/bin/regression \
		${WRKSRC}/lib/mlnlffi-lib/Makefile \
		${WRKSRC}/mlnlffigen/gen-cppcmd \
		${WRKSRC}/mlnlffigen/README \
		${BOOT_WRKSRC}/lib/mlton/sml/mlrisc-lib/c-call/test/Makefile \
		${BOOT_WRKSRC}/lib/mlton/sml/mlrisc-lib/c-call/varargs/interp/Makefile
	@${REINPLACE_CMD} -e \
		"s|'gcc'|'${CC}'|" \
		${WRKSRC}/bin/mlton-script \
		${BOOT_WRKSRC}/bin/mlton
.if ! ${PORT_OPTIONS:MSMLNJ}
	@${REINPLACE_CMD} -e "s|/usr/local|${LOCALBASE}|" \
		${BOOT_WRKSRC}/lib/mlton/include/cenv.h
.endif
	@${RM} ${WRKSRC}/doc/guide/PortingMLton.bak \
		${WRKSRC}/doc/guide/SelfCompiling.bak \
		${WRKSRC}/doc/guide/Installation.bak

post-build:
	@${REINPLACE_CMD} -i '' -e '1s|/usr/bin/perl|${perl_CMD}|' \
		${WRKSRC}/build/lib/sml/mlrisc-lib/cm/makecm \
		${WRKSRC}/build/lib/sml/mlrisc-lib/cm/makeallcm \
		${WRKSRC}/build/lib/sml/mlrisc-lib/Doc/html/mltex2html

post-build-MINGW32-on:
	@${ECHO} Adding mingw32 target...
	${WRKSRC}/bin/add-local-cross mingw32 x86 mingw

.include <bsd.port.mk>
