# New ports collection makefile for:   checkrdf
# Date created:        17 december 2002
# Whom:                Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	checkrdf
PORTVERSION=	39.4444
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	checkrdf

MAINTAINER=	obraun@FreeBSD.org
COMMENT=	A tool for RDF site summaries based news-check

BUILD_DEPENDS=	Xtract:${PORTSDIR}/textproc/hs-haxml

USE_BZIP2=	yes

MAN1=		checkrdf.1
MANCOMPRESSED=	yes

PLIST_FILES=	bin/checkrdf bin/checkrdf.bin etc/checkrdf.rc
PORTDOCS=	README NEWS blog.news.css bluegreek.css myrdf.css

.if defined(NOPORTDOCS)
INSTALL_TARGET=install-bin install-rc install-man
.endif

.include <bsd.port.mk>
