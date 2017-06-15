# Created by: <jsmith@resonatingmedia.com>
# $FreeBSD$

PORTNAME=	mysqldump-secure
PORTVERSION=	0.16.3
CATEGORIES=	databases

MAINTAINER=	jsmith@resonatingmedia.com
COMMENT=	Simple tool for dumping/backing up MySQL and MariaDB databases

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	cytopia

USES=		mysql gmake

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

do-install:
	gzip ${GZIP} ${WRKSRC}/build/${PORTNAME}.1
	${INSTALL_SCRIPT} ${WRKSRC}/build/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA}  ${WRKSRC}/build/${PORTNAME}.conf ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample
	${INSTALL_DATA}  ${WRKSRC}/build/${PORTNAME}.cnf ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.cnf.sample
	${INSTALL_MAN}  ${WRKSRC}/build/${PORTNAME}.1.gz ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
