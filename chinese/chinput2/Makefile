# ex:ts=8
# Ports collection makefile for:	chinput2
# Date created:				11/09/2000
# Whom:					Peng HaiJie   (phj@cn.freebsd.org)
#
# $FreeBSD$
#

PORTNAME=	chinput2
PORTVERSION=	1.3.1
CATEGORIES=	chinese x11
MASTER_SITES=	ftp://ftp.cn.freebsd.org/pub/ported/
DISTNAME=	zh-chinput2-1.3.1

MAINTAINER=	phj@cn.FreeBSD.org

BUILD_DEPENDS=	mysql:${PORTSDIR}/databases/mysql323-client
RUN_DEPENDS=	mysql:${PORTSDIR}/databases/mysql323-client

USE_XLIB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

post-extract:
	find ${WRKSRC} -name CVS | xargs ${RM} -rf

post-install:
	@echo
	@echo
	@echo "Please refer to /usr/local/share/chinput2/README for "
	@echo "how to use chinput2,thanks for using this software."
	@echo
	@echo "					-phj@cn.freebsd.org"
	@echo

.include <bsd.port.mk>
