# New ports collection makefile for:	scm
# Date created:		Sat Nov  5 17:11:01 PST 1994
# Whom:			hsu
#
# $FreeBSD$
#

PORTNAME=	scm
PORTVERSION=	5e6
CATEGORIES=	lang scheme
MASTER_SITES=	http://groups.csail.mit.edu/mac/ftpdir/scm/%SUBDIR%/ \
		ftp://ftp.informatik.uni-hamburg.de/ftpmnt/inf1/pub/soft/lang/scheme/
MASTER_SITE_SUBDIR=	. OLD
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} slib-3b2.zip slib-psd1-3.tar.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} slib-3b2.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A scheme interpreter

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_ZIP=	yes
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" IMPLPATH="${PREFIX}/lib/scm/" \
		SCMLIT="./scmlit"
ALL_TARGET=	scmlit scm5 mydlls
MAN1=		scm.1
INFO=		scm

PLIST_SUB=	VERSION="${PORTVERSION}"

SUB_FILES=	require.scm

SCM_DATA=	COPYING COPYING.LESSER Iedline.scm Idiffer.scm \
		Init${PORTVERSION}.scm Link.scm Macexp.scm Macro.scm \
		Transcen.scm Tscript.scm build build.scm compile.scm \
		hobbit.scm keysymdef.scm mkimpcat.scm patchlvl.h \
		r4rstest.scm rwb-isam.scm scmhob.h scmhob.scm wbtab.scm \
		x11.scm xatoms.scm xevent.scm
SCM_MODULES=	byte.so bytenumb.so crs.so differ.so edline.so gsubr.so \
		ioext.so posix.so ramap.so record.so rgx.so sc2.so \
		socket.so unix.so

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ${ARCH}
.endif

.if defined(WITH_X11)
USE_XORG=	ice sm x11 xext
SCM_MODULES+=	x.so
PLIST_SUB+=	X11=""
.else
PLIST_SUB+=	X11="@comment "
.endif

post-extract:
	@${TAR} -C ${WRKDIR} -zxf ${DISTDIR}/slib-psd1-3.tar.gz

post-patch:
	@${REINPLACE_CMD} -e 's|exec ./scmlit|exec $$SCMLIT|g' ${WRKSRC}/build
	@${REINPLACE_CMD} -e 's|%%CC%%|${CC}|g ; \
		 s|%%CFLAGS%%|${CFLAGS}|g ; \
		 s|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/build.scm
	@${REINPLACE_CMD} -e 's|gnuregex\.h|gnu/regex.h|g' ${WRKSRC}/rgx.c

post-build:
	@cd ${WRKSRC} \
		&& SCMLIT="./scmlit" ${SH} ./build \
		 -c differ.c \
		 -h system \
		 -t dll
.if defined(WITH_X11)
	@cd ${WRKSRC} \
		&& SCMLIT="./scmlit" ${SH} ./build \
		 -F x \
		 -h system \
		 -t dll
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/scm ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/scmlit ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/scm.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${PREFIX}/lib/scm
	${INSTALL_DATA} ${WRKDIR}/require.scm ${PREFIX}/lib/scm
.for file in ${SCM_DATA} ${SCM_MODULES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/lib/scm
.endfor
	@${MKDIR} ${PREFIX}/lib/scm/slib
	${INSTALL_DATA} ${WRKDIR}/slib/*.scm ${PREFIX}/lib/scm/slib
	@${MKDIR} ${PREFIX}/lib/scm/slib/psd
	${INSTALL_DATA} ${WRKDIR}/slib/psd/*.scm ${PREFIX}/lib/scm/slib/psd
	${INSTALL_DATA} ${WRKDIR}/scm/scm.info ${PREFIX}/${INFO_PATH}
	cd ${PREFIX}/lib/scm && ${PREFIX}/bin/scm -lmkimpcat.scm

.include <bsd.port.post.mk>
