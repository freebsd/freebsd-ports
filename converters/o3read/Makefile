# Created by: samm
# $FreeBSD$

PORTNAME=	o3read
PORTVERSION=	0.0.4
CATEGORIES=	converters
MASTER_SITES=	http://siag.nu/pub/o3read/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	Standalone converter for the OpenOffice.org writer and scalc formats

PORTDOCS=	README COPYING ChangeLog

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/o3read ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/o3totxt ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/o3tohtml ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/utf8tolatin1 ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/*.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for FILE in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
