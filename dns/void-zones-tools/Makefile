# $FreeBSD$

PORTNAME=	void-zones-tools
DISTVERSION=	0.1a
CATEGORIES=	dns

MAINTAINER=	vidar@karlsen.tech
COMMENT=	Prepare a list of void zones that can be readily fed into Unbound

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11
USE_GITHUB=	yes
GH_ACCOUNT=	cyclaero
GH_TAGNAME=	e6c5ef1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hosts2zones ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/void-zones
	${INSTALL_SCRIPT} ${WRKSRC}/void-zones-update.sh ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
