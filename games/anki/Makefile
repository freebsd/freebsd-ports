# New ports collection makefile for:	anki
# Date created:		9 August 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	anki
PORTVERSION=	0.4.3
CATEGORIES=	games
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Flashcard trainer with spaced repetition

BUILD_DEPENDS=	py*-qt4-core>=4.2:${PORTSDIR}/devel/py-qt4-core \
		py*-qt4-gui>=4.2:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		py*-sip>=4.6:${PORTSDIR}/devel/py-sip \
		py*-numpy>=0:${PORTSDIR}/math/py-numpy \
		py*-anki>=0.4.3:${PORTSDIR}/games/py-anki \
		py*-matplotlib>=0.90.0:${PORTSDIR}/math/py-matplotlib
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GETTEXT=	yes
USE_PYDISTUTILS=easy_install
USE_PYTHON=	yes
USE_QT_VER=	4
QT_COMPONENTS=	moc
PYDISTUTILS_PKGNAME=	ankiqt
PORT_VERBS=	ankiqt

post-extract:
	@cd ${WRKSRC}/&&${RM} -rf libanki build

post-patch:
	@${REINPLACE_CMD} -e '/req/d' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e 's|0.4.2|${PORTVERSION}|g'\
		${WRKSRC}/ankiqt/__init__.py

.include <bsd.port.mk>
