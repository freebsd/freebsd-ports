# New ports collection makefile for: canuum
# Version required:	1.0
# Date created:		20 Jan 1999
# Whom:			KIRIYAMA Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $Id: Makefile,v 1.1.1.1 1999/02/11 07:56:55 kuriyama Exp $
#

DISTNAME=	canuum-1.0
PKGNAME=	ja-canuum-1.0
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.nec.co.jp/pub/Canna/Canna22/
DISTFILES=	Uum4.109.tar.gz  Canna32p2.tar.gz
EXTRACT_ONLY=	Uum4.109.tar.gz

MAINTAINER=	kiri@pis.toba-cmt.ac.jp

LIB_DEPENDS=	canna.1:${PORTSDIR}/japanese/Canna

MANLANG=	ja
MAN1=		canuum.1
MAKE_ARGS=	PREFIX=${PREFIX}
WRKSRC=		${WRKDIR}/Canna32p2/canuum

post-extract:
	@${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/Canna32p2.tar.gz \
		${EXTRACT_AFTER_ARGS} -C ${WRKDIR} \
		Canna32p2/Canna.conf Canna32p2/canuum
	@${MV} ${WRKDIR}/Canna32p2/Canna.conf ${WRKSRC}/
	@${CP} ${WRKDIR}/Uum4.109/* ${WRKSRC}

pre-patch:
	@(cd ${WRKSRC}; ${PATCH} ${PATCH_DIST_ARGS} < Canuum.patch)

do-configure:
	@(cd ${WRKSRC}; xmkmf; make ${MAKE_ARGS} Makefile; \
	make ${MAKE_ARGS} cannaconf.h; make ${MAKE_ARGS} depend)

do-build:
	@(cd ${WRKSRC}; make ${MAKE_ARGS} all)

post-install:
	@${INSTALL_MAN} ${WRKSRC}/canuum.jmn ${PREFIX}/man/ja/man1/canuum.1

.include <bsd.port.mk>
