# ex:ts=8
# New ports collection makefile for:   dotconf
# Date created:                Jan 28, 2001
# Whom:                        Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dotconf
PORTVERSION=	1.0.2
CATEGORIES=	devel
MASTER_SITES=	http://www.azzit.de/dotconf/download/

MAINTAINER=	ijliao@FreeBSD.org

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

USE_GMAKE=	yes

INSTALLS_SHLIB=	yes

post-install:
	${MKDIR} ${PREFIX}/share/${PORTNAME}
.if !defined(NOPORTDOCS)
.for f in dotconf-api.txt dotconf-features.txt
	@${INSTALL_DATA} ${WRKSRC}/doc/$f ${PREFIX}/share/${PORTNAME}
.endfor
.endif
	${CP} -R ${WRKSRC}/examples ${PREFIX}/share/${PORTNAME}

.include <bsd.port.mk>
