# ex:ts=8
# New ports collection makefile for:   Maaate
# Date created:                Fab 12, 2001
# Whom:                        Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Maaate
PORTVERSION=	0.1.0
CATEGORIES=	audio
MASTER_SITES=	http://www.cmis.csiro.au/dmis/maaate/

MAINTAINER=	ijliao@FreeBSD.org

USE_AUTOCONF=	yes
USE_LIBTOOL=	yes

USE_GMAKE=	yes

INSTALLS_SHLIB=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/Maaate
	@${CP} ${WRKSRC}/doc/* ${PREFIX}/share/doc/Maaate
.endif

.include <bsd.port.mk>
