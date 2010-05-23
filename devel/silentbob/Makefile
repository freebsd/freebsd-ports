# New ports collection makefile for:	silentbob
# Date created:		2008-11-13
# Whom:			TAKATSU Tomonari <tota@rtfm.jp>
#
# $FreeBSD$
#

PORTNAME=	silentbob
PORTVERSION=	2.3
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}2/${PORTNAME}-${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Yet another sourcecode indexing tool

USE_CMAKE=	yes

PORTDOCS=	*
PLIST_FILES=	bin/bob

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/lib/silent_bob/|${PREFIX}/lib/silent_bob/|' \
		${WRKSRC}/src/init.cxx

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
