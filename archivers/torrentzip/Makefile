# New ports collection makefile for:    torrentzip
# Date created:         May 2, 2005
# Whom:                 swhetzel@gmail.com
#
# $FreeBSD$
#

PORTNAME=	torrentzip
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	trrntzip
DISTNAME=	trrntzip_v${PORTVERSION:S/.//}_src

MAINTAINER=	swhetzel@gmail.com
COMMENT=	Efficient way to prepare zipfiles for BitTorrent

USE_AUTOTOOLS=	aclocal:19 automake:19 autoheader:259
AUTOMAKE_ARGS=		-a

WRKSRC=		${WRKDIR}/trrntzip

PLIST_FILES=	bin/trrntzip
PORTDOCS=	README

run-autotools:: run-autotools-aclocal run-autotools-autoheader \
		run-autotools-autoconf run-autotools-automake

.if !defined(NOPORTDOCS)
pre-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
.endif

.include <bsd.port.mk>
