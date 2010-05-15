# New ports collection makefile for:   cad/salome
# Date created:        16 Oct 2009
# Whom:            Stas Timokhin <devel@stasyan.com>
#
# $FreeBSD$

PORTNAME=	salome
PORTVERSION=	5.1.3
PORTREVISION=	2
CATEGORIES=	cad science
MASTER_SITES=	http://www.stasyan.com/devel/distfiles/
DISTNAME=	src5.1.3
DIST_SUBDIR=	${PORTNAME}
.if !defined(PKGNAMESUFFIX)
EXTRACT_ONLY=	#none
.endif

MAINTAINER=	devel@stasyan.com

OPTIONS=	\
		GEOM		"GEOM module" 					on  \
		MED		"MED module" 					on  \
		SMESH		"SMESH module (require MED & GEOM)" 		on  \
		VISU		"VISU module (require MED)" 			on  \
		LIGHT		"LIGHT module" 					on  \
		YACS		"Yacs module" 					on  \
		MULTIPR		"Multipr module" 				on  \
		RANDOMIZER	"Randomizer module" 				on  \
		SIERPINSKY	"Sierpinsky module" 				on  \
		CPPUNIT		"build with C++ unit testing framework" 	off \
		MPI		"build with support parrallel calculation" 	off

RESOURCEDIR=	${DATADIR}/resources

SLAVEDIRS=	cad/salome-kernel cad/salome-gui cad/salome-geom cad/salome-light	\
		cad/salome-yacs cad/salome-randomizer cad/salome-visu cad/salome-med	\
		cad/salome-sierpinsky cad/salome-smesh cad/salome-multipr

.include <bsd.port.options.mk>

.if !defined(PKGNAMESUFFIX)
COMMENT=	Metaport for cad/salome

NO_BUILD=	yes

.include <bsd.port.pre.mk>

RUN_DEPENDS+=	${RESOURCEDIR}/kernel:${PORTSDIR}/cad/salome-kernel \
				${RESOURCEDIR}/gui:${PORTSDIR}/cad/salome-gui

.if defined(WITH_GEOM)
RUN_DEPENDS+=	${RESOURCEDIR}/geom:${PORTSDIR}/cad/salome-geom
.endif
.if defined(WITH_LIGHT)
RUN_DEPENDS+=	${RESOURCEDIR}/light:${PORTSDIR}/cad/salome-light
.endif
.if defined(WITH_YACS)
RUN_DEPENDS+=	${RESOURCEDIR}/yacs:${PORTSDIR}/cad/salome-yacs
.endif
.if defined(WITH_RANDOMIZER)
RUN_DEPENDS+=	${RESOURCEDIR}/randomizer:${PORTSDIR}/cad/salome-randomizer
.endif
.if defined(WITH_VISU)
RUN_DEPENDS+=	${RESOURCEDIR}/visu:${PORTSDIR}/cad/salome-visu
.endif
.if defined(WITH_MED)
RUN_DEPENDS+=	${RESOURCEDIR}/med:${PORTSDIR}/cad/salome-med
.endif
.if defined(WITH_SIERPINSKY)
RUN_DEPENDS+=	${RESOURCEDIR}/sierpinsky:${PORTSDIR}/cad/salome-sierpinsky
.endif
.if defined(WITH_SMESH)
RUN_DEPENDS+=	${RESOURCEDIR}/smesh:${PORTSDIR}/cad/salome-smesh
.endif
.if defined(WITH_MULTIPR)
RUN_DEPENDS+=	${RESOURCEDIR}/multipr:${PORTSDIR}/cad/salome-multipr
.endif

SUB_LIST=	PREFIX=${PREFIX}
SUB_FILES=	pkg-message runSalome.csh
PLIST_FILES=	bin/runSalome.csh

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/runSalome.csh ${PREFIX}/bin/runSalome.csh

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
.else
.include "${MASTERDIR}/Makefile.ext"
.endif
