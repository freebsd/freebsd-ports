# New ports collection makefile for: 	Ninja-irc
# Date created:	 	10 April 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ninja
PORTVERSION=	1.2
CATEGORIES=	irc
MASTER_SITES=	ftp://ninja.qoop.org/ninja/unstable/
DISTNAME= 	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes
PLIST_SUB=	VERSION="${PORTVERSION}"
WRKSRC=		${WRKDIR}/${PKGNAME}

pre-patch:
	@${CP} ${WRKSRC}/config/configure ${WRKSRC}

post-patch:
	@${SED} -e s#__PREFIX__#$(PREFIX)#g $(WRKSRC)/include/config.h.dist > $(WRKSRC)/include/config.h.dist.new
	@${MV} $(WRKSRC)/include/config.h.dist.new $(WRKSRC)/include/config.h.dist

.include <bsd.port.mk>
