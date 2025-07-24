PORTNAME=	rcheckbook
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.5
CATEGORIES=	finance

MAINTAINER=	tonyhawk2100@gmail.com
COMMENT= CLI based checkbook ledger
WWW=	https://github.com/bryceac/rcheckbook

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	cargo

USE_GITHUB=	yes
GH_ACCOUNT=	bryceac

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/rcheckbook ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}/var/db/${PORTNAME}
	${INSETT_DATA} ${WRKSRC}/register.db ${STAGEDIR}/var/db/${PORTNAME}/

.include <bsd.port.mk>
