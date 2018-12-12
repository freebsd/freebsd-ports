# $FreeBSD$

PORTNAME=	apitran
PORTVERSION=	g20180926
PORTREVISION=	2
CATEGORIES=	comms astro hamradio python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Toolkit to handle the automatic picture transmission protocol

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		${PYNUMPY} \
		sox:audio/sox \
		display:graphics/ImageMagick6

USES=		python:run shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	rsj56
GH_PROJECT=	apitran
GH_TAGNAME=	d209347

NO_BUILD=	yes
NO_ARCH=	yes
SHEBANG_FILES=	apitran

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/apitran ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in NOAA_APT_Frame_Format.gif README.md
	${INSTALL_DATA} ${WRKSRC}/$f ${STAGEDIR}${DOCSDIR}
.endfor
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in ex_1ch_11025.png ex_2ch_48000.png ex_2ch_48000.wav
	${INSTALL_DATA} ${WRKSRC}/Examples/$f ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
