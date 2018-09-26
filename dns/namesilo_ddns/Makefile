# $FreeBSD$

PORTNAME=	namesilo_ddns
PORTVERSION=	2.2
DISTVERSIONPREFIX=v
CATEGORIES=	dns net

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Updates DNS records with Namesilo for dynamic IP addresses

LICENSE=	MIT

RUN_DEPENDS=	xmllint:textproc/libxml2

USE_GITHUB=	yes
GH_ACCOUNT=	crees

NO_BUILD=	yes

PLIST_FILES=	sbin/${PORTNAME} "@sample etc/${PORTNAME}.conf.sample"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.sh \
		${STAGEDIR}${PREFIX}/sbin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf.sample \
		${STAGEDIR}${PREFIX}/etc/

.include <bsd.port.mk>
