# New ports collection makefile for:	scm
# Date created:		Sat Nov  5 17:11:01 PST 1994
# Whom:			hsu
#
# $FreeBSD$
#

PORTNAME=	scm
PORTVERSION=	5d4
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.swiss.ai.mit.edu/pub/scm/
DISTFILES=	scm5d4.zip slib2d2.zip slib-psd1-3.tar.gz

MAINTAINER=	ports@FreeBSD.org

EXTRACT_ONLY=	scm5d4.zip slib2d2.zip

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_ZIP=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
ALL_TARGET=	scmlit
MAN1=		scm.1

PLIST_SUB=	VERSION=${PORTVERSION}

SCM_DATA=	COPYING Iedline.scm Init${PORTVERSION}.scm Link.scm \
		Macexp.scm Macro.scm Transcen.scm Tscript.scm mkimpcat.scm

post-extract:
	@${TAR} -C ${WRKDIR} -zxf ${_DISTDIR}/slib-psd1-3.tar.gz

do-configure:
	@${SED} -e "s:%%PREFIX%%:${PREFIX}:g" \
		${FILESDIR}/require.scm.in > ${WRKDIR}/require.scm

post-build:
	cd ${WRKSRC}; SCMLIT="./scmlit" ${SH} ./build \
		-F "arrays bignums cautious inexact" \
		-h system \
		-o scm \
		-s "${DATADIR}/"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/scm ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/scm.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/require.scm ${DATADIR}
.for file in ${SCM_DATA}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DATADIR}
.endfor
	@touch ${DATADIR}/implcat
	@touch ${DATADIR}/slibcat
	@${MKDIR} ${DATADIR}/slib
	${INSTALL_DATA} ${WRKDIR}/slib/*.scm ${DATADIR}/slib
	@${MKDIR} ${DATADIR}/slib/psd
	${INSTALL_DATA} ${WRKDIR}/slib/psd/*.scm ${DATADIR}/slib/psd
	${INSTALL_DATA} ${WRKDIR}/scm/scm.info ${PREFIX}/info
	@install-info ${PREFIX}/info/scm.info ${PREFIX}/info/dir
	${INSTALL_DATA} ${WRKDIR}/slib/slib.info ${PREFIX}/info
	@install-info ${PREFIX}/info/slib.info ${PREFIX}/info/dir

.include <bsd.port.mk>
