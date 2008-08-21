# ex:ts=8
# New ports collection makefile for:	o3read
# Date created:                 Aug 07, 2008
# Whom:				samm
#
# $FreeBSD$

PORTNAME=	o3read
PORTVERSION=	0.0.4
CATEGORIES=	converters
MASTER_SITES=	http://siag.nu/pub/o3read/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	Standalone converter for the OpenOffice.org writer and scalc formats

MAN1=		o3read.1 utf8tolatin1.1
MLINKS=		o3read.1 o3totxt.1 o3read.1 o3tohtml.1
PORTDOCS=	README COPYING ChangeLog
PLIST_FILES=	bin/o3read bin/o3totxt bin/o3tohtml bin/utf8tolatin1

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/o3read ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/o3totxt ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/o3tohtml ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/utf8tolatin1 ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/o3read.1 ${MANPREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/utf8tolatin1.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
