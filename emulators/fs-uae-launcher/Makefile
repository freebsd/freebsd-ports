# Created by: Uffe Jakobsen <uffe@uffe.org>
# $FreeBSD$

PORTNAME=	fs-uae-launcher
PORTVERSION=	2.4.1
CATEGORIES=	emulators
MASTER_SITES=	http://fs-uae.net/fs-uae/stable/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI launcher for the FS-UAE Amiga emulator

LICENSE=	GPLv2

USES=		gettext gmake pathfix python:2.7 shebangfix

INSTALLS_ICONS=	yes
MAKE_ARGS=	DESTDIR=${STAGEDIR} prefix=${PREFIX}

do-build:
	(cd ${WRKSRC} && ${PYTHON_CMD} setup.py build)
	(cd ${WRKSRC} && ${PYTHON_CMD} \
		setup.py install --root ${STAGEDIR} --prefix ${PREFIX})

.include <bsd.port.mk>
