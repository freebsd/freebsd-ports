# New ports collection makefile for:	lyx-doc
# Date created:		10 Nov 1999
# Whom:			KIRIYAMA Kazuhiko <kiri@pis.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	lyx_doc
PORTVERSION=	1.0.3
CATEGORIES=	japanese print
MASTER_SITES=	http://www.hiei.kit.ac.jp/~hitomi/lyx/
DISTNAME=	ja_LyX_Doc.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese Lyx documents translated from original ones

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

LYXDOCDIR=	${PREFIX}/share/lyx/doc

do-install:
	${MKDIR} ${LYXDOCDIR}
	${INSTALL_DATA} ${WRKDIR}/*.lyx ${WRKDIR}/*.eps ${LYXDOCDIR}

.include <bsd.port.mk>
