# ex:ts=8
# New ports collection makefile for:   Maaate
# Date created:                Fab 12, 2001
# Whom:                        Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Maaate
PORTVERSION=	0.2.2
CATEGORIES=	audio
MASTER_SITES=	http://www.cmis.csiro.au/maaate/packages/

MAINTAINER=	ports@FreeBSD.org

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -E -e "s,-ldl,,g ; s,\(CCLD,(CXXLD,g" ${WRKSRC}/demos/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/Maaate
	@${CP} ${WRKSRC}/doc/* ${PREFIX}/share/doc/Maaate
.endif

.include <bsd.port.mk>
