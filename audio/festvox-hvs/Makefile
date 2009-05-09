# New ports collection makefile for:	festvox-hvs
# Date created:        			2000-06-20
# Whom:					Trevor Johnson
# based on the NetBSD port
#
# $NetBSD: Makefile,v 1.10 2000/02/15 09:26:14 agc Exp $
# $FreeBSD$
#

PORTNAME=	festvox-hvs
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	audio accessibility spanish
MASTER_SITES=	${MASTER_SITE_FESTIVAL_OGI}
DISTNAME=	voice_hvs_di-2.1

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Mexican Spanish female voice for Festival

RUN_DEPENDS=	festival+OGI:${PORTSDIR}/audio/festival+OGI \
		festlex-poslex:${PORTSDIR}/audio/festlex-poslex \
		festlex-ogi:${PORTSDIR}/audio/festlex-ogi \
		festogi-spanish:${PORTSDIR}/audio/festogi-spanish

WRKSRC=		${WRKDIR}/festival

RESTRICTED=	no-commercial-use

DEPRECATED=	unfulfilled dependencies for 8+ months, no user interest.
EXPIRATION_DATE=	2009-06-09

NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}) && !defined(PACKAGE_BUILDING)
IGNORE= distfile can only be fetched if you accept the license. Go to https://www.cslu.ogi.edu/tts/download/data/voice_hvs_di-2.1.tar.gz and put ${DISTFILE} into ${DISTDIR}
.endif

post-extract:
	@ ${CHMOD} -R a+r ${WRKSRC}
	@ ${FIND} ${WRKSRC} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@ ${FIND} ${WRKSRC} -type d -name CVS | ${XARGS} ${RM} -fr

do-install:
	${MKDIR} ${FHOME}
	cd ${WRKSRC} && ${CP} -pPR * ${FHOME}

.include <bsd.port.post.mk>
