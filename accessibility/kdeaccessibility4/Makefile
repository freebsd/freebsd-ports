# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kdeaccessibility
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	accessibility kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Accessibility applications for KDE4

USE_KDE4=	kdeprefix
NO_BUILD=	yes

LATEST_LINK=	${PORTNAME}4

OPTIONS_DEFINE=	JOVIE KACCESSIBLE KMAG KMOUSETOOL KMOUTH
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

JOVIE_DESC=		Install Jovie text-to-speech system
KACCESSIBLE_DESC=	Install Accessibility services for KDE
KMAG_DESC=		Install Screen magnifier
KMOUSETOOL_DESC=	Install Automatic mouse click tool
KMOUTH_DESC=		Install Speech synthesizer frontend

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJOVIE}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/jovie:${PORTSDIR}/accessibility/jovie
.endif

.if ${PORT_OPTIONS:MKACCESSIBLE}
RUN_DEPENDS+=	${KDE4_PREFIX}/lib/kde4/libexec/kaccessibleapp:${PORTSDIR}/accessibility/kaccessible
.endif

.if ${PORT_OPTIONS:MKMAG}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kmag:${PORTSDIR}/accessibility/kmag
.endif

.if ${PORT_OPTIONS:MKMOUSETOOL}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kmousetool:${PORTSDIR}/accessibility/kmousetool
.endif

.if ${PORT_OPTIONS:MKMOUTH}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kmouth:${PORTSDIR}/accessibility/kmouth
.endif

do-install:
	${DO_NADA}

.include <bsd.port.mk>
