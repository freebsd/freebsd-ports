# Created by: trevor
# $FreeBSD$

PORTNAME=	festlex-ogi
PORTVERSION=	2.2
PORTREVISION=	2
CATEGORIES=	audio accessibility
MASTER_SITES=	# ${MASTER_SITE_FESTIVAL_OGI}
DISTNAME=	OGIlexicon-2.2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Composite pronunciation dictionary from ogi.edu for Festival

RUN_DEPENDS=	festival:audio/festival \
		${LOCALBASE}/share/festival/lib/dicts/wsj.wp39.poslexR:audio/festlex-poslex

RESTRICTED=	No commercial use

WRKSRC=		${WRKDIR}/festival

NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	distfile can only be fetched if you accept the license. Go to https://www.cslu.ogi.edu/tts/download/data/OGIlexicon-2.2.tar.gz and put ${DISTFILE} into ${DISTDIR}
.endif

do-install:
	${MKDIR} ${STAGEDIR}${FHOME}
	cd ${WRKSRC} && ${CP} -pPR * ${STAGEDIR}${FHOME}

.include <bsd.port.post.mk>
