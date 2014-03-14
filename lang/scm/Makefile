# Created by: hsu
# $FreeBSD$

PORTNAME=	scm
PORTVERSION=	5f1
CATEGORIES=	lang scheme
MASTER_SITES=	http://groups.csail.mit.edu/mac/ftpdir/scm/%SUBDIR%/
MASTER_SITE_SUBDIR=	. OLD
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} slib-3b4.zip slib-psd1-3.tar.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} slib-3b4.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Scheme interpreter

LICENSE=	LGPL21

OPTIONS_DEFINE=	X11

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		gmake readline zip
USE_GCC=	any
MAKE_JOBS_UNSAFE=	yes

SUB_FILES=	require.scm

PLIST_SUB=	VERSION="${PORTVERSION}"

MAN1=		scm.1
INFO=		scm

SCM_DATA=	COPYING COPYING.LESSER Iedline.scm Idiffer.scm \
		Init${PORTVERSION}.scm Link.scm Macexp.scm Macro.scm \
		Transcen.scm Tscript.scm build build.scm compile.scm \
		hobbit.scm mkimpcat.scm patchlvl.h \
		r4rstest.scm rwb-isam.scm scmhob.h scmhob.scm wbtab.scm
SCM_MODULES=	byte.so bytenumb.so crs.so differ.so edline.so gsubr.so \
		ioext.so posix.so ramap.so record.so rgx.so sc2.so \
		socket.so unix.so

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
USE_XORG=	ice sm x11 xext
PLIST_SUB+=	X11=""
SCM_DATA+=	keysymdef.scm x11.scm xatoms.scm xevent.scm
SCM_MODULES+=	x.so
.else
PLIST_SUB+=	X11="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

.if ${OSVERSION} > 1000000
READLINE_DIR=	${LOCALBASE}
.else
READLINE_DIR=	/usr
.endif

post-extract:
	@${TAR} -C ${WRKDIR} -zxf ${DISTDIR}/slib-psd1-3.tar.gz

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/include|${LOCALBASE}/include|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|%%CC%%|${CC}|g ; \
		 s|%%CFLAGS%%|${CFLAGS}|g ; \
		 s|%%READLINE_DIR%%|${READLINE_DIR}|g ; \
		 s|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/build.scm
	@${REINPLACE_CMD} -e 's|gnuregex\.h|gnu/regex.h|g' ${WRKSRC}/rgx.c
	@${REINPLACE_CMD} -e 's|/usr/include|${LOCALBASE}/include|g' \
		${WRKSRC}/xgen.scm

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} scm ${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} scmlit ${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} scm.1 ${MANPREFIX}/man/man1)
	@${MKDIR} ${PREFIX}/lib/scm
	(cd ${WRKDIR} && ${INSTALL_DATA} require.scm ${PREFIX}/lib/scm)
.for i in ${SCM_DATA} ${SCM_MODULES}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${PREFIX}/lib/scm)
.endfor
	@${MKDIR} ${PREFIX}/lib/scm/slib
	(cd ${WRKDIR}/slib && ${INSTALL_DATA} *.scm ${PREFIX}/lib/scm/slib)
	@${MKDIR} ${PREFIX}/lib/scm/slib/psd
	(cd ${WRKDIR}/slib/psd && ${INSTALL_DATA} *.scm \
		${PREFIX}/lib/scm/slib/psd)
	(cd ${WRKDIR}/scm && ${INSTALL_DATA} scm.info ${PREFIX}/${INFO_PATH})
	(cd ${PREFIX}/lib/scm && ${PREFIX}/bin/scm -lmkimpcat.scm)

.include <bsd.port.post.mk>
