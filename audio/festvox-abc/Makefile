# New ports collection makefile for:	festvox-abc
# Date created:        			2000-06-12
# Whom:					Trevor Johnson
# based on the NetBSD port
#
# $NetBSD: Makefile,v 1.10 2000/02/15 09:26:13 agc Exp $
# $FreeBSD$
#

PORTNAME=	festvox-abc
PORTVERSION=	2.1
PORTREVISION=	2
CATEGORIES=	audio accessibility spanish
MASTER_SITES=	# ${MASTER_SITE_FESTIVAL_OGI}
DISTNAME=	voice_abc_di-${PORTVERSION}

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Mexican Spanish male voice for Festival speech synthesis system

RUN_DEPENDS=	\
		${LOCALBASE}/share/festival/lib/ogi_spanish/ogi_span_mx_lts.scm:${PORTSDIR}/audio/festogi-spanish \
		${LOCALBASE}/share/festival/lib/dicts/ogi_lex.out:${PORTSDIR}/audio/festlex-ogi

RESTRICTED=	no-commercial-use

DEPRECATED=	unfulfilled dependencies for 8+ months, no user interest.
EXPIRATION_DATE=	2009-06-09

WRKSRC=		${WRKDIR}/festival

NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}) && !defined(PACKAGE_BUILDING)
IGNORE= distfile can only be fetched if you accept the license. Go to https://www.cslu.ogi.edu/tts/download/data/voice_abc_di-2.1.tar.gz and put ${DISTFILE} into ${DISTDIR}
.endif

post-extract:
	${CHMOD} -R a+r ${WRKSRC}
	${FIND} ${WRKSRC} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	${RM} -f ${WRKSRC}/lib/voices/spanish/abc_diphone/group/hvslpcOGI16k.group
	${FIND} ${WRKSRC} -type d -name CVS | ${XARGS} ${RM} -fr

do-install:
	${MKDIR} ${FHOME}
	cd ${WRKSRC} && ${CP} -pPR * ${FHOME}

.include <bsd.port.post.mk>
