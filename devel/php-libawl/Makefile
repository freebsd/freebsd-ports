# Created by: Cristiano Rolim Pereira <cristianorolim@hotmail.com>
# $FreeBSD$

PORTNAME=	php-libawl
PORTVERSION=	0.54
CATEGORIES=	devel
MASTER_SITES=	http://debian.mcmillan.net.nz/debian/pool/awm/a/awl/
DISTNAME=	awl-${PORTVERSION}

MAINTAINER=	cristianorolim@outlook.com
COMMENT=	Andrew.s Web Libraries - PHP Utility Libraries

WRKSRC=		${WRKDIR}/awl-${PORTVERSION}

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

post-patch:
	${RM} ${WRKSRC}/inc/*.orig

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${LIBAWLDIR}
	cd ${WRKSRC} && ${CP} -pR dba inc ${STAGEDIR}${PREFIX}/${LIBAWLDIR}/

.include <bsd.port.mk>
