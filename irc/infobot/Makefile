# New ports collection makefile for:	infobot
# Date created:				17 November 1999
# Whom:					perlguy@perlguy.com
#
# $FreeBSD$
#

PORTNAME=	infobot
PORTVERSION=	0.44.5
CATEGORIES=	irc
MASTER_SITES=	http://www.infobot.org/src/ \
		http://www.infobot.org/src/prior/

DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	perlguy@perlguy.com

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_PERL5=	yes
NO_BUILD=	yes
PLIST_SUB+=	VERSION="${PORTVERSION}"

do-install:
	@if [ ! -d ${PREFIX}/share/${DISTNAME} ]; then \
		${MKDIR} ${PREFIX}/share/${PORTNAME}-${PORTVERSION}; \
	fi
	${CP} -R ${WRKSRC}/* ${PREFIX}/share/${PORTNAME}-${PORTVERSION}/

.include <bsd.port.mk>
