# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	0.5.6
CATEGORIES=	korean textproc
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}-dict-ko-${PORTVERSION}

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Korean hunspell dictionaries

LICENSE=	GPLv2 LGPL21 MPL
LICENSE_COMB=	dual

BUILD_DEPENDS+=	py*-lxml>=0:${PORTSDIR}/devel/py-lxml

USES=		gmake
USE_PYTHON_BUILD=	yes
USE_XZ=			yes

PLIST_FILES=	%%DATADIR%%/ko_KR.aff \
		%%DATADIR%%/ko_KR.dic
PLIST_DIRSTRY=	%%DATADIR%%

PROJECTHOST=	spellcheck-ko

MAKE_ENV+=	PYTHON=${PYTHON_CMD}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/ko.aff ${STAGEDIR}${DATADIR}/ko_KR.aff
	${INSTALL_DATA} ${WRKSRC}/ko.dic ${STAGEDIR}${DATADIR}/ko_KR.dic

.include <bsd.port.mk>
