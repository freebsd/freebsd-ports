# New ports collection Makefile for:	php-libawl
# Date created:				28 Jan 2009
# Whom:					Cristiano Rolim Pereira <cristianorolim@hotmail.com>
# $FreeBSD$

PORTNAME=	php-libawl
PORTVERSION=	0.53
CATEGORIES=	devel
MASTER_SITES=	http://debian.mcmillan.net.nz/packages/awl/ \
		SF/rscds/awl/${PORTVERSION}
DISTNAME=	awl-${PORTVERSION}

MAINTAINER=	cristianorolim@hotmail.com
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
	${RM} -f ${WRKSRC}/inc/*.orig

do-install:
	${MKDIR} ${PREFIX}/${LIBAWLDIR}/
	cd ${WRKSRC} && ${CP} -pR dba inc ${PREFIX}/${LIBAWLDIR}/

.include <bsd.port.mk>
