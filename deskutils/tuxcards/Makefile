# New ports collection makefile for:	tuxcards
# Date created:				08 Jan 2002
# Whom:			Tilman linneweh <freebsdports@arved.de>
#
# $FreeBSD$
#

PORTNAME=	tuxcards
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://www.arved.de/bsd/src/
DISTNAME=	${PORTNAME}-${PORTVERSION}-ohneCactus

MAINTAINER=	freebsdports@arved.de

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GMAKE=	yes
USE_QT_VER=	2
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
USE_REINPLACE=	yes

pre-patch:
	@${REINPLACE_CMD} -e 's|[$$](prefix)/doc|\$$\(prefix\)/share/doc|' \
		${WRKSRC}/tuxcards/docs/en/Makefile.in
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/configure
.ifdef(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|install-data-am\: install-data-local||' \
		${WRKSRC}/tuxcards/docs/en/Makefile.in
.endif #NOPORTDOCS

.include <bsd.port.mk>
