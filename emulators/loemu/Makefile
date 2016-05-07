# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	loemu
PORTVERSION=	0.3.1
PORTREVISION=	11
CATEGORIES=	emulators python
MASTER_SITES=	http://loemu.pegueroles.com/dists/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple frontend for various game emulators

LICENSE=	GPLv2+

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:x11-toolkits/py-gtk2 \
		${PYTHON_SITELIBDIR}/libxml2.py:textproc/py-libxml2 \
		${PYTHON_SITELIBDIR}/libxslt.py:textproc/py-libxslt

USES=		gettext python shebangfix
USE_PYTHON=	distutils
NO_BUILD=	yes
SHEBANG_FILES=	setup.py

OPTIONS_DEFINE=	MAME SNES9X ZSNES
OPTIONS_DEFAULT=	MAME SNES9X

MAME_DESC=		Install mame emulator
SNES9X_DESC=		Install snes9x emulator
ZSNES_DESC=		Install zsnes emulator
MAME_RUN_DEPENDS=	mame>=0.154:emulators/mame
SNES9X_RUN_DEPENDS=	snes9x:emulators/snes9x
ZSNES_RUN_DEPENDS=	zsnes:emulators/zsnes

.include <bsd.port.options.mk>

.if ${ARCH:Mamd64}
MAMENAME=	mame64
.else
MAMENAME=	mame
.endif

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|/usr/bin/env python|${PYTHON_CMD}|' \
		${WRKSRC}/scripts/loemu \
		${WRKSRC}/scripts/loemu-builder
	@${REINPLACE_CMD} -i '' -e 's|sdlmame|${MAMENAME}|' \
		${WRKSRC}/config/sdlmame.conf

.include <bsd.port.mk>
