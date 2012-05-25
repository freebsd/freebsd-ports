# New ports collection Makefile for:	kdeaccessibility
# Date created:				2008-01-31
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
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

OPTIONS=	JOVIE "Install Jovie text-to-speech system" on \
		KACCESSIBLE "Install Accessibility services for KDE" on \
		KMAG "Install Screen magnifier" on \
		KMOUSETOOL "Install Automatic mouse click tool" on \
		KMOUTH "Install Speech synthesizer frontend" on

.include <bsd.port.options.mk>

.ifndef(WITHOUT_JOVIE)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/jovie:${PORTSDIR}/accessibility/jovie
.endif

.ifndef(WITHOUT_KACCESSIBLE)
RUN_DEPENDS+=	${KDE4_PREFIX}/lib/kde4/libexec/kaccessibleapp:${PORTSDIR}/accessibility/kaccessible
.endif

.ifndef(WITHOUT_KMAG)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kmag:${PORTSDIR}/accessibility/kmag
.endif

.ifndef(WITHOUT_KMOUSETOOL)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kmousetool:${PORTSDIR}/accessibility/kmousetool
.endif

.ifndef(WITHOUT_KMOUTH)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kmouth:${PORTSDIR}/accessibility/kmouth
.endif

do-install:
	${DO_NADA}

.include <bsd.port.mk>
