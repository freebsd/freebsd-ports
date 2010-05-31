# New ports collection makefile for:	loemu
# Date created:		2007-02-27
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	loemu
PORTVERSION=	0.3.1
PORTREVISION=	5
CATEGORIES=	emulators python
MASTER_SITES=	http://loemu.pegueroles.com/dists/

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Simple frontend for various game emulators

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2 \
		${PYTHON_SITELIBDIR}/libxml2.py:${PORTSDIR}/textproc/py-libxml2 \
		${PYTHON_SITELIBDIR}/libxslt.py:${PORTSDIR}/textproc/py-libxslt

USE_GETTEXT=		yes
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
NO_BUILD=		yes

OPTIONS=	MAME	"Install mame emulator"	on \
		XMAME	"Install xmame emulator"	off \
		SNES9X	"Install snes9x emulator"	on \
		ZSNES	"Install zsnes emulator"	off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_MAME)
RUN_DEPENDS+=	mame:${PORTSDIR}/emulators/mame
.endif

.if defined(WITH_XMAME)
RUN_DEPENDS+=	xmame:${PORTSDIR}/emulators/xmame
.endif

.if !defined(WITHOUT_SNES9X)
RUN_DEPENDS+=	snes9x:${PORTSDIR}/emulators/snes9x
.endif

.if defined(WITH_ZSNES)
RUN_DEPENDS+=	zsnes:${PORTSDIR}/emulators/zsnes
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
