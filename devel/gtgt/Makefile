# ex:ts=8
# New ports collection makefile for:   gtgt
# Date created:                Feb 13, 2001
# Whom:                        Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtgt
PORTVERSION=	3.0.0
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General (or GNU) template generation tools

USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/gcng bin/gptg bin/gscg
PORTDOCS=	autoconf.html automake.html \
		company-license.long company-license.short \
		gtgt.gif gtgt.html gtgt.txt \
		index.html libtool.html

do-install:
.for file in gcng gptg gscg
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/${file} ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
