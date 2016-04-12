# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	tvdownloader
PORTVERSION=	0.7.2
PORTREVISION=	5
CATEGORIES=	french multimedia
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Download podcasts and videos from French websites

LICENSE=	GPLv2

RUN_DEPENDS=	msdl:multimedia/msdl	\
		rtmpdump:multimedia/rtmpdump	\
		${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:x11-toolkits/py-qt4-gui	\
		${PYTHON_SITELIBDIR}/Crypto/__init__.py:security/py-pycrypto\
		${PYTHON_SITELIBDIR}/mechanize/_mechanize.py:www/py-mechanize

DEPRECATED=	Many channels have modified their protocols and cannot be DL anymore
EXPIRATION_DATE=	2016-04-14

USES=		python shebangfix
SHEBANG_FILES=	doc/installdox
ALL_TARGET=	build
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

pre-configure:
	${REINPLACE_CMD} -e 's|@python|${PYTHON_CMD}|'	\
		${WRKSRC}/Makefile ${WRKSRC}/src/Makefile
	${REINPLACE_CMD} -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|'	\
		${WRKSRC}/tvdownloader.sh
	${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|'	\
		${WRKSRC}/tvdownload.desktop

pre-configure-DOCS-on:
	${REINPLACE_CMD} -e 's|%%DOC%%||' ${WRKSRC}/Makefile

pre-configure-DOCS-off:
	${REINPLACE_CMD} -e 's|%%DOC%%|#|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
