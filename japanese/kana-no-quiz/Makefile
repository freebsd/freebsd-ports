# Created by: Nicola Vitale	<nivit@email.it>
# $FreeBSD$

PORTNAME=	kana-no-quiz
DISTVERSION=	1.9
PORTREVISION=	10
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME:S,k,K,}-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Little tool to memorize Japanese KANA (Hiragana/Katakana)

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}game>0:${PORTSDIR}/devel/py-game

NO_BUILD=	yes

RM_FILES=	CHANGES.txt FAL.txt  GPL.txt
RM_OPTS=	-f

USES=		gettext python
USE_GNOME=	pygtk2:run
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	Kana-no-quiz

WRKSRC=		"${WRKDIR}/Kana no quiz-${DISTVERSION}"

post-extract:
	@cd ${WRKSRC} && ${RM} ${RM_OPTS} ${RM_FILES}

.include <bsd.port.mk>
