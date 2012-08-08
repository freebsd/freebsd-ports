# New ports collection makefile for:   checkrdf
# Date created:        17 december 2002
# Whom:                Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	checkrdf
PORTVERSION=	39.4444
PORTREVISION=	6
CATEGORIES=	deskutils
MASTER_SITES=	SF

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A tool for RDF site summaries based news-check

LICENSE=	BSD

BUILD_DEPENDS=	hs-HaXml>=1.19:${PORTSDIR}/textproc/hs-HaXml

USE_BZIP2=	yes

MAN1=		checkrdf.1
MANCOMPRESSED=	yes

PLIST_FILES=	bin/checkrdf bin/checkrdf.bin etc/checkrdf.rc
PORTDOCS=	README NEWS blog.news.css bluegreek.css myrdf.css

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	DOCS

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MDOCS)
INSTALL_TARGET=install-bin install-rc install-man
.endif

.include <bsd.port.mk>
