# Created by: Nicola Vitale	<nivit@email.it>
# $FreeBSD$

PORTNAME=	kana-no-quiz
DISTVERSION=	1.9
PORTREVISION=	8
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME:S,k,K,}-${DISTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A little tool to memorize Japanese KANA (Hiragana/Katakana)

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pygtk.py:${PORTSDIR}/x11-toolkits/py-gtk2 \
		${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game

NO_BUILD=	yes

RM_FILES=	CHANGES.txt FAL.txt  GPL.txt
RM_OPTS=	-f

USES=		gettext
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

PYDISTUTILS_PKGNAME=	Kana-no-quiz

WRKSRC=		"${WRKDIR}/Kana no quiz-${DISTVERSION}"

NO_STAGE=	yes
post-extract:
	@cd ${WRKSRC} && ${RM} ${RM_OPTS} ${RM_FILES}

.include <bsd.port.mk>
