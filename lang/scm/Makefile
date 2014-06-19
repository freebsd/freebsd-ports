# Created by: hsu
# $FreeBSD$

PORTNAME=	scm
PORTVERSION=	5f1
PORTREVISION=	1
CATEGORIES=	lang scheme
MASTER_SITES=	http://groups.csail.mit.edu/mac/ftpdir/scm/%SUBDIR%/
MASTER_SITE_SUBDIR=	. OLD
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} slib-3b4.zip slib-psd1-3.tar.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} slib-3b4.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Scheme interpreter

LICENSE=	LGPL21

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		gmake readline zip
USE_GCC=	any
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	--prefix=${PREFIX}
MAKE_JOBS_UNSAFE=	yes

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

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

post-extract:
	@${TAR} -C ${WRKDIR} -zxf ${DISTDIR}/slib-psd1-3.tar.gz

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/include|${LOCALBASE}/include| ; \
		 /strip/s|^|#|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|%%CC%%|${CC}|g ; \
		 s|%%CFLAGS%%|${CFLAGS}|g ; \
		 s|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/build.scm
	@${REINPLACE_CMD} -e 's|__osf__|__FreeBSD__|' ${WRKSRC}/gmalloc.c
	@${REINPLACE_CMD} -e 's|gnuregex\.h|gnu/regex.h|g' ${WRKSRC}/rgx.c
	@${REINPLACE_CMD} -e 's|/usr/include|${LOCALBASE}/include|g' \
		${WRKSRC}/xgen.scm

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} scm scmlit \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} scm.1 \
		${STAGEDIR}${MANPREFIX}/man/man1)
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/scm
	(cd ${WRKDIR} && ${INSTALL_DATA} require.scm \
		${STAGEDIR}${PREFIX}/lib/scm)
.for i in ${SCM_DATA}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${PREFIX}/lib/scm)
.endfor
.for i in ${SCM_MODULES}
	(cd ${WRKSRC} && ${INSTALL_LIB} ${i} \
		${STAGEDIR}${PREFIX}/lib/scm)
.endfor
.if ${PORT_OPTIONS:MX11}
.for i in ${SCM_DATA_X11}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${PREFIX}/lib/scm)
.endfor
.for i in ${SCM_MODULES_X11}
	(cd ${WRKSRC} && ${INSTALL_LIB} ${i} \
		${STAGEDIR}${PREFIX}/lib/scm)
.endfor
.endif
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/scm/slib
	(cd ${WRKDIR}/slib && ${INSTALL_DATA} *.scm \
		${STAGEDIR}${PREFIX}/lib/scm/slib)
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/scm/slib/psd
	(cd ${WRKDIR}/slib/psd && ${INSTALL_DATA} *.scm \
		${STAGEDIR}${PREFIX}/lib/scm/slib/psd)
	(cd ${WRKDIR}/scm && ${INSTALL_DATA} scm.info \
		${STAGEDIR}${PREFIX}/${INFO_PATH})

.include <bsd.port.mk>
