# ex:ts=8
# New ports collection makefile for:   dotconf
# Date created:                Jan 28, 2001
# Whom:                        Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dotconf
PORTVERSION=	1.0.4
CATEGORIES=	devel
MASTER_SITES=	http://www.azzit.de/dotconf/download/

MAINTAINER=	ports@FreeBSD.org

USE_LIBTOOL=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

post-install:
	${MKDIR} ${DATADIR}
.if !defined(NOPORTDOCS)
.for f in dotconf-api.txt dotconf-features.txt
	@${INSTALL_DATA} ${WRKSRC}/doc/$f ${DATADIR}
.endfor
.endif
	${CP} -R ${WRKSRC}/examples ${DATADIR}

.include <bsd.port.mk>
