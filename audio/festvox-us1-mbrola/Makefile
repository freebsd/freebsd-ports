# New ports collection makefile for:	festvox-us1-mbrola
# Date created:				31 Mar 2006
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	festvox-${VOICE}-mbrola
PORTVERSION?=	20041012
CATEGORIES=	audio accessibility
MASTER_SITES=	${MASTER_SITE_FESTIVAL}
MASTER_SITE_SUBDIR=	1.95
DISTNAME=	festvox_${VOICE}

MAINTAINER=	jylefort@FreeBSD.org
COMMENT?=	The MBROLA ${VOICE} voice (${VOICEDESC}) for Festival

RUN_DEPENDS=	${LOCALBASE}/share/festival/lib/dicts/cmu/cmulex.scm:${PORTSDIR}/audio/festlex-cmu \
		festival:${PORTSDIR}/audio/festival \
		mbrola:${PORTSDIR}/audio/linux-mbrola \
		${LOCALBASE}/share/mbrolavox/${VOICE}/${VOICE}:${PORTSDIR}/audio/mbrolavox

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

VOICE?=		us1
VOICEDESC?=	American English, female

VOICEDIR=	${PREFIX}/share/festival/lib/voices/english/${VOICE}_mbrola
VOICEDIR_REL=	${VOICEDIR:S|^${PREFIX}/||}

PLIST_FILES=	${VOICEDIR_REL}/festvox/${VOICE}_mbrola.scm \
		${VOICEDIR_REL}/festvox/usdurtreeZ.scm \
		${VOICEDIR_REL}/${VOICE} \
		${VOICEDIR_REL}/usradio
PLIST_DIRS=	${VOICEDIR_REL}/festvox \
		${VOICEDIR_REL}

MD5_FILE=	${.CURDIR}/distinfo

do-install:
	cd ${WRKSRC} && \
	${FIND} * -type d -exec ${MKDIR} "${PREFIX}/share/{}" \; && \
	${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${PREFIX}/share/{}" \;
	${LN} -sf ${LOCALBASE}/share/mbrolavox/${VOICE} ${VOICEDIR}

.include <bsd.port.mk>
