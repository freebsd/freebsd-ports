# New ports collection makefile for:	kdebindings4-python
# Date created:		2009-02-13
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdebindings
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde python
MASTER_SITES=	# empty
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	# empty

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Meta-port of Python bindings for KDE

USE_KDE4=	kdeprefix
USE_PYTHON=	yes
PYTHON_NO_DEPENDS=	yes
NO_BUILD=	yes

OPTIONS=	KROSSPYTHON "Kross Python scripting library" on \
		PYKDE4 "KDE bindings" on

.include <bsd.port.options.mk>

.if !defined(WITHOUT_KROSSPYTHON)
RUN_DEPENDS+=	${KDE4_PREFIX}/lib/kde4/krosspython.so:${PORTSDIR}/devel/kdebindings4-python-krosspython
.endif

.if !defined(WITHOUT_PYKDE4)
RUN_DEPENDS+=	${KDE4_PREFIX}/lib/kde4/kpythonpluginfactory.so:${PORTSDIR}/devel/kdebindings4-python-pykde4 \
		${KDE4_PREFIX}/bin/pykdeuic4:${PORTSDIR}/devel/kdebindings4-python-pykdeuic4
.endif

do-install:
	${DO_NADA}

.include <bsd.port.mk>
