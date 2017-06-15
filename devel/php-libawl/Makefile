# Created by: Cristiano Rolim Pereira <cristianorolim@hotmail.com>
# $FreeBSD$

PORTNAME=	php-libawl
PORTVERSION=	0.57
DISTVERSIONPREFIX=	r
CATEGORIES=	devel
MASTER_SITES=	https://gitlab.com/davical-project/awl/repository/archive.tar.gz?ref=${DISTVERSIONPREFIX}${PORTVERSION}&dummy=/
DISTNAME=	awl-${DISTVERSIONPREFIX}${PORTVERSION}

MAINTAINER=	cristianorolim@outlook.com
COMMENT=	Andrew.s Web Libraries - PHP Utility Libraries

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	PHP
OPTIONS_DEFAULT=	PHP

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPHP}
USE_PHP=	YES
.endif
NO_BUILD=	YES
LIBAWLDIR?=	share/awl
PLIST_SUB+=	LIBAWLDIR=${LIBAWLDIR}

pre-everything::
	@${ECHO_CMD} "# you can customize the installation directory"
	@${ECHO_CMD} "# by setting LIBAWLDIR in /etc/make.conf"

post-extract:
	@${MV} ${WRKDIR}/${DISTNAME}-* ${WRKSRC}

post-patch:
	${RM} ${WRKSRC}/inc/*.orig

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${LIBAWLDIR}
	cd ${WRKSRC} && ${CP} -pR dba inc ${STAGEDIR}${PREFIX}/${LIBAWLDIR}/

.include <bsd.port.mk>
