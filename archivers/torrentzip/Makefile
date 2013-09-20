# Created by: swhetzel@gmail.com
# $FreeBSD$

PORTNAME=	torrentzip
PORTVERSION=	0.2
PORTREVISION=	3
CATEGORIES=	archivers
MASTER_SITES=	SF/trrntzip/trrntzip/TorrentZip%20v${PORTVERSION}
DISTNAME=	trrntzip_v${PORTVERSION:S/.//}_src

MAINTAINER=	swhetzel@gmail.com
COMMENT=	Efficient way to prepare zipfiles for BitTorrent

NO_STAGE=	yes
USE_AUTOTOOLS=	aclocal automake autoheader
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
