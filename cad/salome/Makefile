# Created by: Stas Timokhin <devel@stasyan.com>
# $FreeBSD$

PORTNAME=	salome
PORTVERSION=	5.1.4
PORTREVISION?=	5
CATEGORIES=	cad science
MASTER_SITES=	http://www.stasyan.com/devel/distfiles/
DISTNAME=	src5.1.4
DIST_SUBDIR=	${PORTNAME}
.if !defined(PKGNAMESUFFIX)
EXTRACT_ONLY=	#none
.endif

MAINTAINER=	devel@stasyan.com

OPTIONS_DEFINE=	GEOM MED SMESH NETGENPLUGIN VISU LIGHT YACS MULTIPR RANDOMIZER SIERPINSKY
OPTIONS_DEFAULT= GEOM MED SMESH NETGENPLUGIN VISU LIGHT YACS MULTIPR RANDOMIZER SIERPINSKY
GEOM_DESC=		GEOM module
MED_DESC=		MED module
SMESH_DESC=		SMESH module (require MED & GEOM)
NETGENPLUGIN_DESC=	Netgen-meser plugin
VISU_DESC=		VISU module (require MED)
LIGHT_DESC=		LIGHT module
YACS_DESC=		Yacs module
MULTIPR_DESC=		Multipr module
RANDOMIZER_DESC=	Randomizer module
SIERPINSKY_DESC=	Sierpinsky module
JOBMAN_DESC=		Job manager module
MPI_DESC=		build with support parrallel calculation

RESOURCEDIR=	${PREFIX}/share/salome/resources

SLAVEDIRS=	cad/salome-kernel cad/salome-gui cad/salome-geom cad/salome-light	\
		cad/salome-yacs cad/salome-randomizer cad/salome-visu cad/salome-med	\
		cad/salome-sierpinsky cad/salome-smesh cad/salome-multipr cad/salome-jobmanager \
		cad/salome-netgenplugin

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if !defined(PKGNAMESUFFIX)
COMMENT=	Metaport for cad/salome

NO_BUILD=	yes

.include <bsd.port.pre.mk>

RUN_DEPENDS+=	${RESOURCEDIR}/kernel:${PORTSDIR}/cad/salome-kernel \
				${RESOURCEDIR}/gui:${PORTSDIR}/cad/salome-gui

.if ${PORT_OPTIONS:MGEOM}
RUN_DEPENDS+=	${RESOURCEDIR}/geom:${PORTSDIR}/cad/salome-geom
.endif
.if ${PORT_OPTIONS:MLIGHT}
RUN_DEPENDS+=	${RESOURCEDIR}/light:${PORTSDIR}/cad/salome-light
.endif
.if ${PORT_OPTIONS:MYACS}
RUN_DEPENDS+=	${RESOURCEDIR}/yacs:${PORTSDIR}/cad/salome-yacs
.endif
.if ${PORT_OPTIONS:MRANDOMIZER}
RUN_DEPENDS+=	${RESOURCEDIR}/randomizer:${PORTSDIR}/cad/salome-randomizer
.endif
.if ${PORT_OPTIONS:MVISU}
RUN_DEPENDS+=	${RESOURCEDIR}/visu:${PORTSDIR}/cad/salome-visu
.endif
.if ${PORT_OPTIONS:MMED}
RUN_DEPENDS+=	${RESOURCEDIR}/med:${PORTSDIR}/cad/salome-med
.endif
.if ${PORT_OPTIONS:MSIERPINSKY}
RUN_DEPENDS+=	${RESOURCEDIR}/sierpinsky:${PORTSDIR}/cad/salome-sierpinsky
.endif
.if ${PORT_OPTIONS:MSMESH}
RUN_DEPENDS+=	${RESOURCEDIR}/smesh:${PORTSDIR}/cad/salome-smesh
.endif
.if ${PORT_OPTIONS:MNETGENPLUGIN}
RUN_DEPENDS+=	${RESOURCEDIR}/netgenplugin:${PORTSDIR}/cad/salome-netgenplugin
.endif
.if ${PORT_OPTIONS:MMULTIPR}
RUN_DEPENDS+=	${RESOURCEDIR}/multipr:${PORTSDIR}/cad/salome-multipr
.endif
.if ${PORT_OPTIONS:MJOBMAN}
RUN_DEPENDS+=	${RESOURCEDIR}/jobmanager:${PORTSDIR}/cad/salome-jobmanager
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
