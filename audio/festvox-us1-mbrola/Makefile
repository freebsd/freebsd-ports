# New ports collection makefile for:	festvox-us1-mbrola
# Date created:				31 Mar 2006
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	festvox-${VOICE}-mbrola
PORTVERSION?=	20041012
PORTREVISION?=	1
CATEGORIES=	audio accessibility
MASTER_SITES=	${MASTER_SITE_FESTIVAL}
MASTER_SITE_SUBDIR=	1.95
DISTNAME=	festvox_${VOICE}

MAINTAINER=	jylefort@FreeBSD.org
COMMENT?=	The MBROLA ${VOICE} voice (${VOICEDESC}) for Festival

RUN_DEPENDS=	${LOCALBASE}/share/festival/lib/dicts/cmu/cmulex.scm:${PORTSDIR}/audio/festlex-cmu \
		mbrola:${PORTSDIR}/audio/linux-mbrola

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

VOICE?=		us1
VOICEDESC?=	American English, female

VOICEDIR=	${PREFIX}/share/festival/lib/voices/english/${VOICE}_mbrola
VOICEDIR_REL=	${VOICEDIR:S|^${PREFIX}/||}

PLIST_SUB=	VOICE="${VOICE}" VOICEDIR_REL="${VOICEDIR_REL}"

MD5_FILE=	${.CURDIR}/distinfo

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/share/mbrolavox/${VOICE}/${VOICE})
RUN_DEPENDS+=	${LOCALBASE}/share/mbrolavox/${VOICE}/${VOICE}:${PORTSDIR}/audio/mbrolavox
.else
IGNORE=		requires the ${VOICE} MBROLA voice. Install the audio/mbrolavox port and enable the ${VOICE} voice in the options dialog, then install this port
.endif

do-install:
	cd ${WRKSRC} && \
	${FIND} * -type d -exec ${MKDIR} "${PREFIX}/share/{}" \; && \
	${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${PREFIX}/share/{}" \;
	${LN} -sf ${LOCALBASE}/share/mbrolavox/${VOICE} ${VOICEDIR}

.include <bsd.port.post.mk>
