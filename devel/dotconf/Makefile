# ex:ts=8
# New ports collection makefile for:   dotconf
# Date created:                Jan 28, 2001
# Whom:                        Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dotconf
PORTVERSION=	1.0.0p2
CATEGORIES=	devel
MASTER_SITES=	http://www.azzit.de/dotconf/download/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/p/pre/}

MAINTAINER=	ijliao@FreeBSD.org

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

USE_GMAKE=	yes

INSTALLS_SHLIB=	yes

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/${PORTNAME}
.for f in dotconf-api.txt dotconf-features.txt
	@${INSTALL_DATA} ${WRKSRC}/doc/$f ${PREFIX}/share/${PORTNAME}
.endfor
	${CP} -R ${WRKSRC}/examples ${PREFIX}/share/${PORTNAME}
.endif

.include <bsd.port.mk>
