# New ports collection makefile for:	lyx-doc
# Version required:	1.0.3
# Date created:		10 Nov 1999
# Whom:			KIRIYAMA Kazuhiko <kiri@pis.toba-cmt.ac.jp>
#
# $FreeBSD$
#

DISTNAME=	ja_LyX_Doc.1.0.3
PKGNAME=	ja-lyx_doc-1.0.3
CATEGORIES=	japanese print
MASTER_SITES=	http://www.hiei.kit.ac.jp/~hitomi/lyx/

MAINTAINER=	kiri@pis.toba-cmt.ac.jp

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

LYXDOCDIR=	${PREFIX}/share/lyx/doc

do-install:
	${MKDIR} ${LYXDOCDIR}
	${INSTALL_DATA} ${WRKDIR}/*.lyx ${WRKDIR}/*.eps ${LYXDOCDIR}

.include <bsd.port.mk>
