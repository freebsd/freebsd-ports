# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	tvdownloader
PORTVERSION=	0.7.2
PORTREVISION=	5
CATEGORIES=	french multimedia
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
MASTER_SITE_SUBDIR=

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Download podcasts and videos from French websites

LICENSE=	GPLv2

RUN_DEPENDS=	msdl:${PORTSDIR}/multimedia/msdl	\
		rtmpdump:${PORTSDIR}/multimedia/rtmpdump	\
		${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:${PORTSDIR}/x11-toolkits/py-qt4-gui	\
		${PYTHON_SITELIBDIR}/Crypto/__init__.py:${PORTSDIR}/security/py-pycrypto\
		${PYTHON_SITELIBDIR}/mechanize/_mechanize.py:${PORTSDIR}/www/py-mechanize

USE_PYTHON=	yes
USES=		shebangfix
SHEBANG_FILES=	doc/installdox
ALL_TARGET=	build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

pre-configure:
	${REINPLACE_CMD} -e 's|@python|${PYTHON_CMD}|'	\
		${WRKSRC}/Makefile ${WRKSRC}/src/Makefile
	${REINPLACE_CMD} -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|'	\
		${WRKSRC}/tvdownloader.sh
	${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|'	\
		${WRKSRC}/tvdownload.desktop
.if empty(PORT_OPTIONS:MDOCS)
	${REINPLACE_CMD} -e 's|%%DOC%%|#|' ${WRKSRC}/Makefile
.else
	${REINPLACE_CMD} -e 's|%%DOC%%||' ${WRKSRC}/Makefile
.endif

.include <bsd.port.mk>
