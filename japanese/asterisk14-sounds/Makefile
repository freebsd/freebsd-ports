# New ports collection makefile for:	asterisk-sounds-jp
# Date created:				27 June 2007
# Whom:		Fumihiko Kimura <jfkimura@yahoo.co.jp>
#
# $FreeBSD$
#

PORTNAME=	asterisk-sounds
PORTVERSION=	1.4
PORTREVISION=	4
CATEGORIES=	japanese net
MASTER_SITES=	ftp://ftp.voip-info.jp/asterisk/sounds/
DISTNAME=	${PORTVERSION:S|.|_|}/${PORTNAME:S|sounds|sound|}-jp_${PORTVERSION:S|.||}_beta

MAINTAINER=	jfkimura@yahoo.co.jp
COMMENT=	Japanese sound files for Asterisk

RUN_DEPENDS=	asterisk:${PORTSDIR}/net/asterisk

NO_BUILD=	yes
ASTERISKSDIR=	${LOCALBASE}/share/asterisk/sounds

do-install:
	@-${MKDIR} ${ASTERISKSDIR}
	@${CP} -pR ${WRKDIR}/jp ${ASTERISKSDIR}
	@${MKDIR} ${DOCSDIR}
	@${CP} -pv ${WRKDIR}/jp/README.txt ${DOCSDIR}

post-install:
	@cd ${WRKDIR} && ${FIND} ./jp -type f -o -type l | ${SED} -e 's,^\.,${ASTERISKSDIR:S|${LOCALBASE}/||},' > ${TMPPLIST}
	@cd ${WRKDIR} && ${FIND} ./jp -type d -depth  | ${SED} -e 's,^\.,@dirrm ${ASTERISKSDIR:S|${LOCALBASE}/||},' >> ${TMPPLIST}
	@${ECHO} ${DOCSDIR:S|${LOCALBASE}/||}/README.txt >> ${TMPPLIST}
	@${ECHO} "@dirrm" ${DOCSDIR:S|${LOCALBASE}/||}  >> ${TMPPLIST}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
