# New ports collection makefile for: ee
# Version required:	1.0
# Date created:		20 Jan 1999
# Whom:			KIRIYAMA Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $Id$
#

DISTNAME=	jee-1.0
PKGNAME=	ja-jee-1.0
CATEGORIES=	editors japanese
MASTER_SITES=	ftp://ftp.mogami-wire.co.jp/pub/beta/ \
		ftp://ports.jp.freebsd.org/pub/FreeBSD-jp/ports-jp/LOCAL_PORTS/ \
		ftp://ports.jp.freebsd.org/pub/FreeBSD-jp/LOCAL_PORTS/ \
		ftp://ports.jp.freebsd.org/pub/FreeBSD-jp/ports-jp/incoming/japanese/
DISTFILES=	jee.tar.gz \
		libncurses-3.0.tar.gz \
		ee-3.0.tar.gz

MAINTAINER=	kiri@pis.toba-cmt.ac.jp

LIB_DEPENDS=	canna.1:${PORTSDIR}/japanese/Canna

MANLANG=	ja
MAN1=		jee.1
WRKSRC=		${WRKDIR}/ee

do-extract:
	@${MKDIR} ${WRKSRC}
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/jee.tar.gz \
		${EXTRACT_AFTER_ARGS} -C ${WRKSRC}
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/ee-3.0.tar.gz \
		${EXTRACT_AFTER_ARGS} -C ${WRKDIR}
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/libncurses-3.0.tar.gz \
		${EXTRACT_AFTER_ARGS} -C ${WRKSRC}
	${MV} ${WRKSRC}/libncurses ${WRKSRC}/curses

post-patch:
	@${PATCH} ${PATCH_DIST_ARGS} < ${WRKSRC}/ee.patch
	@${PATCH} ${PATCH_DIST_ARGS:S@${WRKSRC}@${WRKSRC}/curses@} \
		< ${WRKSRC}/ncurses.patch
do-build:
	@(cd ${WRKSRC}/curses; ${MAKE} keys.tries.h; ${MAKE})
	@(cd ${WRKSRC}; ${MAKE} -f makefile)

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/ee ${PREFIX}/bin/jee
	@${INSTALL_MAN} ${WRKSRC}/jee.1 ${PREFIX}/man/ja/man1/

.include <bsd.port.mk>
