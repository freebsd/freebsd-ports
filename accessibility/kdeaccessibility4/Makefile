# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kdeaccessibility
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	2
CATEGORIES=	accessibility kde
DISTFILES=	# empty

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Accessibility applications for KDE 4

USE_KDE4=	kdeprefix
NO_BUILD=	yes
NO_INSTALL=	yes
NO_MTREE=	yes

OPTIONS_DEFINE=	JOVIE KACCESSIBLE KMAG KMOUSETOOL KMOUTH
OPTIONS_DEFAULT:=	${OPTIONS_DEFINE}

JOVIE_DESC=		Install Jovie text-to-speech system
JOVIE_RUN_DEPENDS=	${KDE4_PREFIX}/bin/jovie:${PORTSDIR}/accessibility/jovie

KACCESSIBLE_DESC=	Install Accessibility services for KDE
KACCESSIBLE_RUN_DEPENDS=	${KDE4_PREFIX}/lib/kde4/libexec/kaccessibleapp:${PORTSDIR}/accessibility/kaccessible

KMAG_DESC=		Install Screen magnifier
KMAG_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kmag:${PORTSDIR}/accessibility/kmag

KMOUSETOOL_DESC=	Install Automatic mouse click tool
KMOUSETOOL_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kmousetool:${PORTSDIR}/accessibility/kmousetool

KMOUTH_DESC=		Install Speech synthesizer frontend
KMOUTH_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kmouth:${PORTSDIR}/accessibility/kmouth

.include <bsd.port.mk>
