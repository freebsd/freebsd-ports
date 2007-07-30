# New ports collection makefile for:	kana-no-quiz
# Date created:		2006-04-10
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	kana-no-quiz
DISTVERSION=	1.7
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	Kana_no_quiz-${DISTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A little tool to memorize Japanese KANA (Hiragana/Katakana)

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pygtk.py:${PORTSDIR}/x11-toolkits/py-gtk2

NO_BUILD=	yes

RM_FILES=	CHANGES.txt FAL.txt  GPL.txt
RM_OPTS=	-f

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_PYTHON=	2.4+
USE_PYDISTUTILS=yes

PYDISTUTILS_PKGNAME=	Kana_no_quiz

WRKSRC=		"${WRKDIR}/Kana no quiz-${DISTVERSION}"

post-extract:
	for f in ${RM_FILES}; do \
	    ${RM} ${RM_OPTS} ${WRKSRC}/$${f}; \
	done

.include <bsd.port.mk>
