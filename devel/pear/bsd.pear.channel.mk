# $FreeBSD$
#
# Common code for PEAR channels

MASTER_SITES?=	#no master sites
DISTFILES?=	#no distfiles

BUILD_DEPENDS?=	${LOCALBASE}/bin/pear:${PORTSDIR}/devel/pear
RUN_DEPENDS?=	${LOCALBASE}/bin/pear:${PORTSDIR}/devel/pear

NO_BUILD?=	yes

LPEARDIR?=	share/pear
PEAR_CHANNEL_REG?=	${FILESDIR}/${PEAR_CHANNEL_HOST}.reg

PLIST_FILES=	${LPEARDIR}/.channels/.alias/${PEAR_CHANNEL_ALIAS}.txt \
		${LPEARDIR}/.channels/${PEAR_CHANNEL_HOST}.reg \
		"@exec ${MKDIR} %D/${LPEARDIR}/.registry/.channel.${PEAR_CHANNEL_HOST}"
PLIST_DIRS=	${LPEARDIR}/.registry/.channel.${PEAR_CHANNEL_HOST}


do-install:
	@${MKDIR} ${PREFIX}/${LPEARDIR}/.registry/.channel.${PEAR_CHANNEL_HOST}
	@${INSTALL_DATA} ${PEAR_CHANNEL_REG} \
		${PREFIX}/${LPEARDIR}/.channels/
	@${ECHO_CMD} -n ${PEAR_CHANNEL_HOST} > \
		${PREFIX}/${LPEARDIR}/.channels/.alias/${PEAR_CHANNEL_ALIAS}.txt
