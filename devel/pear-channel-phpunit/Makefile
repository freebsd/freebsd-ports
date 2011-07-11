# Ports collection makefile for:  pear-channel-phpunit
# Date created:			  11 July 2011
# Whom:				  Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pear-channel-phpunit
PORTVERSION=	20110327
CATEGORIES=	devel www pear
MASTER_SITES=	#no master sites
DISTFILES=	#no distfiles

MAINTAINER=	mm@FreeBSD.org
COMMENT=	PEAR Channel pear.phpunit.de

BUILD_DEPENDS=	${LOCALBASE}/bin/pear:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${LOCALBASE}/bin/pear:${PORTSDIR}/devel/pear

NO_BUILD=	yes

LPEARDIR?=	share/pear

PLIST_FILES=	${LPEARDIR}/.channels/.alias/phpunit.txt \
		${LPEARDIR}/.channels/pear.phpunit.de.reg \
		"@exec ${MKDIR} %D/${LPEARDIR}/.registry/.channel.pear.phpunit.de"
PLIST_DIRS=	${LPEARDIR}/.registry/.channel.pear.phpunit.de

do-install:
	@${MKDIR} ${PREFIX}/${LPEARDIR}/.registry/.channel.pear.phpunit.de
	@${INSTALL_DATA} ${FILESDIR}/pear.phpunit.de.reg \
		${PREFIX}/${LPEARDIR}/.channels/pear.phpunit.de.reg
	@${ECHO_CMD} -n pear.phpunit.de > \
		${PREFIX}/${LPEARDIR}/.channels/.alias/phpunit.txt

.include <bsd.port.mk>
