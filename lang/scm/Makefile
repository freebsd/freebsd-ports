# Created by: hsu
# $FreeBSD$

PORTNAME=	scm
PORTVERSION=	5f2
PORTREVISION=	1
CATEGORIES=	lang scheme
MASTER_SITES=	http://groups.csail.mit.edu/mac/ftpdir/scm/%SUBDIR%/
MASTER_SITE_SUBDIR=	. OLD
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} slib-3b5.zip slib-psd1-3.tar.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Scheme interpreter

LICENSE=	LGPL21

BROKEN_powerpc64=	Does not build

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		readline zip
USE_GCC=	any
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	--prefix=${PREFIX}
MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-Wall -Wwrite-strings -Wmissing-declarations -Wredundant-decls -Wcast-qual
CFLAGS+=	-Wno-unused-label -Wno-uninitialized

SUB_FILES=	require.scm

PLIST_SUB=	VERSION="${PORTVERSION}"

PKGDEINSTALL=	${PKGINSTALL}

INFO=		scm

OPTIONS_DEFINE=		X11
OPTIONS_SUB=		yes

X11_USE=		xorg=ice,sm,x11,xext

SCM_DATA=	COPYING COPYING.LESSER Iedline.scm Idiffer.scm \
		Init${PORTVERSION}.scm Link.scm Macexp.scm Macro.scm \
		Transcen.scm Tscript.scm build build.scm compile.scm \
		hobbit.scm mkimpcat.scm patchlvl.h \
		r4rstest.scm rwb-isam.scm scmhob.h scmhob.scm wbtab.scm
SCM_DATA_X11=	keysymdef.scm x11.scm xatoms.scm xevent.scm
SCM_MODULES=	byte.so bytenumb.so crs.so differ.so edline.so gsubr.so \
		ioext.so posix.so ramap.so record.so rgx.so sc2.so \
		socket.so unix.so
SCM_MODULES_X11=x.so

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
SCM_MODULES+=	${SCM_MODULES_X11}
SCM_DATA+=	${SCM_DATA_X11}
.endif

.if ${ARCH} == "ia64"
EXTRA_PATCHES+=	${FILESDIR}/ia64-patch
ARCHOBJS=	continue-ia64.S
.endif

post-extract:
	# Certain .scm files are needed during build:
	@${TAR} -C ${WRKDIR} -zxf ${DISTDIR}/${DISTFILES:Mslib*.zip} '*.scm'

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/include|${LOCALBASE}/include| ; \
		 /strip/s|^|#|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|%%CC%%|${CC}|g ; \
		 s|%%CFLAGS%%|${CFLAGS}|g ; \
		 s|%%ARCHOBJS%%|${ARCHOBJS}|g ; \
		 s|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/build.scm
	@${REINPLACE_CMD} -e 's|__osf__|__FreeBSD__|' ${WRKSRC}/gmalloc.c
	@${REINPLACE_CMD} -e 's|gnuregex\.h|gnu/regex.h|g' ${WRKSRC}/rgx.c
	@${REINPLACE_CMD} -e 's|/usr/include|${LOCALBASE}/include|g' \
		${WRKSRC}/xgen.scm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/scm ${WRKSRC}/scmlit \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/scm.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/scm
	${INSTALL_DATA} ${WRKDIR}/require.scm ${SCM_DATA:S|^|${WRKSRC}/|} \
		${STAGEDIR}${PREFIX}/lib/scm
	${INSTALL_LIB} ${SCM_MODULES:S|^|${WRKSRC}/|} \
		${STAGEDIR}${PREFIX}/lib/scm
	${TAR} -C ${STAGEDIR}${PREFIX}/lib/scm -xf ${DISTDIR}/${DISTFILES:Mslib*.tar.gz} '*.scm'
	${INSTALL_DATA} ${WRKDIR}/slib/*.scm ${STAGEDIR}${PREFIX}/lib/scm/slib/
	${INSTALL_DATA} ${WRKDIR}/scm/scm.info ${STAGEDIR}${PREFIX}/${INFO_PATH}

.include <bsd.port.mk>
