PORTNAME=	rfksay
PORTVERSION=	0.1
CATEGORIES=	games
MASTER_SITES=	http://freebsdcluster.org/~mich/software/
DISTNAME=	rfksay

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generates a kitten finding robot with a text bubble

USES=		perl5 shebangfix
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

SHEBANG_FILES=	rfksay kittensay robotsay

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/kittensay ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/robotsay ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
