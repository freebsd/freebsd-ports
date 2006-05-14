# New ports collection makefile for:	kana-no-quiz
# Date created:		2006-04-10
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	kana-no-quiz
DISTVERSION=	1.5
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	nivit@email.it
COMMENT=	A little tool to memorize Japanese KANA (Hiragana/Katakana)

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pygtk.py:${PORTSDIR}/x11-toolkits/py-gtk2

WRKSRC=		"${WRKDIR}/Kana no quiz-1.5"
NO_BUILD=	yes
USE_GETTEXT=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

post-extract:
	@${RM} -f ${WRKSRC}/GPL.txt

.include <bsd.port.mk>
