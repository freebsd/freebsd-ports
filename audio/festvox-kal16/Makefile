# New ports collection makefile for:	festvox-kal16
# Date created:        			2000-06-16
# Whom:					Trevor Johnson
# based on the NetBSD port
#
# $NetBSD: Makefile,v 1.8 2000/02/15 09:26:15 agc Exp $
# $FreeBSD$
#

PORTNAME=	festvox-kal16
PORTVERSION=	1.4.0
CATEGORIES=	audio accessibility
MASTER_SITES=	${MASTER_SITE_FESTIVAL}
MASTER_SITE_SUBDIR=	1.4.1
DISTNAME=	festvox_kallpc16k
DIST_SUBDIR=	festival
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	American English male voice, sampled at 16 kHz, for Festival

RUN_DEPENDS=	\
${LOCALBASE}/share/festival/lib/dicts/wsj.wp39.poslexR:${PORTSDIR}/audio/festlex-poslex \
${LOCALBASE}/share/festival/lib/dicts/cmu/cmulex.scm:${PORTSDIR}/audio/festlex-cmu

CONFLICTS=	festvox-kal8-*

NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

do-install:
	${TAR} -C ${FHOME:H} -xvzpf ${_DISTDIR}/${_DISTFILES}

.include <bsd.port.mk>
