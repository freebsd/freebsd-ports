# Created by: Michael L. Hostbaek (mich@freebsdcluster.org)
# $FreeBSD$

PORTNAME=	rfksay
PORTVERSION=	0.1
CATEGORIES=	games
MASTER_SITES=	http://freebsdcluster.org/~mich/software/
DISTNAME=	rfksay

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Generates a kitten finding robot with a text bubble

USES=		perl5 shebangfix
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

SHEBANG_FILES=	rfksay kittensay robotsay

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/kittensay ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/robotsay ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
