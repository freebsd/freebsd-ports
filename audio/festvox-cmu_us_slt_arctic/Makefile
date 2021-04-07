PORTNAME=	festvox-${VOICE}
PORTVERSION=	0.95
CATEGORIES=	audio
MASTER_SITES=	http://www.speech.cs.cmu.edu/cmu_arctic/packed/
DISTNAME=	${VOICE}-${PORTVERSION}-release
DIST_SUBDIR=	festival

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	CMU US English female voice for festival

LICENSE=	MIT-variant
LICENSE_NAME=	MIT License (CMU variant)
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept dist-sell pkg-sell

RUN_DEPENDS=	festival:audio/festival \
	${LOCALBASE}/share/festival/lib/dicts/cmu/cmulex.scm:audio/festlex-cmu \
	${LOCALBASE}/share/festival/lib/dicts/wsj.wp39.poslexR:audio/festlex-poslex

USES=	tar:bzip2

WRKSRC=	${WRKDIR}/${VOICE}

NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	pkg-message
SUB_LIST+=	VOICE=${VOICE}

DATADIR=	${PREFIX}/share/festival/lib/voices/us/${VOICE}_clunits
PORTDATA?=	*

VOICE?=	cmu_us_slt_arctic

DESCR=		${.CURDIR}/pkg-descr
DISTINFO_FILE=	${.CURDIR}/distinfo
PKGMESSAGE=	${.CURDIR}/pkg-message

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	${RM} ${STAGEDIR}${DATADIR}/.time-stamp
	${FIND} ${STAGEDIR}${DATADIR} -type d -empty -delete

.include <bsd.port.mk>
