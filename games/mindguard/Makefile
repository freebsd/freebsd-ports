# New ports collection makefile for:	mindguard
# Date created:		27 July 2000
# Whom:			kris
#
# $FreeBSD$
#

PORTNAME=	mindguard
PORTVERSION=	0.0.0.3
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://zapatopi.net/mindguard/
EXTRACT_SUFX=	.tgz

MAINTAINER=	kris@FreeBSD.org
COMMENT=	Helpful utility for detecting and jamming harmful mind-control rays

USE_X_PREFIX=	yes
USE_GNOME=	gtk12

ALL_TARGET=	# empty

CARRIERS=	antarctic.carrier belgian.carrier beta.carrier \
		brother.carrier kpsi.carrier liberati.carrier \
		reticulian.carrier russel.carrier tz8.carrier \
		unmetric.carrier

DOCS=	index.html mg01.html mg02.html mg03.html mg04.html \
		mg05.html mg06.html mg07.html mg08.html mg09.html \
		mg10.html mg11.html mg12.html mg13.html mg14.html \
		mg15.html mg16.html mg17.html mg18.html mg19.html \
		mg20.html mg21.html mg22.html mg23.html mg30.html \
		mg31.html mg32.html mg33.html mg40.html mg41.html \
		mg42.html mg43.html mg44.html mg45.html mg46.html \
		mg47.html mg48.html mg60.html mgjamtab.png \
		mglogtab.png mgmisctab.png mgpsid.png mgwin.png \
		style.css

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mindguard ${X11BASE}/bin/mindguard
	${MKDIR} ${X11BASE}/share/mindguard
.for i in ${CARRIERS}
	${INSTALL_DATA} ${WRKSRC}/carriers/$i ${X11BASE}/share/mindguard
.endfor
	${MKDIR} ${X11BASE}/share/doc/mindguard
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/$i ${X11BASE}/share/doc/mindguard
.endfor

.include <bsd.port.mk>
