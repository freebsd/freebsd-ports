# Created by: ijliao
# $FreeBSD$

PORTNAME=	rlwrap
PORTVERSION=	0.42
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	gamato@users.sf.net
COMMENT=	Readline wrapper

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	hanslub42

USES=		readline autoreconf
GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS BUGS NEWS PLEA README TODO

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
