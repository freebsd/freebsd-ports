# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	nsec3walker
PORTVERSION=	20101223
CATEGORIES=	dns
MASTER_SITES=	https://dnscurve.org/

MAINTAINER=	pkubaj@anongoth.pl
COMMENT=	Walk NSEC3 secured DNSSEC zones

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bsddb>0:databases/py-bsddb@${PY_FLAVOR} \
		dig:dns/bind-tools

USES=		python shebangfix ssl

SHEBANG_FILES=	${WRKSRC}/collect ${WRKSRC}/unhash
PLIST_FILES=	bin/collect \
		bin/dicthashes \
		bin/query \
		bin/randomhashes \
		bin/unhash

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/collect ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dicthashes ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/query ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/randomhashes ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/unhash ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
