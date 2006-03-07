# New ports collection makefile for:	mindguard
# Date created:		27 July 2000
# Whom:			kris
#
# $FreeBSD$
#

PORTNAME=	mindguard
PORTVERSION=	0.0.0.4
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

DOCS=	algorithms.html antarctic.html author.html \
	biorhythm.html carriers.html cia.html \
	depsych.html diagnostic.html failure.html \
	fbi.html features.html fetus.html \
	index.html install.html interface.html \
	introduction.html jam.html kpsi.html \
	lead.html liberati.html log.html \
	mgjamtab.png mglogtab.png mgmisctab.png \
	mgpl.html mgpsid.png mgwin.png \
	numerology.html prefs.html psident.html \
	quit.html reticulan.html russian.html \
	scan.html simulacra.html style.css \
	tikiroom.html un.html usage.html \
	versions.html

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mindguard ${X11BASE}/bin/mindguard
	${MKDIR} ${X11BASE}/share/mindguard
.for i in ${CARRIERS}
	${INSTALL_DATA} ${WRKSRC}/carriers/$i ${X11BASE}/share/mindguard
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${X11BASE}/share/doc/mindguard
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/$i ${X11BASE}/share/doc/mindguard
.endfor
.endif

.include <bsd.port.mk>
