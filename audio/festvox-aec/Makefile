# New ports collection makefile for:	festvox-aec
# Date created:        			2000-06-12
# Whom:					Trevor Johnson
# based on the NetBSD port
#
# $NetBSD: Makefile,v 1.16 2003/04/10 01:28:05 grant Exp $
# $FreeBSD$
#

PORTNAME=	festvox_aec
PORTVERSION=	2.0
CATEGORIES=	audio accessibility
MASTER_SITES=	${MASTER_SITE_FESTIVAL_OGI}
DISTNAME=	voice_aec_di-2.0
DIST_SUBDIR=	festival

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	American English male voice for Festival speech synthesis system

RUN_DEPENDS=	festival:${PORTSDIR}/audio/festival \
 ${LOCALBASE}/share/festival/lib/dicts/ogi_lex.out:${PORTSDIR}/audio/festlex-ogi

AECDIR=		share/festival/lib/voices/english/aec_diphone
FHOME=		${PREFIX}/share/festival
NO_BUILD=	y
PLIST=		${WRKDIR}/plist
RESTRICTED=	"no commercial use"
WRKSRC=		${WRKDIR}/festival

post-extract:
	${CHMOD} -R a+r ${WRKSRC}
	${FIND} ${WRKSRC} -type d -print0 | ${XARGS} ${CHMOD} 755
	${FIND} ${WRKSRC} -type d -name CVS | ${XARGS} ${RM} -fr

pre-install:
	${RM} -f ${PLIST}
.for ii in _diphone.scm diph.msec gain.dat
	${ECHO_CMD} ${AECDIR}/festvox/aec${ii} >> ${PLIST}
.endfor
	${ECHO_CMD} ${AECDIR}/group/aec_di_resLPC.group >> ${PLIST}
.for ii in /group /festvox /
	${ECHO_CMD} @dirrm ${AECDIR}${ii} >> ${PLIST}
.endfor

do-install:
	${MKDIR} ${FHOME}
	cd ${WRKSRC} && ${CP} -pPR * ${FHOME}

.include <bsd.port.mk>
