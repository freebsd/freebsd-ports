# New ports collection makefile for: ee
# Date created:		20 Jan 1999
# Whom:			KIRIYAMA Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	jee
PORTVERSION=	1.0
CATEGORIES=	japanese editors
MASTER_SITES=	ftp://ftp.mogami-wire.co.jp/pub/beta/ \
		${MASTER_SITE_PORTS_JP}
DISTFILES=	${PORTNAME}.tar.gz \
		ee-3.0.tar.gz \
		libncurses-3.0.tar.gz
EXTRACT_ONLY=	ee-3.0.tar.gz

MAINTAINER=	kiri@pis.toba-cmt.ac.jp

LIB_DEPENDS=	canna.1:${PORTSDIR}/japanese/Canna

MANLANG=	ja
MAN1=		jee.1
WRKSRC=		${WRKDIR}/ee

post-extract:
.for f in ${PORTNAME}.tar.gz libncurses-3.0.tar.gz
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${f} \
		${EXTRACT_AFTER_ARGS} -C ${WRKSRC}
.endfor
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
