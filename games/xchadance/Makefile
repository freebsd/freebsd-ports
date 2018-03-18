# Created by: issei <issei@jp.FreeBSD.org>
# $FreeBSD$

PORTNAME=	xchadance
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.mk.bsdclub.org/pub/FreeBSD/distfiles/ \
		ftp://relay1.tomsk.gov.ru/pub/FreeBSD/ports/distfiles/ \
		ftp://ftp.rediris.es/sites/ftp.freebsd.org/pub/FreeBSD/ports/local-distfiles/motoyuki/
DISTFILES=	xchada01.lzh

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Display a dancing girl "ChaCha."

BROKEN=		unfetchable

USES=		lha
USE_XORG=	x11
MAKEFILE=	makefile
NO_WRKSUBDIR=	yes

OPTIONS_DEFINE=	DOCS

RESTRICTED=	'contains commercial character data'

post-patch:
	@(cd ${WRKSRC}; \
		${PATCH} < ${WRKSRC}/xchada01.bug)

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.jp ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.eng ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
