# New ports collection makefile for:	lyx-doc
# Version required:	1.0.3
# Date created:		10 Nov 1999
# Whom:			KIRIYAMA Kazuhiko <kiri@pis.toba-cmt.ac.jp>
#
# $FreeBSD$
#

DISTNAME=	jp_LyX_Doc.1.0.3
PKGNAME=	ja-lyx_doc-1.0.3
CATEGORIES=	japanese print
MASTER_SITES=	http://www.hiei.kit.ac.jp/~hitomi/lyx/

MAINTAINER=	kiri@pis.toba-cmt.ac.jp

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PORTDOCDIR=	${PREFIX}/share/doc/lyx

do-install:
	${MKDIR} ${PORTDOCDIR}
	${INSTALL_DATA} ${WRKDIR}/*.lyx ${WRKDIR}/*.eps ${PORTDOCDIR}

.include <bsd.port.mk>
