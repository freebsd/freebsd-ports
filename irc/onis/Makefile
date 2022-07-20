PORTNAME=	onis
PORTVERSION=	0.8.2
CATEGORIES=	irc
MASTER_SITES=	http://verplant.org/onis/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Script that converts IRC logfiles into an HTML statistics page

USES=		perl5
NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
