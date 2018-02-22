# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kdeaccessibility
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	3
CATEGORIES=	accessibility kde
PKGNAMESUFFIX=	-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Accessibility applications for KDE 4

USES=		kde:4 metaport

OPTIONS_DEFINE=	JOVIE KACCESSIBLE KMAG KMOUSETOOL KMOUTH
OPTIONS_DEFAULT:=	${OPTIONS_DEFINE}

JOVIE_DESC=		Install Jovie text-to-speech system
JOVIE_RUN_DEPENDS=	${KDE_PREFIX}/bin/jovie:accessibility/jovie-kde4

KACCESSIBLE_DESC=	Install Accessibility services for KDE
KACCESSIBLE_RUN_DEPENDS=	${KDE_PREFIX}/lib/kde4/libexec/kaccessibleapp:accessibility/kaccessible-kde4

KMAG_DESC=		Install Screen magnifier
KMAG_RUN_DEPENDS=	${KDE_PREFIX}/bin/kmag:accessibility/kmag-kde4

KMOUSETOOL_DESC=	Install Automatic mouse click tool
KMOUSETOOL_RUN_DEPENDS=	${KDE_PREFIX}/bin/kmousetool:accessibility/kmousetool-kde4

KMOUTH_DESC=		Install Speech synthesizer frontend
KMOUTH_RUN_DEPENDS=	${KDE_PREFIX}/bin/kmouth:accessibility/kmouth-kde4

.include <bsd.port.mk>
