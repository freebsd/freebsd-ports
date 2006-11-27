# New ports collection makefile for:	tclgeomap
# Date created:		25 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tclgeomap
PORTVERSION=	2.10.1
CATEGORIES=	astro tcl84
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	tkgeomap

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Read, manipulate and display geo data

LIB_DEPENDS=	tcl${USE_TCL}.1:${PORTSDIR}/lang/tcl${USE_TCL}

USE_TCL=	yes
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/unix
PLIST_SUB=	INC=include/${PORTNAME} \
		LIB=lib/${PORTNAME}
MAKE_ENV=	MKLINKS_FLAGS=-s
USE_LDCONFIG=	yes

MAN3=	geoLn.3 geoLnArr.3 geoLnArrToMap.3 geoProj.3 geography.3 mapLn.3 mapLnArr.3 tclgeomap.3
MANN=	tclgeomap.n tclgeomap_procs.n
MLINKS=	\
	geoLn.3 GeoLn.3 \
	geoLn.3 GeoLnAddPt.3 \
	geoLn.3 GeoLnClear.3 \
	geoLn.3 GeoLnContainGeoPt.3 \
	geoLn.3 GeoLnCreate.3 \
	geoLn.3 GeoLnCtr.3 \
	geoLn.3 GeoLnDestroy.3 \
	geoLn.3 GeoLnGetPt.3 \
	geoLn.3 GeoLnInfo.3 \
	geoLn.3 GeoLnSetAlloc.3 \
	geoLnArr.3 GeoLnArr.3 \
	geoLnArr.3 GeoLnArrAddLine.3 \
	geoLnArr.3 GeoLnArrContainGeoPt.3 \
	geoLnArr.3 GeoLnArrCreate.3 \
	geoLnArr.3 GeoLnArrDestroy,.3 \
	geoLnArr.3 GeoLnArrFree.3 \
	geoLnArr.3 GeoLnArrGetDescr.3 \
	geoLnArr.3 GeoLnArrGetInfo.3 \
	geoLnArr.3 GeoLnArrGetLine.3 \
	geoLnArr.3 GeoLnArrPutLine.3 \
	geoLnArr.3 GeoLnArrSetAlloc.3 \
	geoLnArr.3 GeoLnArrSetDescr.3 \
	geoProj.3 GeoProj.3 \
	geoProj.3 GeoProjAlloc.3 \
	geoProj.3 GeoProjDescriptor.3 \
	geoProj.3 GeoProjDestroy.3 \
	geoProj.3 GeoProjFree.3 \
	geoProj.3 GeoProjGetInfo.3 \
	geoProj.3 GeoProjGetType.3 \
	geoProj.3 GeoProjInit.3 \
	geoProj.3 LatLonToProj.3 \
	geoProj.3 ProjToLatLon.3 \
	geoProj.3 SetCylEqArea.3 \
	geoProj.3 SetCylEqDist.3 \
	geoProj.3 SetLambertConfConic.3 \
	geoProj.3 SetLambertEqArea.3 \
	geoProj.3 SetMercator.3 \
	geoProj.3 SetOrthographic.3 \
	geoProj.3 SetStereographic.3 \
	geography.3 AngleCmp.3 \
	geography.3 AngleFmDeg.3 \
	geography.3 AngleFmRad.3 \
	geography.3 AngleIsBad.3 \
	geography.3 AngleIsOK.3 \
	geography.3 AngleToDeg.3 \
	geography.3 AngleToRad.3 \
	geography.3 Azimuth.3 \
	geography.3 BadAngle.3 \
	geography.3 DeleteRotation.3 \
	geography.3 DomainLat.3 \
	geography.3 DomainLon.3 \
	geography.3 DomainLonPt.3 \
	geography.3 GCircleX.3 \
	geography.3 GeoDistance.3 \
	geography.3 GeoPtGetDeg.3 \
	geography.3 GeoPtGetRad.3 \
	geography.3 GeoPtIsNowhere.3 \
	geography.3 GeoPtIsSomewhere.3 \
	geography.3 GeoPtNowhere.3 \
	geography.3 GeoPtSetDeg.3 \
	geography.3 GeoPtSetRad.3 \
	geography.3 GeoQuickDistance.3 \
	geography.3 GeoStep.3 \
	geography.3 GetRotation.3 \
	geography.3 GwchLon.3 \
	geography.3 GwchLonPt.3 \
	geography.3 ICos.3 \
	geography.3 ISin.3 \
	geography.3 LatCmp.3 \
	geography.3 LonBtwn.3 \
	geography.3 LonBtwn1.3 \
	geography.3 LonCmp.3 \
	geography.3 MapPtIsNowhere.3 \
	geography.3 MapPtIsSomewhere.3 \
	geography.3 MapPtNowhere.3 \
	geography.3 NewRotation.3 \
	geography.3 REarth.3 \
	geography.3 Rotate.3 \
	geography.3 Rotation.3 \
	geography.3 ScaleMapPt.3 \
	geography.3 SetREarth.3 \
	geography.3 SetRotation.3 \
	mapLn.3 MapLn.3 \
	mapLn.3 MapLnAddPt.3 \
	mapLn.3 MapLnClear.3 \
	mapLn.3 MapLnCreate.3 \
	mapLn.3 MapLnDestroy.3 \
	mapLn.3 MapLnGetInfo.3 \
	mapLn.3 MapLnGetPt.3 \
	mapLn.3 MapLnSetAlloc.3 \
	mapLnArr.3 MapLnArr.3 \
	mapLnArr.3 MapLnArrAddLine.3 \
	mapLnArr.3 MapLnArrCreate.3 \
	mapLnArr.3 MapLnArrDestroy.3 \
	mapLnArr.3 MapLnArrGetDescr.3 \
	mapLnArr.3 MapLnArrGetInfo.3 \
	mapLnArr.3 MapLnArrGetLine.3 \
	mapLnArr.3 MapLnArrSet.3 \
	mapLnArr.3 MapLnArrSetAlloc.3 \
	mapLnArr.3 MapLnArrSetDescr.3 \
	tclgeomap.3 Tclgeomap_AddLnArr.3 \
	tclgeomap.3 Tclgeomap_AddLnArrDeleteTask.3 \
	tclgeomap.3 Tclgeomap_AddPlaceDeleteTask.3 \
	tclgeomap.3 Tclgeomap_AddPlaceUpdateTask.3 \
	tclgeomap.3 Tclgeomap_AddProjDeleteTask.3 \
	tclgeomap.3 Tclgeomap_AddProjUpdateTask.3 \
	tclgeomap.3 Tclgeomap_CnxLnArrDeleteTask.3 \
	tclgeomap.3 Tclgeomap_CnxPlaceDeleteTask.3 \
	tclgeomap.3 Tclgeomap_CnxPlaceUpdateTask.3 \
	tclgeomap.3 Tclgeomap_CnxProjDeleteTask.3 \
	tclgeomap.3 Tclgeomap_CnxProjUpdateTask.3 \
	tclgeomap.3 Tclgeomap_GetGeoPtFromObj.3 \
	tclgeomap.3 Tclgeomap_GetLnArr.3 \
	tclgeomap.3 Tclgeomap_GetMapPtFromObj.3 \
	tclgeomap.3 Tclgeomap_GetPlace.3 \
	tclgeomap.3 Tclgeomap_GetProj.3 \
	tclgeomap.3 Tclgeomap_Init.3 \
	tclgeomap.3 Tclgeomap_LnArrName.3 \
	tclgeomap.3 Tclgeomap_NewGeoPtObj.3 \
	tclgeomap.3 Tclgeomap_NewMapPtObj.3 \
	tclgeomap.3 Tclgeomap_PlaceLoc.3 \
	tclgeomap.3 Tclgeomap_PlaceName.3 \
	tclgeomap.3 Tclgeomap_ProjName.3 \
	tclgeomap.3 Tclgeomap_SetGeoPtObj.3 \
	tclgeomap.3 Tclgeomap_SetMapPtObj.3 \
	tclgeomap.n cartg.n \
	tclgeomap.n dectodm.n \
	tclgeomap.n dectodms.n \
	tclgeomap.n dmstodec.n \
	tclgeomap.n domnlat.n \
	tclgeomap.n domnlon.n \
	tclgeomap.n domnlonpt.n \
	tclgeomap.n gclcross.n \
	tclgeomap.n georadius.n \
	tclgeomap.n gwchlon.n \
	tclgeomap.n gwchpt.n \
	tclgeomap.n latlonok.n \
	tclgeomap.n lnarr.n \
	tclgeomap.n lonbtwn.n \
	tclgeomap.n mapptok.n \
	tclgeomap.n place.n \
	tclgeomap.n projection.n \
	tclgeomap.n rotatpt.n \
	tclgeomap.n scalept.n \
	tclgeomap_procs.n circle.n \
	tclgeomap_procs.n fillsegment.n \
	tclgeomap_procs.n grid_list.n \
	tclgeomap_procs.n latitude.n \
	tclgeomap_procs.n latlon.n \
	tclgeomap_procs.n longitude.n \
	tclgeomap_procs.n ocean_list.n

post-install:
	@${LN} -sf ${PREFIX}/lib/libtclgeomap2.9.so ${PREFIX}/lib/libtclgeomap2.9.so.0
	@${LN} -sf ${PREFIX}/lib/libtclgeomap2.9.so ${PREFIX}/lib/libtclgeomap.so.0

post-patch:
	@${REINPLACE_CMD} -e 's/@PACKAGE@@VERSION@/@PACKAGE@/g' ${WRKSRC}/Makefile.in ${WRKSRC}/pkgIndex.tcl.in

# Maintainer section
MY_MLINKS:
	@cd ${MAN3PREFIX}/man/man3/ && ls -l `${FIND} . -type l` | ${GREP} -E '(geo|mapLn)' | ${SED} -Ee 's#^.*\./(.*) -> (.*)$$#\2 \1 \\#' | ${SORT} -u
	@cd ${MANNPREFIX}/man/mann/ && ls -l `${FIND} . -type l` | ${GREP} -E '(geo|mapLn)' | ${SED} -Ee 's#^.*\./(.*) -> (.*)$$#\2 \1 \\#' | ${SORT} -u

.include <bsd.port.mk>
