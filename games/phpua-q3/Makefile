# New ports collection makefile for:	phpua-plugin_q3
# Date created:				11 March 2003
# Whom:					hideki
#
# $FreeBSD$
#

PORTNAME=	phpua-plugin_q3
PORTVERSION=	1.1.0b
CATEGORIES=	games www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	phpua

MAINTAINER=	hido@neojapangz.com
COMMENT=	A Quake 3 plugin for phpUA

RUN_DEPENDS=	${LOCALBASE}/${PHPUA}/index.php:${PORTSDIR}/games/phpua-engine

# Some variables you can change
PHPUA?=		www/data/phpua
USER?=		www
GROUP?=		www

# Static Variables
PKGOPTS=	${FILESDIR}/pkg-opts

NO_BUILD=	yes

PLIST_SUB+=	PHPUA=${PHPUA}

options:
	@ ${ECHO_MSG} "===>  Build options for ${PKGNAME}:"
	@ ${CAT} ${PKGOPTS}

pre-everything::
.if !defined(BATCH)
	@ ${TEST} -r ${PKGOPTS} && \
	(${ECHO_MSG} '-------------------------------------------------------------------------'; \
	${ECHO_MSG} 'Perform a "make options" to see a list of available installation options.'; \
	${ECHO_MSG} '-------------------------------------------------------------------------')
.endif

do-install:
	@ ${CP} -R ${WRKDIR}/plugins ${PREFIX}/${PHPUA}/
	@ ${CP} -R ${WRKDIR}/templates ${PREFIX}/${PHPUA}/
	@ ${CP} -R ${WRKDIR}/images ${PREFIX}/${PHPUA}/
	@ ${CHOWN} -R ${USER}:${GROUP} ${PREFIX}/${PHPUA}
	@ ${ECHO_MSG} ""
	@ ${ECHO_MSG} "* Files have been installed in"
	@ ${ECHO_MSG} "* ${PREFIX}/${PHPUA}"
	@ ${ECHO_MSG} "*"

.include <bsd.port.mk>
