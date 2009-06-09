# New ports collection makefile for:	head files and libraries of Wnn7
# Date created:		01/07/16
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Wnn7-lib
PORTVERSION=	2001.10.17
PORTREVISION=	2
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.omronsoft.co.jp/pub/Wnn7/sdk_source/
DISTNAME=	Wnn7SDK
EXTRACT_SUFX=	.tgz

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Wnn7 client library

USE_IMAKE=	yes
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/src
PORTDOCS=	README

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},g' \
		${WRKSRC}/config/Project.tmpl \
		${WRKSRC}/config/X11.tmpl \
		${WRKSRC}/Makefile.ini

# Warning: we cannot use USE_IMAKE.
do-build:
	cd ${WRKSRC} && make World -f Makefile.ini

post-install:
	${MKDIR} ${PREFIX}/include/wnn7/wnn
	${INSTALL_DATA} ${WRKSRC}/Wnn/include/*.h ${PREFIX}/include/wnn7/wnn
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
