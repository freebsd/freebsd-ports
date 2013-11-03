# Created by: kris
# $FreeBSD$

PORTNAME=	mindguard
PORTVERSION=	0.0.0.4
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://zapatopi.net/mindguard/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Helpful utility for detecting and jamming harmful mind-control rays

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

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mindguard ${STAGEDIR}${PREFIX}/bin/mindguard
	${MKDIR} ${STAGEDIR}${PREFIX}/share/mindguard
.for i in ${CARRIERS}
	${INSTALL_DATA} ${WRKSRC}/carriers/$i ${STAGEDIR}${PREFIX}/share/mindguard
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/mindguard
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/$i ${STAGEDIR}${PREFIX}/share/doc/mindguard
.endfor

.include <bsd.port.mk>
