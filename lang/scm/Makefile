# New ports collection makefile for:	scm
# Date created:		Sat Nov  5 17:11:01 PST 1994
# Whom:			hsu
#
# $FreeBSD$
#

PORTNAME=	scm
PORTVERSION=	5e1
CATEGORIES=	lang scheme
MASTER_SITES=	http://swissnet.ai.mit.edu/ftpdir/scm/%SUBDIR%/
MASTER_SITE_SUBDIR=	. OLD
DISTFILES=	scm5e1.zip slib3a2.zip slib-psd1-3.tar.gz
EXTRACT_ONLY=	scm5e1.zip slib3a2.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A scheme interpreter

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_ZIP=	yes
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
ALL_TARGET=	scmlit
MAN1=		scm.1
INFO=		scm

PLIST_SUB=	VERSION=${PORTVERSION}

SCM_DATA=	COPYING Iedline.scm Init${PORTVERSION}.scm Link.scm \
		Macexp.scm Macro.scm Transcen.scm Tscript.scm mkimpcat.scm \
		r4rstest.scm
SCM_MODULES=	byte.so crs.so edline.so gsubr.so ioext.so posix.so ramap.so \
		record.so rgx.so sc2.so socket.so unix.so

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not compile on !i386"
.endif

post-extract:
	@${TAR} -C ${WRKDIR} -zxf ${DISTDIR}/slib-psd1-3.tar.gz
	@${CP} ${FILESDIR}/require.scm.in ${WRKDIR}/require.scm

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKDIR}/require.scm
	@${REINPLACE_CMD} -e 's|%%CC%%|${CC}|g ; \
		 s|%%CFLAGS%%|${CFLAGS}|g ; \
		 s|%%X11BASE%%|${X11BASE}|g' ${WRKSRC}/build.scm

post-build:
	@cd ${WRKSRC} \
		&& SCMLIT="./scmlit" ${SH} ./build \
		 -F arrays \
		 -F bignums \
		 -F cautious \
		 -F engineering-notation \
		 -F inexact \
		 -F macro \
		 -F dynamic-linking \
		 -h system \
		 -o scm \
		 -s "${PREFIX}/lib/scm/" \
		&& SCMLIT="./scmlit" ${SH} ./build \
		 -F edit-line \
		 -h system \
		 -t dll \
		&& SCMLIT="./scmlit" ${SH} ./build \
		 -F curses \
		 -h system \
		 -t dll \
		&& SCMLIT="./scmlit" ${SH} ./build \
		 -c sc2.c \
		 -h system \
		 -t dll \
		&& SCMLIT="./scmlit" ${SH} ./build \
		 -c rgx.c \
		 -h system \
		 -t dll \
		&& SCMLIT="./scmlit" ${SH} ./build \
		 -c record.c \
		 -h system \
		 -t dll \
		&& SCMLIT="./scmlit" ${SH} ./build \
		 -c gsubr.c \
		 -h system \
		 -t dll \
		&& SCMLIT="./scmlit" ${SH} ./build \
		 -c ioext.c \
		 -h system \
		 -t dll \
		&& SCMLIT="./scmlit" ${SH} ./build \
		 -c posix.c \
		 -h system \
		 -t dll \
		&& SCMLIT="./scmlit" ${SH} ./build \
		 -c unix.c \
		 -h system \
		 -t dll \
		&& SCMLIT="./scmlit" ${SH} ./build \
		 -c socket.c \
		 -h system \
		 -t dll \
		&& SCMLIT="./scmlit" ${SH} ./build \
		 -c ramap.c \
		 -h system \
		 -t dll \
		&& SCMLIT="./scmlit" ${SH} ./build \
		 -c byte.c \
		 -h system \
		 -t dll

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
	${INSTALL_DATA} ${WRKDIR}/scm/scm.info ${PREFIX}/info
	cd ${PREFIX}/lib/scm && ${PREFIX}/bin/scm -lmkimpcat.scm

.include <bsd.port.post.mk>
