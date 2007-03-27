# New ports collection makefile for:	loemu
# Date created:		2007-02-27
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	loemu
PORTVERSION=	0.1.1
CATEGORIES=	emulators python
MASTER_SITES=	http://loemu.pegueroles.com/dists/

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Simple frontend for various game emulators

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pygtk.pth:${PORTSDIR}/x11-toolkits/py-gtk2 \
		${PYTHON_SITELIBDIR}/libxml2.py:${PORTSDIR}/textproc/py-libxml2 \
		${PYTHON_SITELIBDIR}/libxslt.py:${PORTSDIR}/textproc/py-libxslt

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
NO_BUILD=		yes

OPTIONS=	SDLMAME	"Install sdlmame emulator"	off \
		XMAME	"Install xmame emulator"	on \
		SNES9X	"Install snes9x emulator"	on

.include <bsd.port.pre.mk>

.if defined(WITH_SDLMAME)
RUN_DEPENDS+=	sdlmame:${PORTSDIR}/emulators/sdlmame
.endif

.if !defined(WITHOUT_XMAME)
RUN_DEPENDS+=	xmame:${PORTSDIR}/emulators/xmame
.endif

.if !defined(WITHOUT_SNES9X)
RUN_DEPENDS+=	snes9x:${PORTSDIR}/emulators/snes9x
.endif

post-patch:
.for DIRE in config loemu scripts
	@cd ${WRKSRC}/${DIRE} && \
		${FIND} * -type f -exec ${REINPLACE_CMD} -i '' -e \
			's|/share/games/|/share/|g' -e \
			's|/usr/bin/python|${PYTHON_CMD}|g' "{}" \;
.endfor
	@${REINPLACE_CMD} -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|g' \
		${WRKSRC}/setup.py

.include <bsd.port.post.mk>
