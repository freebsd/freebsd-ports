# Created by: Nicola Vitale	<nivit@email.it>
# $FreeBSD$

PORTNAME=	kana-no-quiz
DISTVERSION=	1.9.5
CATEGORIES=	japanese
MASTER_SITES=	SF/${PORTNAME}/Program%20releases/version%20${DISTVERSION}
DISTNAME=	Kana_no_quiz-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Educational tool to memorize Japanese KANA (Hiragana/Katakana)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/GPL.txt

RUN_DEPENDS=	${PYGAME}

NO_BUILD=	yes
NO_ARCH=	yes


USES=		gettext python:2.7 tar:bzip2
USE_GNOME=	pygtk2:run
USE_PYTHON=	distutils autoplist

WRKSRC=		"${WRKDIR}/${DISTNAME:S/_/ /g}"

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/share|${PREFIX}/share|' \
		${WRKSRC}/data/misc/kana-no-quiz.desktop

pre-configure:
	@${MKDIR} ${WRKSRC}/data/script
	@${ECHO_CMD} -n > ${WRKSRC}/data/script/kana-no-quiz
	@${ECHO_CMD} '#!${PYTHON_CMD}' \
		>> ${WRKSRC}/data/script/kana-no-quiz
	@${ECHO_CMD} 'from kananoquiz import *' \
		>> ${WRKSRC}/data/script/kana-no-quiz

.include <bsd.port.mk>
