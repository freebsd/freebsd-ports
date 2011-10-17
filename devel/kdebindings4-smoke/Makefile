# New ports collection makefile for:	kdebindings4-smoke
# Date created:				1 September 2011
# Whom:					Alberto Villa <avilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdebindings-smoke
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Meta port of SMOKE bindings for KDE

USE_KDE4=	kdeprefix
NO_BUILD=	yes

OPTIONS=	SMOKEKDE "KDE bindings (requires SMOKEQT)" on \
		SMOKEQT "Qt bindings" on

.include <bsd.port.options.mk>

.if !defined(WITHOUT_SMOKEKDE)
RUN_DEPENDS+=	${KDE4_PREFIX}/lib/libsmokekdecore.so:${PORTSDIR}/devel/kdebindings4-smoke-smokekde
.endif

.if !defined(WITHOUT_SMOKEQT) || !defined(WITHOUT_SMOKEKDE)
RUN_DEPENDS+=	${KDE4_PREFIX}/lib/libsmokeqtcore.so:${PORTSDIR}/devel/kdebindings4-smoke-smokeqt
.endif

do-install:
	${DO_NADA}

.include <bsd.port.mk>
