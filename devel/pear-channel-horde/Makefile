# Ports collection makefile for:  pear-channel-horde
# Date created:			  6 July 2011
# Whom:				  Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pear-channel-horde
PORTVERSION=	20110304
CATEGORIES=	devel www pear
MASTER_SITES=	#no master sites
DISTFILES=	#no distfiles

MAINTAINER=	mm@FreeBSD.org
COMMENT=	PEAR Channel pear.horde.org

BUILD_DEPENDS=	${LOCALBASE}/bin/pear:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${LOCALBASE}/bin/pear:${PORTSDIR}/devel/pear

NO_BUILD=	yes

LPEARDIR?=	share/pear

PLIST_FILES=	${LPEARDIR}/.channels/.alias/horde.txt \
		${LPEARDIR}/.channels/pear.horde.org.reg \
		"@exec ${MKDIR} %D/${LPEARDIR}/.registry/.channel.pear.horde.org"
PLIST_DIRS=	${LPEARDIR}/.registry/.channel.pear.horde.org

do-install:
	@${MKDIR} ${PREFIX}/${LPEARDIR}/.registry/.channel.pear.horde.org
	@${INSTALL_DATA} ${FILESDIR}/pear.horde.org.reg \
		${PREFIX}/${LPEARDIR}/.channels/pear.horde.org.reg
	@${ECHO_CMD} -n pear.horde.org > \
		${PREFIX}/${LPEARDIR}/.channels/.alias/horde.txt

.include <bsd.port.mk>
