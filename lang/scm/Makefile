PORTNAME=	scm
PORTVERSION=	5f3
CATEGORIES=	lang scheme
MASTER_SITES=	GNU:scm	\
		http://groups.csail.mit.edu/mac/ftpdir/scm/:psd1
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:scm slib-psd1-3.tar.gz:psd1
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Scheme interpreter
WWW=		https://people.csail.mit.edu/jaffer/SCM

LICENSE=	LGPL3+
LICENSE_FILES=	${WRKSRC}/COPYING.LESSER

LIB_DEPENDS=	libgnuregex.so:devel/libgnuregex
BUILD_DEPENDS=	${LOCALBASE}/share/slib/require.scm:lang/slib
RUN_DEPENDS=	${LOCALBASE}/share/slib/require.scm:lang/slib

USES=		readline

HAS_CONFIGURE=	yes
CONFIGURE_ENV=	--prefix=${PREFIX}
MAKE_JOBS_UNSAFE=	yes

CFLAGS:=	${CFLAGS:N-O*} -O0
CFLAGS+=	-Wall -Wwrite-strings -Wmissing-declarations -Wredundant-decls -Wcast-qual
CFLAGS+=	-Wno-unused-label -Wno-uninitialized

SUB_FILES=	require.scm

PLIST_SUB=	VERSION="${PORTVERSION}"

PKGDEINSTALL=	${PKGINSTALL}

INFO=		scm

OPTIONS_DEFINE=		X11
OPTIONS_SUB=		yes

X11_USES=		xorg
X11_USE=		xorg=ice,sm,x11,xext
TEST_TARGET=	check checkmacro

SCM_DATA=	COPYING COPYING.LESSER Iedline.scm Idiffer.scm \
		Init${PORTVERSION}.scm Link.scm Macexp.scm Macro.scm \
		Transcen.scm Tscript.scm build build.scm compile.scm \
		hobbit.scm mkimpcat.scm patchlvl.h \
		r4rstest.scm scmhob.h scmhob.scm
SCM_DATA_X11=	keysymdef.scm x11.scm xatoms.scm xevent.scm
SCM_MODULES=	byte.so bytenumb.so differ.so edline.so gsubr.so \
		ioext.so posix.so ramap.so record.so rgx.so sc2.so \
		socket.so unix.so
SCM_MODULES_X11=x.so

post-extract:
	${LN} -s ${LOCALBASE}/share/slib ${WRKDIR}

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc64*}
USES+=		compiler:gcc-c++11-lib
.endif

.if ${ARCH} == aarch64 || ${ARCH} == riscv64
CFLAGS+=	-DLACK_SBRK
.endif

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MX11}
SCM_MODULES+=	${SCM_MODULES_X11}
SCM_DATA+=	${SCM_DATA_X11}
.endif

LIBEDIT_SUB1=	${CPPFLAGS}" "${LDFLAGS:M-L*}
LIBEDIT_SUB2=	${LDFLAGS:M-L*}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/include|${LOCALBASE}/include| ; \
		 /strip/s|^|#|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|%%CC%%|${CC}|g ; \
		 s|%%CFLAGS%%|${CFLAGS}|g ; \
		 s|%%ARCHOBJS%%|${ARCHOBJS}|g ; \
		 s|editline freebsd "" "|editline freebsd "${LIBEDIT_SUB1}| ; \
		 s|-lreadline")$$|${LIBEDIT_SUB2} -lreadline")| ; \
		 s|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/build.scm
	@${REINPLACE_CMD} -e 's|__osf__|__FreeBSD__|' ${WRKSRC}/gmalloc.c
	@${REINPLACE_CMD} -e 's|gnuregex\.h|gnu/regex.h|g' ${WRKSRC}/rgx.c
	@${REINPLACE_CMD} -e 's|/usr/include|${LOCALBASE}/include|g' \
		${WRKSRC}/xgen.scm
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g'	\
		${WRKSRC}/*.info ${WRKSRC}/*.texi
	${TOUCH} ${WRKSRC}/scm.core

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/scm ${WRKSRC}/scmlit \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/scm.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/scm
	${INSTALL_DATA} ${WRKDIR}/require.scm ${SCM_DATA:S|^|${WRKSRC}/|} \
		${STAGEDIR}${PREFIX}/lib/scm
	${INSTALL_LIB} ${SCM_MODULES:S|^|${WRKSRC}/|} \
		${STAGEDIR}${PREFIX}/lib/scm
	${TAR} -C ${STAGEDIR}${PREFIX}/lib/scm -xf ${DISTDIR}/${_DISTFILES:Mslib*.tar.gz} '*.scm'
	${INSTALL_DATA} ${WRKSRC}/scm.info ${STAGEDIR}${PREFIX}/${INFO_PATH}

.include <bsd.port.post.mk>
