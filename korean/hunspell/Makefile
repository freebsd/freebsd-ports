# New ports collection makefile for:	Korean hunspell dictionaries
# Date created:		August 9, 2011
# Whom:			Jung-uk Kim <jkim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hunspell
PORTVERSION=	0.5.4
CATEGORIES=	korean textproc
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}-dict-ko-${PORTVERSION}

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Korean hunspell dictionaries

LICENSE=	GPLv2 LGPL21 MPL
LICENSE_COMB=	dual

BUILD_DEPENDS+=	py*-lxml>=0:${PORTSDIR}/devel/py-lxml

USE_GMAKE=		yes
USE_PYTHON_BUILD=	yes

PLIST_FILES=	%%DATADIR%%/ko_KR.aff \
		%%DATADIR%%/ko_KR.dic
PLIST_DIRSTRY=	%%DATADIR%%

PROJECTHOST=	spellcheck-ko

MAKE_ENV+=	PYTHON=${PYTHON_CMD}

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/ko.aff ${DATADIR}/ko_KR.aff
	${INSTALL_DATA} ${WRKSRC}/ko.dic ${DATADIR}/ko_KR.dic

.include <bsd.port.mk>
