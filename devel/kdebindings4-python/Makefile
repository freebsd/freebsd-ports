# New ports collection makefile for:	kdebindings4-python
# Date created:		2009-02-13
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdebindings
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde
MASTER_SITES=	# empty
PKGNAMESUFFIX=	-python
DISTFILES=	# none

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Meta port of Python bindings for KDE

USE_KDE4=	kdeprefix
NO_BUILD=	yes
# NO_INSTALL=	yes

OPTIONS+=	KROSSPYTHON "Kross Python scripting library" on
OPTIONS+=	PYKDE4 "Kde bindings" on

.include <bsd.port.options.mk>

.if !defined(WITHOUT_KROSSPYTHON)
RUN_DEPENDS+=	${KDE4_PREFIX}/lib/kde4/krosspython.so:${PORTSDIR}/devel/kdebindings4-python-krosspython
.endif

.if !defined(WITHOUT_PYKDE4)
RUN_DEPENDS+=	${KDE4_PREFIX}/lib/kde4/kpythonpluginfactory.so:${PORTSDIR}/devel/kdebindings4-python-pykde4 \
		${LOCALBASE}/bin/pykdeuic4:${PORTSDIR}/devel/kdebindings4-python-pykdeuic4
.endif

do-install:
	${DO_NADA}

.include <bsd.port.mk>
