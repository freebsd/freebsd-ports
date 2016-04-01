# $FreeBSD$
#
# Common code for PEAR channels

PKGNAMEPREFIX?=	pear-channel-

MASTER_SITES?=	#no master sites
DISTFILES?=	#no distfiles

BUILD_DEPENDS?=	${LOCALBASE}/bin/pear:devel/pear
RUN_DEPENDS?=	${LOCALBASE}/bin/pear:devel/pear

NO_BUILD?=	yes

LPEARDIR?=	share/pear

PEAR_CHANNEL_ALIAS?=	${PORTNAME}
PEAR_CHANNEL_REG?=	${FILESDIR}/${PEAR_CHANNEL_HOST}.reg

PLIST_FILES=	${LPEARDIR}/.channels/.alias/${PEAR_CHANNEL_ALIAS}.txt \
		${LPEARDIR}/.channels/${PEAR_CHANNEL_HOST}.reg
PLIST_DIRS=	${LPEARDIR}/.registry/.channel.${PEAR_CHANNEL_HOST}

.if !defined(PEAR_CHANNEL_HOST)
IGNORE=		Please set PEAR_CHANNEL_HOST
.elif !exists(${PEAR_CHANNEL_REG})
IGNORE=		Cannot find registry file: ${PEAR_CHANNEL_REG}
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${LPEARDIR}/.channels/.alias
	@${MKDIR} ${STAGEDIR}${PREFIX}/${LPEARDIR}/.registry/.channel.${PEAR_CHANNEL_HOST}
	@${INSTALL_DATA} ${PEAR_CHANNEL_REG} \
		${STAGEDIR}${PREFIX}/${LPEARDIR}/.channels
	@${ECHO_CMD} -n ${PEAR_CHANNEL_HOST} > \
		${STAGEDIR}${PREFIX}/${LPEARDIR}/.channels/.alias/${PEAR_CHANNEL_ALIAS}.txt
