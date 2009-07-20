# New ports collection Makefile for:	php-libawl
# Date created:				28 Jan 2009
# Whom:					Cristiano Rolim Pereira <cristianorolim@hotmail.com>
# $FreeBSD$

PORTNAME=	php-libawl
PORTVERSION=	0.37
CATEGORIES=	devel
MASTER_SITES=	SF/rscds
DISTNAME=	awl_${PORTVERSION}

MAINTAINER=	cristianorolim@hotmail.com
COMMENT=	Andrew.s Web Libraries - PHP Utility Libraries

WRKSRC=		${WRKDIR}/awl-${PORTVERSION}

.if !defined(WITHOUT_PHP_DEPENDS)
USE_PHP=	YES
.endif
NO_BUILD=	YES
LIBAWLDIR?=	share/awl
PLIST_SUB+=	LIBAWLDIR=${LIBAWLDIR}

pre-everything::
	@${ECHO_CMD} "# you can customize the installation directory"
	@${ECHO_CMD} "# by setting LIBAWLDIR in /etc/make.conf"

do-install:
	${MKDIR} ${PREFIX}/${LIBAWLDIR}
	${CP} -Rp ${WRKSRC}/dba ${PREFIX}/${LIBAWLDIR}/
	${CP} -Rp ${WRKSRC}/inc ${PREFIX}/${LIBAWLDIR}/

.include <bsd.port.mk>
