PORTNAME=	mysqldump-secure
DISTVERSION=	0.16.5
CATEGORIES=	databases

MAINTAINER=	jsmith@resonatingmedia.com
COMMENT=	Simple tool for dumping/backing up MySQL and MariaDB databases
WWW=		https://mysqldump-secure.org/

LICENSE=	MIT

USES=		gmake mysql

USE_GITHUB=	yes
GH_ACCOUNT=	cytopia

HAS_CONFIGURE=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/build/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/build/${PORTNAME}.conf ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample
	${INSTALL_DATA} ${WRKSRC}/build/${PORTNAME}.cnf ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.cnf.sample
	${INSTALL_MAN} ${WRKSRC}/build/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
