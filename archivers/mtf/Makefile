# New ports collection makefile for:   mtf
# Date created:        29 January 2002
# Whom:                Philippe Casidy <pcasidy@casidy.com>
#
# $FreeBSD$
#

PORTNAME=	mtf
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/backup
EXTRACT_SUFX=	.tgz

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	A Unix reader for the Microsoft Tape Format used by NT Backup

ALL_TARGET=	# empty
PLIST_FILES=	bin/mtf
PORTDOCS=	README

post-patch:
	@${REINPLACE_CMD} -e "s|CC=|CC?=|" \
			-e "s|CFLAGS=|CFLAGS?=|" \
			${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mtf ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
