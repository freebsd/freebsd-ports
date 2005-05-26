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

USE_AUTOMAKE_VER=	19
AUTOMAKE_ARGS=		-a
USE_AUTOHEADER_VER=	259

WRKSRC=		${WRKDIR}/trrntzip

PLIST_FILES=	bin/trrntzip
PORTDOCS=	README

run-autotools:
	(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${ACLOCAL} ${ACLOCAL_ARGS})
	(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTOHEADER} ${AUTOHEADER_ARGS})
	(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTOCONF} ${AUTOCONF_ARGS})
	(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTOMAKE} ${AUTOMAKE_ARGS})

.if !defined(NOPORTDOCS)
pre-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
.endif

.include <bsd.port.mk>
