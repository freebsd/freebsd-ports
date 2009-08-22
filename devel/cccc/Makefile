# ex:ts=8
# New ports collection makefile for:	cccc
# Date created:				12 September 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	cccc
PORTVERSION=	3.1.4
CATEGORIES=	devel textproc www
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C and C++ Code Counter

BUILD_DEPENDS=	antlr:${PORTSDIR}/devel/pccts \
		dlg:${PORTSDIR}/devel/pccts

USE_GMAKE=	yes
MAKEFILE=	makefile

PORTDOCS=	readme.txt changes.txt
PLIST_FILES=	bin/cccc

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/cccc/cccc ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
