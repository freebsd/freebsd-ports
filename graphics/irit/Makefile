# New ports collection makefile for:	irit
# Date created:		6 August 2002
# Whom:			Igor Pokrovsky <tiamat@telegraph.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	irit
PORTVERSION=	8.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.cs.technion.ac.il/~irit/
DISTNAME=	${PORTNAME}-sm

MAINTAINER=	tiamat@comset.net
COMMENT=	Solid modelling system

NO_WRKSUBDIR=	yes
USE_ZIP=	yes
USE_XLIB=	yes
USE_REINPLACE=	yes
.ifndef (WITHOUT_MOTIF)
USE_MOTIF=	yes
.endif
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/irit

MAKEFILE=	makefile.unx
MAKE_ENV=	WRKSRC=${WRKSRC} LD_LIBRARY_PATH=${WRKSRC}/lib PATH=${PATH}:${WRKSRC}/bin

MAN3=	AfdApplyEStep.3 AfdApplyLn.3 AfdBzrCrvEvalToPolyline.3 \
	AfdCnvrtCubicBzrToAfd.3 AfdComputePolyline.3 Attr2String.3 \
	AttrCopyAttributes.3 AttrFindAttribute.3 AttrFreeAttributes.3 \
	AttrFreeObjectAttribute.3 AttrFreeOneAttribute.3 AttrGetColor.3 \
	AttrGetIntAttrib.3 AttrGetMAttribCount.3 AttrGetMIntAttrib.3 \
	AttrGetMRealAttrib.3 AttrGetObjAttrib.3 AttrGetObjectColor.3 \
	AttrGetObjectIntAttrib.3 AttrGetObjectObjAttrib.3 AttrGetObjectPtrAttrib.3 \
	AttrGetObjectRGBColor.3 AttrGetObjectRealAttrib.3 AttrGetObjectStrAttrib.3 \
	AttrGetObjectUVAttrib.3 AttrGetObjectWidth.3 AttrGetPtrAttrib.3 \
	AttrGetRGBColor.3 AttrGetRealAttrib.3 AttrGetStrAttrib.3 \
	AttrGetUVAttrib.3 AttrGetWidth.3 AttrReverseAttributes.3 AttrSetColor.3 \
	AttrSetIntAttrib.3 AttrSetObjAttrib.3 AttrSetObjectColor.3 \
	AttrSetObjectIntAttrib.3 AttrSetObjectObjAttrib.3 AttrSetObjectPtrAttrib.3 \
	AttrSetObjectRGBColor.3 AttrSetObjectRealAttrib.3 AttrSetObjectStrAttrib.3 \
	AttrSetObjectUVAttrib.3 AttrSetObjectWidth.3 AttrSetPtrAttrib.3 \
	AttrSetRGBColor.3 AttrSetRealAttrib.3 AttrSetStrAttrib.3 \
	AttrSetUVAttrib.3 AttrSetWidth.3 AttrTraceAttributes.3 \
	BoolCutPolygonAtRay.3 BoolExtractPolygons.3 BoolFilterCollinearities.3 \
	BoolGenAdjacencies.3 BoolInterPolyPoly.3 BoolLoopsFromInterList.3 \
	BoolSetHandleCoplanarPoly.3 BoolSetOutputInterCurve.3 BoolSetParamSurfaceUVVals.3 \
	BoolSetPolySortAxis.3 BoolSortOpenInterList.3 Boolean2D.3 \
	Boolean2DComputeInters.3 BooleanAND.3 BooleanCUT.3 \
	BooleanComputeRotatedPolys.3 BooleanICUT.3 BooleanLow1In2.3 \
	BooleanLow1Out2.3 BooleanLowSelfInOut.3 BooleanMERGE.3 BooleanNEG.3 \
	BooleanOR.3 BooleanSELF.3 BooleanSUB.3 BspC1Srf2Polygons.3 \
	BspCrv2Polyline.3 BspCrvBiNormal.3 BspCrvCoxDeBoorBasis.3 \
	BspCrvCoxDeBoorIndexFIrst.3 BspCrvCreateCircle.3 BspCrvCreatePCircle.3 \
	BspCrvCreateUnitCircle.3 BspCrvCreateUnitPCircle.3 BspCrvDegreeRaise.3 \
	BspCrvDegreeRaiseN.3 BspCrvDerive.3 BspCrvDeriveRational.3 \
	BspCrvDeriveScalar.3 BspCrvDomain.3 BspCrvEvalAtParam.3 \
	BspCrvEvalCoxDeBoor.3 BspCrvEvalVecAtParam.3 BspCrvFitLstSqr.3 \
	BspCrvHasBezierKV.3 BspCrvHasOpenEC.3 BspCrvIntegrate.3 \
	BspCrvInterpPts.3 BspCrvInterpPtsError.3 BspCrvInterpolate.3 \
	BspCrvKnotInsert.3 BspCrvKnotInsertNDiff.3 BspCrvKnotInsertNSame.3 \
	BspCrvMaxCoefParam.3 BspCrvMeshC1Continuous.3 BspCrvMoebiusTransform.3 \
	BspCrvMult.3 BspCrvNew.3 BspCrvNoraml.3 BspCrvOpenEnd.3 BspCrvReadFromFile.3 \
	BspCrvReadFromFile2.3 BspCrvSubdivAtParam.3 BspCrvTangent.3 \
	BspCrvWriteToFile.3 BspCrvWriteToFile2.3 BspIsKnotUniform.3 \
	BspKnotAffineTrans.3 BspKnotAffineTrans2.3 BspKnotAffineTransOrder.3 \
	BspKnotAffineTransOrder2.3 BspKnotAllC1Discont.3 BspKnotAverage.3 \
	BspKnotC1Discont.3 BspKnotContinuityMergeTwo.3 BspKnotCopy.3 \
	BspKnotDegreeRaisedK.3 BspKnotEvalAlphaCoef.3 BspKnotEvalAlphaCoefMerge.3 \
	BspKnotFindMult.3 BspKnotFirstIndexG.3 BspKnotFreeAlphaCoef.3 \
	BspKnotHasBezierKV.3 BspKnotHasOpenEC.3 BspKnotInsertMult.3 \
	BspKnotInsertOne.3 BspKnotLastIndexL.3 BspKnotLastIndexLE.3 BspKnotMergeTwo.3 \
	BspKnotNodes.3 BspKnotParamInDomain.3 BspKnotParamValues.3 \
	BspKnotPrepEquallySpaced.3 BspKnotReverse.3 BspKnotScale.3 \
	BspKnotSubtrTwo.3 BspKnotUniformFloat.3 BspKnotUniformOpen.3 \
	BspKnotUniformPeriodic.3 BspKnotVectorsSame.3 BspKnotVerifyPeriodicK.3 \
	BspMVMult.3 BspMakeReparamCurve.3 BspMultInterpFlag.3 \
	BspPeriodicCrvNew.3 BspPeriodicSrfNew.3 BspPtSamplesToK.3 \
	BspSrf2Curves.3 BspSrf2PolygonSetErrFunc.3 BspSrf2Polygons.3 \
	BspSrf2Polylines.3 BspSrfC1DiscontCrvs.3 BspSrfCrvFromMesh.3 \
	BspSrfCrvFromSrf.3 BspSrfDegreeRaise.3 BspSrfDegreeRaiseN.3 \
	BspSrfDerive.3 BspSrfDeriveRational.3 BspSrfDeriveScalar.3 \
	BspSrfDomain.3 BspSrfEvalAtParam.3 BspSrfEvalAtParam2.3 \
	BspSrfFactorUMinus.3 BspSrfFitLstSqr.3 BspSrfHasBezierKVs.3 \
	BspSrfHasOpenEC.3 BspSrfHasOpenECDir.3 BspSrfInterpPts.3 \
	BspSrfInterpScatPts.3 BspSrfInterpScatPts2.3 BspSrfInterpolate.3 \
	BspSrfIsC1DiscontAt.3 BspSrfKnotInsert.3 BspSrfKnotInsertNDiff.3 \
	BspSrfKnotInsertNSame.3 BspSrfMaxCoefParam.3 BspSrfMeshC1Continuous.3 \
	BspSrfMeshNormals.3 BspSrfMeshNormalsSymb.3 BspSrfMoebiusTransform.3 \
	BspSrfMult.3 BspSrfNew.3 BspSrfNormal.3 BspSrfOpenEnd.3 \
	BspSrfReadFromFile.3 BspSrfReadFromFile2.3 BspSrfSubdivAtParam.3 \
	BspSrfTangent.3 BspSrfWriteToFile.3 BspSrfWriteToFile2.3 \
	BzrApproxBzrCrvAsCubicPoly.3 BzrApproxBzrCrvAsCubics.3 BzrComposeCrvCrv.3 \
	BzrComposeSrfCrv.3 BzrCrv2Polyline.3 BzrCrvBiNormal.3 \
	BzrCrvCreateArc.3 BzrCrvDegreeRaise.3 BzrCrvDegreeRaiseN.3 \
	BzrCrvDegreeRreduce.3 BzrCrvDerive.3 BzrCrvDeriveRational.3 \
	BzrCrvDeriveScalar.3 BzrCrvEvalAtParam.3 BzrCrvEvalToPolyline.3 \
	BzrCrvEvalVecAtParam.3 BzrCrvIntegrate.3 BzrCrvInterp.3 \
	BzrCrvMoebiusTransform.3 BzrCrvMult.3 BzrCrvMultList.3 \
	BzrCrvNew.3 BzrCrvNoraml.3 BzrCrvReadFromFile.3 \
	BzrCrvReadFromFile2.3 BzrCrvSetCache.3 BzrCrvSubdivAtParam.3 \
	BzrCrvTangent.3 BzrCrvWriteToFile.3 BzrCrvWriteToFile2.3 \
	BzrMVMult.3 BzrSrf2Curves.3 BzrSrf2Polygons.3 BzrSrf2Polylines.3 \
	BzrSrfCrvFromMesh.3 BzrSrfCrvFromSrf.3 BzrSrfDegreeRaise.3 \
	BzrSrfDerive.3 BzrSrfDeriveRational.3 BzrSrfDeriveScalar.3 \
	BzrSrfEvalAtParam.3 BzrSrfFactorBilinear.3 BzrSrfFactorUMinus.3 \
	BzrSrfMeshNormals.3 BzrSrfMoebiusTransform.3 BzrSrfMult.3 \
	BzrSrfNew.3 BzrSrfNormal.3 BzrSrfReadFromFile.3 BzrSrfReadFromFile2.3 \
	BzrSrfSubdivAtParam.3 BzrSrfTangent.3 BzrSrfWriteToFile.3 \
	BzrSrfWriteToFile2.3 CagdAllWeightsNegative.3 CagdAllWeightsSame.3 \
	CagdBBoxArrayFree.3 CagdBBoxArrayNew.3 CagdBBoxCopy.3 CagdBBoxCopyList.3 \
	CagdBBoxFree.3 CagdBBoxFreeList.3 CagdBBoxNew.3 CagdBilinearSrf.3 \
	CagdBlossomEval.3 CagdBoolSumSrf.3 CagdCoerceCrvTo.3 CagdCoercePointTo.3 \
	CagdCoercePointsTo.3 CagdCoerceSrfTo.3 CagdCoerceToE2.3 \
	CagdCoerceToP2.3 CagdCoerceToP3.3 CagdCreateConicCurve.3 CagdCreateConicCurve2.3 \
	CagdCreateQuadricSrf.3 CagdCrv2CtrlPoly.3 CagdCrvBBox.3 CagdCrvBiNormal.3 \
	CagdCrvBlossomDegreeRaise.3 CagdCrvBlossomDegreeRaiseN.3 \
	CagdCrvBlossomEval.3 CagdCrvCopy.3 CagdCrvCopyList.3 CagdCrvCreateArc.3 \
	CagdCrvCrvInter.3 CagdCrvDegreeRaise.3 CagdCrvDegreeRaiseN.3 \
	CagdCrvDegreeReduce.3 CagdCrvDerive.3 CagdCrvDeriveScalar.3 \
	CagdCrvDomain.3 CagdCrvEval.3 CagdCrvEvalToPolyline.3 CagdCrvFirstMoments.3 \
	CagdCrvFree.3 CagdCrvFreeList.3 CagdCrvFromMesh.3 CagdCrvFromSrf.3 \
	CagdCrvIntegrate.3 CagdCrvListBBox.3 CagdCrvMatTransform.3 \
	CagdCrvMinMax.3 CagdCrvMoebiusTransform.3 CagdCrvNew.3 CagdCrvNodes.3 \
	CagdCrvNormal.3 CagdCrvReadFromFile.3 CagdCrvReadFromFile2.3 \
	CagdCrvRefineAtParams.3 CagdCrvRegionFromCrv.3 CagdCrvReverse.3 \
	CagdCrvRotateToXY.3 CagdCrvRotateToXYMat.3 CagdCrvScale.3 \
	CagdCrvSubdivAtParam.3 CagdCrvTanAngularSpan.3 CagdCrvTangent.3 \
	CagdCrvToMesh.3 CagdCrvTransform.3 CagdCrvWriteToFile.3 \
	CagdCrvWriteToFile2.3 CagdCrvWriteToFile3.3 CagdCrvsSame.3 \
	CagdCtlMeshsSame.3 CagdCtlPtArrayFree.3 CagdCtlPtArrayNew.3 \
	CagdCtlPtCopy.3 CagdCtlPtCopyList.3 CagdCtlPtFree.3 CagdCtlPtFreeList.3 \
	CagdCtlPtNew.3 CagdCubicHermiteCrv.3 CagdCubicHermiteSrf.3 CagdDbg.3 \
	CagdDescribeError.3 CagdDistPtPlane.3 CagdDistTwoCtlPt.3 \
	CagdEditSingleCrvPt.3 CagdEditSingleSrfPt.3 CagdEstimateCrvCollinearity.3 \
	CagdEstimateSrfPlanarity.3 CagdEvaluateSurfaceVecField.3 CagdExtrudeSrf.3 \
	CagdFatalError.3 CagdFitPlaneThruCtlPts.3 CagdIChooseK.3 CagdIsClosedCrv.3 \
	CagdIsClosedSrf.3 CagdListAppend.3 CagdListInsert.3 CagdListLast.3 \
	CagdListLength.3 CagdListReverse.3 CagdMakeCrvsCompatible.3 CagdMakeRectangle.3 \
	CagdMakeSrfsCompatible.3 CagdMakeTriangle.3 CagdMatTransform.3 \
	CagdMatchDistNorm.3 CagdMatchMorphNorm.3 CagdMatchRuledNorm.3 \
	CagdMatchingTwoCurves.3 CagdMergeBBox.3 CagdMergeCrvCrv.3 \
	CagdMergeCrvList.3 CagdMergeCrvPt.3 CagdMergePointType.3 \
	CagdMergePtCrv.3 CagdMergePtPt.3 CagdMergeSrfList.3 CagdMergeSrfSrf.3 \
	CagdPeriodicCrvNew.3 CagdPeriodicSrfNew.3 CagdPlaneArrayFree.3 \
	CagdPlaneArrayNew.3 CagdPlaneCopy.3 CagdPlaneCopyList.3 CagdPlaneFree.3 \
	CagdPlaneFreeList.3 CagdPlaneNew.3 CagdPointsBBox.3 CagdPointsHasPoles.3 \
	CagdPolyApproxErrEstimate.3 CagdPolyApproxErrs.3 CagdPolyApproxMaxErr.3 \
	CagdPolygonArrayNew.3 CagdPolygonCopy.3 CagdPolygonCopyList.3 \
	CagdPolygonFree.3 CagdPolygonFreeList.3 CagdPolygonNew.3 \
	CagdPolygonSetErrFunc.3 CagdPolygonStripNew.3 CagdPolylineArrayNew.3 \
	CagdPolylineCopy.3 CagdPolylineCopyList.3 CagdPolylineFree.3 \
	CagdPolylineFreeList.3 CagdPolylineNew.3 CagdPrimCone2Srf.3 \
	CagdPrimConeSrf.3 CagdPrimCylinderSrf.3 CagdPrimPlaneSrf.3 CagdPrimSphereSrf.3 \
	CagdPrimTorusSrf.3 CagdPromoteCrvToSrf.3 CagdPtArrayFree.3 CagdPtArrayNew.3 \
	CagdPtCopy.3 CagdPtCopyList.3 CagdPtFree.3 CagdPtFreeList.3 CagdPtNew.3 \
	CagdRuledSrf.3 CagdScale.3 CagdSetLinear2Poly.3 CagdSparseMatFree.3 \
	CagdSparseMatMultNonSparseResult.3 CagdSparseMatNew.3 CagdSparseMatNewCell.3 \
	CagdSparseMatTranspose.3 CagdSrf2CtrlMesh.3 CagdSrf2PolygonFast.3 \
	CagdSrf2PolygonStrip.3 CagdSrf2Polygons.3 CagdSrf2PolygonsGenPolys.3 \
	CagdSrf2Polylines.3 CagdSrfBBox.3 CagdSrfBlossomDegreeRaise.3 \
	CagdSrfBlossomDegreeRaiseN.3 CagdSrfCopy.3 CagdSrfCopyList.3 \
	CagdSrfDegreeRaise.3 CagdSrfDegreeRaiseN.3 CagdSrfDerive.3 \
	CagdSrfDeriveScalar.3 CagdSrfDomain.3 CagdSrfEffiNrmlEval.3 \
	CagdSrfEffiNrmlPostlude.3 CagdSrfEffiNrmlPrelude.3 CagdSrfEval.3 \
	CagdSrfFree.3 CagdSrfFreeList.3 CagdSrfFromCrvs.3 CagdSrfListBBox.3 \
	CagdSrfMatTransform.3 CagdSrfMinMax.3 CagdSrfMoebiusTransform.3 \
	CagdSrfNew.3 CagdSrfNodes.3 CagdSrfNormal.3 CagdSrfReadFromFile.3 \
	CagdSrfReadFromFile2.3 CagdSrfRefineAtParams.3 CagdSrfRegionFromSrf.3 \
	CagdSrfReverse.3 CagdSrfScale.3 CagdSrfSubdivAtParam.3 CagdSrfTangent.3 \
	CagdSrfTransform.3 CagdSrfWriteToFile.3 CagdSrfWriteToFile2.3 \
	CagdSrfWriteToFile3.3 CagdSrfsSame.3 CagdSurfaceRev.3 CagdSurfaceRev2.3 \
	CagdSurfaceRevPolynomialApprox.3 CagdSweepAxisRefine.3 CagdSweepSrf.3 \
	CagdTightBBox.3 CagdTransform.3 CagdUVArrayFree.3 CagdUVArrayNew.3 \
	CagdUVCopy.3 CagdUVCopyList.3 CagdUVFree.3 CagdUVFreeList.3 CagdUVNew.3 \
	CagdVecArrayFree.3 CagdVecArrayNew.3 CagdVecCopy.3 CagdVecCopyList.3 \
	CagdVecFree.3 CagdVecFreeList.3 CagdVecNew.3 CnvrtBezier2BsplineCrv.3 \
	CnvrtBezier2BsplineSrf.3 CnvrtBezier2PowerCrv.3 CnvrtBezier2PowerSrf.3 \
	CnvrtBspline2BezierSrf.3 CnvrtFloat2OpenSrf.3 CnvrtPeriodic2FloatCrv.3 \
	CnvrtPeriodic2FloatSrf.3 CnvrtPolyline2LinBsplineCrv.3 CnvrtPower2BezierCrv.3 \
	CnvrtPower2BezierSrf.3 Config.3 ConfigPrint.3 CopyObject.3 \
	CopyObjectList.3 CopyPolygonList.3 CopyVertexList.3 ExecuteAnimationEvalMat.3 \
	GAGetArgs.3 GAPrintErrMsg.3 GAPrintHowTo.3 GM2PointsFromCircCirc.3 \
	GM2PointsFromCircCirc3D.3 GM2PointsFromLineLine.3 GMAnimDoAnimation.3 \
	GMAnimDoSingleStep.3 GMAnimEvalAnimation.3 GMAnimEvalAnimationList.3 \
	GMAnimFindAnimationTime.3 GMAnimFindAnimationTimeOne.3 GMAnimGenAnimInfoText.3 \
	GMAnimHasAnimation.3 GMAnimHasAnimationOne.3 GMAnimResetAnimStruct.3 \
	GMAnimSaveIterationsToFiles.3 GMAnimSetAnimInternalNodes.3 GMBBComputeBboxObject.3 \
	GMBBComputeBboxObjectList.3 GMBBComputeOnePolyBbox.3 GMBBComputeOnePolyListBbox.3 \
	GMBBComputePointBbox.3 GMBBMergeBbox.3 GMBaryCentric3Pts.3 \
	GMBlendNormalsToVertices.3 GMCleanUpPolygonList.3 GMCleanUpPolylineList.3 \
	GMCollinear3Pts.3 GMCollinear3PtsInside.3 GMCollinear3Vertices.3 \
	GMConvertPolysToTriangles.3 GMConvexHull.3 GMConvexPolyNormals.3 \
	GMConvexPolyObject.3 GMConvexPolyObjectN.3 GMConvexPolygon.3 \
	GMCoplanar4Pts.3 GMDecimateObjSetDcmRatioParam.3 GMDecimateObjSetDistParam.3 \
	GMDecimateObjSetMinAspRatioParam.3 GMDecimateObjSetPassNumParam.3 GMDecimateObject.3 \
	GMDistLineLine.3 GMDistPoint1DWithEnergy.3 GMDistPointLine.3 \
	GMDistPointPlane.3 GMDistPointPoint.3 GMFilterInteriorVertices.3 \
	GMFindLinComb2Vecs.3 GMGMSphConeSetConeDensity.3 GMGenMatObjectRotVec.3 \
	GMGenMatObjectRotX.3 GMGenMatObjectRotY.3 GMGenMatObjectRotZ.3 \
	GMGenMatObjectScale.3 GMGenMatObjectTrans.3 GMGenMatObjectZ2Dir.3 \
	GMGenMatrixRotVec.3 GMGenMatrixX2Dir.3 GMGenMatrixY2Dir.3 \
	GMGenMatrixZ2Dir.3 GMGenMatrixZ2Dir2.3 GMGenTransMatrixZ2Dir.3 \
	GMGenTransMatrixZ2Dir2.3 GMGetMatTransPortion.3 GMInterpNrmlBetweenTwo.3 \
	GMInterpNrmlBetweenTwo2.3 GMLineSweep.3 GMMatFromPosDir.3 \
	GMMatchPointListIntoPolylines.3 GMMatrixToTransform.3 GMPlaneFrom3Points.3 \
	GMPointCoverOfPolyObj.3 GMPointCoverOfUnitHemiSphere.3 GMPointFrom3Planes.3 \
	GMPointFromLinePlane.3 GMPointFromLinePlane01.3 GMPointFromPointLine.3 \
	GMPolyCountPolys.3 GMPolyObjectArea.3 GMPolyObjectVolume.3 \
	GMPolyOffset.3 GMPolyOffsetAmountDepth.3 GMPolygonRayInter.3 \
	GMPolygonRayInter3D.3 GMPolygonalMorphosis.3 GMQuatAdd.3 \
	GMQuatExp.3 GMQuatInverse.3 GMQuatIsUnitQuat.3 \
	GMQuatLog.3 GMQuatMatToQuat.3 GMQuatMatrixToAngles.3 \
	GMQuatMatrixToScale.3 GMQuatMatrixToTranslation.3 GMQuatMatrixToVector.3 \
	GMQuatMul.3 GMQuatNormalize.3 GMQuatPow.3 \
	GMQuatRotateVec.3 GMQuatRotationToQuat.3 GMQuatToMat.3 \
	GMQuatToRotation.3 GMQuatVecToRotMatrix.3 GMQuatVecToScaleMatrix.3 \
	GMQuatVecToTransMatrix.3 GMQuatVectorToMatrix.3 GMRegularizeTriangleModel.3 \
	GMScanConvertTriangle.3 GMSilExtractBndry.3 GMSilExtractSil.3 \
	GMSilExtractSilDirect.3 GMSilOrigObjAlive.3 GMSilPreprocessPolys.3 \
	GMSilPreprocessRefine.3 GMSilProprocessFree.3 GMSolveCubicEqn.3 \
	GMSolveQuadraticEqn.3 GMSphConeQuery2GetVectors.3 GMSphConeQueryFree.3 \
	GMSphConeQueryGetVectors.3 GMSphConeQueryInit.3 GMSplitNonConvexPoly.3 \
	GMTransObjUpdateAnimCrvs.3 GMTransObjUpdateFuncType.3 GMTransformObject.3 \
	GMTransformObjectList.3 GMUpdateVerticesNormals.3 GMVecCopy.3 \
	GMVecCrossProd.3 GMVecDotProd.3 GMVecLength.3 \
	GMVecNormalize.3 GMVrtxListToCirc.3 GMZBufferClear.3 \
	GMZBufferFree.3 GMZBufferInit.3 GMZBufferInvert.3 \
	GMZBufferLaplacian.3 GMZBufferOGLClear.3 GMZBufferOGLFlush.3 \
	GMZBufferOGLInit.3 GMZBufferOGLMakeActive.3 GMZBufferOGLQueryColor.3 \
	GMZBufferOGLQueryZ.3 GMZBufferOGLSetColor.3 GMZBufferQueryZ.3 \
	GMZBufferRoberts.3 GMZBufferUpdateHLn.3 GMZBufferUpdateLine.3 \
	GMZBufferUpdatePt.3 GMZBufferUpdateTri.3 GenCRVObject.3 \
	GenCTLPTObject.3 GenCrvObject.3 GenCtlPtObject.3 \
	GenINSTNCObject.3 GenInstncObject.3 GenLISTObject.3 \
	GenListObject.3 GenMATObject.3 GenMODELObject.3 \
	GenMULTIVARObject.3 GenMatObject.3 GenModelObject.3 \
	GenMultiVarObject.3 GenNUMObject.3 GenNUMValObject.3 \
	GenNumObject.3 GenPLANEObject.3 GenPOLYGONObject.3 \
	GenPOLYObject.3 GenPTObject.3 GenPlaneObject.3 \
	GenPolyObject.3 GenPtObject.3 GenRotateMatrix.3 \
	GenSRFObject.3 GenSTRObject.3 GenSrfObject.3 \
	GenStrObject.3 GenTRIMSRFObject.3 GenTRISRFObject.3 \
	GenTRIVARObject.3 GenTriSrfObject.3 GenTrimSrfObject.3 \
	GenTrivarObject.3 GenVECObject.3 GenVecObject.3 \
	GeomDescribeError.3 GeomFatalError.3 Gregory2Bezier.3 \
	HDSCnvrtPObj2QTree.3 HDSFreeOctree.3 HDSThreshold.3 \
	HDSTriBudget.3 IPAllacPolygon.3 IPAllocObject.3 \
	IPAllocVertex.3 IPAllocVertex2.3 IPAppendListObjects.3 \
	IPAppendObjLists.3 IPAppendPolyLists.3 IPAppendVrtxLists.3 \
	IPCagdPlgns2IritPlgns.3 IPCagdPllns2IritPllns.3 IPCloseStream.3 \
	IPClosedPolysToOpen.3 IPCnvDataToIrit.3 IPCnvSetPrintFunc.3 \
	IPCoerceCommonSpace.3 IPCoerceObjectTo.3 IPCoercePtsListTo.3 \
	IPConcatFreeForm.3 IPConvertFreeForm.3 IPCurve2CtlPoly.3 \
	IPCurve2Polylines.3 IPCurvesToCubicBzrCrvs.3 IPEvalFreeForms.3 \
	IPFilterDegeneracies.3 IPFlattenForrest.3 \
	IPFlattenTree.3 IPForEachPoly.3 IPForEachVertex.3 \
	IPFreeForm2CubicBzr.3 IPFreeForm2Polygons.3 IPFreeForm2Polylines.3 \
	IPFreeObject.3 IPFreeObjectList.3 IPFreeObjectSlots.3 \
	IPFreePolygon.3 IPFreePolygonList.3 IPFreeVertex.3 \
	IPFreeVertexList.3 IPGetBinObject.3 IPGetDataFiles.3 \
	IPGetFileType.3 IPGetLastObj.3 IPGetLastPoly.3 \
	IPGetLastVrtx.3 IPGetObjectByName.3 IPGetObjects.3 \
	IPGetPrevObj.3 IPGetPrevPoly.3 IPGetPrevVrtx.3 \
	IPInputUnGetC.3 IPIsConsistentFreeObjList.3 IPIsConvexPolygon.3 \
	IPIsFreeObject.3 IPMapObjectInPlace.3 IPMergePolylines.3 \
	IPODAddDependencyToObj.3 IPODAddParameterToObj.3 IPODCopyDependencies.3 \
	IPODCopyDependenciesOfObj.3 IPODCopyParametersOfObj.3 IPODDelDependencyFromObj.3 \
	IPODDelParameterFromObj.3 IPODEvalOneObject.3 IPODFreeDependencies.3 \
	IPODFreeDependenciesOfObj.3 IPODFreeParametersOfObj.3 IPODNewDependencies.3 \
	IPODNewDependenciesOfObj.3 IPODNewParametersOfObj.3 IPODPrintDependencies.3 \
	IPODUpdateAllDependencies.3 IPObjListLen.3 IPObjLnkListToListObject.3 \
	IPOpenDataFile.3 IPOpenPolysToClosed.3 IPOpenStreamFromFile.3 \
	IPOpenStreamFromFileEx.3 IPOpenStreamFromSocket.3 IPOpenStreamFromVrml.3 \
	IPParseError.3 IPPolyListLen.3 IPPolyline2Curve.3 \
	IPProcessFreeForm.3 IPProcessReadObject.3 IPPropagateAttr.3 \
	IPPutBinObject.3 IPPutObjectToFile.3 IPPutObjectToHandler.3 \
	IPPutVrmlViewPoint.3 IPResolveInstances.3 IPReverseListObj.3 \
	IPReverseObjList.3 IPReversePlList.3 \
	IPReverseVrtxList2.3 IPSenseBinaryFile.3 IPSetCopyObjectReferenceCount.3 \
	IPSetCurvesToCubicBzrTol.3 IPSetFlattenObjects.3 IPSetFloatFormat.3 \
	IPSetPolyListCirc.3 IPSetPrintFunc.3 IPSetPropagateAttrs.3 \
	IPSetReadOneObject.3 IPSetSubObjectName.3 IPSetVrmlExternalMode.3 \
	IPSocClntInit.3 IPSocEchoInput.3 IPSocExecAndConnect.3 \
	IPSocHandleClientEvent.3 IPSocReadCharNonBlock.3 IPSocReadLineNonBlock.3 \
	IPSocReadOneObject.3 IPSocSrvrInit.3 IPSocSrvrListen.3 \
	IPSocWriteLine.3 IPSocWriteOneObject.3 IPSrf2OptPolysSetUserTolFunc.3 \
	IPSrvrDisConnectAndKill.3 IPStderrObject.3 IPStdoutObject.3 \
	IPSurface2CtlMesh.3 IPSurface2Polygons.3 IPSurface2Polylines.3 \
	IPSurfacesToCubicBzrCrvs.3 IPSurfacesToCubicBzrSrfs.3 IPTraverseObjListHierarchy.3 \
	IPTriSrf2CtlMesh.3 IPTriSrf2Polygons.3 IPTriSrf2Polylines.3 \
	IPTriSrfsToCubicBzrCrvs.3 IPTrimSrf2CtlMesh.3 IPTrimSrf2Polygons.3 \
	IPTrimSrf2Polylines.3 IPTrimSrfsToCubicBzrCrvs.3 IPTrivar2CtlMesh.3 \
	IPTrivar2Polygons.3 IPTrivar2Polylines.3 IPTrivarToCubicBzrCrvs.3 \
	IPUpdatePolyPlane.3 IPUpdatePolyPlane2.3 IPUpdateVrtxNrml.3 \
	IPVrtxListLen.3 IntrSrfRayFreePreprocess.3 IntrSrfRayPreprocessSrf.3 \
	IntrSrfRayTestRay.3 IritCPUTime.3 IritDebugMallocReset.3 \
	IritFatalError.3 IritFree.3 IritMalloc.3 \
	IritPQDelete.3 IritPQEmpty.3 IritPQFind.3 \
	IritPQFirst.3 IritPQFree.3 IritPQFreeFunc.3 \
	IritPQInit.3 IritPQInsert.3 IritPQNext.3 \
	IritPQPrint.3 IritPQSize.3 IritQRFactorization.3 \
	IritQRUnderdetermined.3 IritRandom.3 IritRandomInit.3 \
	IritRealTimeDate.3 IritRealloc.3 IritSleep.3 \
	IritSolveLowerDiagMatrix.3 IritSolveUpperDiagMatrix.3 IritStrdup.3 \
	IritTestAllDynMemory.3 IritWarningError.3 IrtImgReadImage.3 \
	IrtImgReadImage2.3 IrtImgWriteCloseFile.3 IrtImgWriteOpenFile.3 \
	IrtImgWritePutLine.3 IrtImgWriteSetType.3 JacobiMatrixDiag4x4.3 \
	JacobiMatrixDiagNxN.3 ListObjectFind.3 ListObjectGet.3 \
	ListObjectInsert.3 ListObjectLength.3 MCExtractIsoSurface.3 \
	MCExtractIsoSurface2.3 MCImprovePointOnIsoSrf.3 MCThresholdCube.3 \
	MakeTextGeometry.3 MatAddTwo4by4.3 MatDeterminantMatrix.3 \
	MatGenMatRotX.3 MatGenMatRotX1.3 MatGenMatRotY.3 \
	MatGenMatRotY1.3 MatGenMatRotZ.3 MatGenMatRotZ1.3 \
	MatGenMatScale.3 MatGenMatTrans.3 MatGenMatUnifScale.3 \
	MatGenUnitMat.3 MatInverseMatrix.3 MatIsUnitMat.3 \
	MatMultPtby4by4.3 MatMultTwo4by4.3 MatMultVecby4by4.3 \
	MatMultWVecby4by4.3 MatRotateFactorMatrix.3 MatScale4by4.3 \
	MatScaleFactorMatrix.3 MatSubTwo4by4.3 MatTranslateFactorMatrix.3 \
	MdlReadModelSrfFromFile.3 MdlWriteModelToFile.3 MdlWriteModelToFile2.3 \
	MdlWriteModelToFile3.3 MvarBspMVDerive.3 MvarBspMVDeriveRational.3 \
	MvarBspMVKnotInsertNDiff.3 MvarBspMVReadFromFile.3 MvarBspMVReadFromFile2.3 \
	MvarBspMVWriteToFile2.3 MvarBspMultInterpFlag.3 MvarBspNew.3 \
	MvarBzrMVDerive.3 MvarBzrMVDeriveRational.3 MvarBzrMVReadFromFile.3 \
	MvarBzrMVReadFromFile2.3 MvarBzrMVWriteToFile.3 MvarBzrMVWriteToFile2.3 \
	MvarBzrNew.3 MvarCnvrtBezier2BsplineMV.3 MvarCnvrtBspline2BezierMV.3 \
	MvarCoerceMVTo.3 MvarComputeRayTraps.3 MvarCrvSrfBisector.3 \
	MvarCrvSrfBisectorApprox.3 MvarCrvToMV.3 MvarDbg.3 \
	MvarDescribeError.3 MvarEditSingleMVPt.3 MvarFatalError.3 \
	MvarGetPointsMeshIndices.3 MvarIncBoundMeshIndices.3 MvarIncSkipMeshIndices.3 \
	MvarIncrementMeshIndices.3 MvarMVAdd.3 MvarMVBBox.3 \
	MvarMVBiTangents.3 MvarMVCopy.3 MvarMVCopyList.3 \
	MvarMVCrossProd.3 MvarMVDegreeRaise.3 MvarMVDegreeRaise2.3 \
	MvarMVDegreeRaiseN.3 MvarMVDerive.3 MvarMVDeterminant2.3 \
	MvarMVDeterminant3.3 MvarMVDeterminant4.3 MvarMVDeterminant5.3 \
	MvarMVDomain.3 MvarMVDotProd.3 MvarMVEval.3 \
	MvarMVEvalGradientNumer.3 MvarMVEvalTanPlaneNumer.3 MvarMVFree.3 \
	MvarMVFreeList.3 MvarMVFromMV.3 MvarMVFromMesh.3 \
	MvarMVInvert.3 MvarMVListBBox.3 MvarMVMatTransform.3 \
	MvarMVMergeScalar.3 MvarMVMult.3 MvarMVMultScalar.3 \
	MvarMVNew.3 MvarMVReadFromFile.3 MvarMVReadFromFile2.3 \
	MvarMVRefineAtParams.3 MvarMVRegionFromMV.3 MvarMVReverse.3 \
	MvarMVRtnlMult.3 MvarMVScalarScale.3 MvarMVShiftAxes.3 \
	MvarMVSplitScalar.3 MvarMVSub.3 MvarMVSubdivAtParam.3 \
	MvarMVToCrv.3 MvarMVToSrf.3 MvarMVToTV.3 \
	MvarMVTransform.3 MvarMVTriTangents.3 MvarMVVecDotProd.3 \
	MvarMVWriteToFile.3 MvarMVWriteToFile2.3 MvarMVWriteToFile3.3 \
	MvarMVsBisector.3 MvarMVsSame.3 MvarMVsZeros.3 \
	MvarMakeMVsCompatible.3 MvarMergeMVMV.3 MvarParamInDomain.3 \
	MvarParamsInDomain.3 MvarPlnCopy.3 MvarPlnCopyList.3 \
	MvarPlnFree.3 MvarPlnFreeList.3 MvarPlnNew.3 \
	MvarPromoteMVToMV.3 MvarPromoteMVToMV2.3 MvarPtCopy.3 \
	MvarPtCopyList.3 MvarPtFree.3 MvarPtFreeList.3 \
	MvarPtNew.3 MvarPtRealloc.3 MvarSkel2DInter3Prims.3 \
	MvarSkel2DInter3PrimsFree.3 MvarSkel2DInter3PrimsFreeList.3 MvarSkel2DSetEpsilon.3 \
	MvarSkel2DSetFineNess.3 MvarSkel2DSetOuterExtent.3 MvarSrfAccessibility.3 \
	MvarSrfSrfBisector.3 MvarSrfSrfBisectorApprox.3 MvarSrfToMV.3 \
	MvarTVToMV.3 MvarTwoMVsMorphing.3 MvarVecCopy.3 \
	MvarVecCopyList.3 MvarVecFree.3 MvarVecFreeList.3 \
	MvarVecNew.3 MvarVecRealloc.3 PQCompFunc.3 \
	PolyOnePolyArea.3 PrimGenBOXObject.3 PrimGenCONE2Object.3 \
	PrimGenCONEObject.3 PrimGenCYLINObject.3 PrimGenEXTRUDEObject.3 \
	PrimGenGBOXObject.3 PrimGenObjectFromPolyList.3 PrimGenPOLYDISKObject.3 \
	PrimGenPOLYGONObject.3 PrimGenPolygon3Vrtx.3 PrimGenPolygon4Vrtx.3 \
	PrimGenRULEDObject.3 PrimGenSPHEREObject.3 PrimGenSURFREV2AxisObject.3 \
	PrimGenSURFREV2Object.3 PrimGenSURFREVAxisObject.3 PrimGenSURFREVObject.3 \
	PrimGenTORUSObject.3 PrimSetResolution.3 ReallocNewTypeObject.3 \
	SetPolygonalPrimitives.3 SetSurfacePrimitiveRational.3 SvdLeastSqr.3 \
	SvdMatrix4x4.3 SvdMatrixNxN.3 SymbAdapIsoExtract.3 \
	SymbAlgebraicSumSrf.3 SymbAllPrisaSrfs.3 SymbBspBasisInnerProd.3 \
	SymbBspBasisInnerProdMat.3 SymbBspBasisInnerProdPrep.3 SymbComposeCrvCrv.3 \
	SymbComposeSrfCrv.3 SymbConeConeBisect.3 SymbConeLineBisect.3 \
	SymbConePlaneBisect.3 SymbConePointBisect.3 SymbConeSphereBisect.3 \
	SymbConicDistCrvCrv.3 SymbCrv2DCurvatureSign.3 SymbCrv2DCurvatureSqr.3 \
	SymbCrv2DExtremCrvtrPts.3 SymbCrv2DInflectionPts.3 SymbCrv2DUnnormNormal.3 \
	SymbCrv2Polyline.3 SymbCrv3DCurvatureNormal.3 SymbCrv3DCurvatureSqr.3 \
	SymbCrv3DRadiusNormal.3 SymbCrvAdapOffset.3 SymbCrvAdapOffsetTrim.3 \
	SymbCrvAdd.3 SymbCrvArcLen.3 SymbCrvArcLenCrv.3 \
	SymbCrvArcLenPoly.3 SymbCrvArcLenSteps.3 SymbCrvBisectors.3 \
	SymbCrvBisectorsSrf.3 SymbCrvBisectorsSrf2.3 SymbCrvBisectorsSrf3.3 \
	SymbCrvCnvxHull.3 SymbCrvConstSet.3 SymbCrvCrossProd.3 \
	SymbCrvCrvBisectOnSphere.3 SymbCrvCrvBisectOnSphere2.3 SymbCrvCrvBisectOnSphere3.3 \
	SymbCrvCrvBisectorSrf3D.3 SymbCrvCrvConvolution.3 SymbCrvCrvInter.3 \
	SymbCrvDeterminant2.3 SymbCrvDeterminant3.3 SymbCrvDiameter.3 \
	SymbCrvDiameterMinMax.3 SymbCrvDotProd.3 SymbCrvEnclosedArea.3 \
	SymbCrvExtremSet.3 SymbCrvInvert.3 SymbCrvLeastSquarOffset.3 \
	SymbCrvListCnvxHull.3 SymbCrvMatchingOffset.3 SymbCrvMergeScalar.3 \
	SymbCrvMult.3 SymbCrvMultScalar.3 SymbCrvMultiResCompos.3 \
	SymbCrvMultiResComposAtT.3 SymbCrvMultiResCopy.3 SymbCrvMultiResDecomp.3 \
	SymbCrvMultiResEdit.3 SymbCrvMultiResFree.3 SymbCrvMultiResNew.3 \
	SymbCrvMultiResRefineLevel.3 SymbCrvOffset.3 SymbCrvOrthotomic.3 \
	SymbCrvPosNegWeights.3 SymbCrvPtBisectorCrv2D.3 SymbCrvPtBisectorSrf3D.3 \
	SymbCrvPtTangents.3 SymbCrvRtnlMult.3 SymbCrvScalarScale.3 \
	SymbCrvSplitScalar.3 SymbCrvSqrtScalar.3 SymbCrvSub.3 \
	SymbCrvSubdivOffset.3 SymbCrvUnitLenScalar.3 SymbCrvVecCrossProd.3 \
	SymbCrvVecDotProd.3 SymbCrvZeroSet.3 SymbCubicBspInjective.3 \
	SymbCylinPlaneBisect.3 SymbCylinPointBisect.3 SymbCylinSphereBisect.3 \
	SymbDescribeError.3 SymbDistCrvLine.3 SymbDistCrvPoint.3 \
	SymbEnvOffsetFromCrv.3 SymbEvalSrfCurvPrep.3 SymbEvalSrfCurvature.3 \
	SymbExtremumCntPtVals.3 SymbFatalError.3 SymbGetParamListAndReset.3 \
	SymbHighlightLnFree.3 SymbHighlightLnGen.3 SymbHighlightLnPrepSrf.3 \
	SymbIsCircularCrv.3 SymbIsConstCrv.3 SymbIsConstSrf.3 \
	SymbIsDevelopSrf.3 SymbIsExtrusionSrf.3 SymbIsLineCrv.3 \
	SymbIsPlanarSrf.3 SymbIsRuledSrf.3 SymbIsSphericalSrf.3 \
	SymbIsSrfOfRevSrf.3 SymbLclDistCrvLine.3 SymbLclDistCrvPoint.3 \
	SymbLimitCrvArcLen.3 SymbMakePosCrvCtlPolyPos.3 SymbMeshAddSub.3 \
	SymbNormalConeForSrf.3 SymbNormalConeOverlap.3 SymbPiecewiseRuledSrfApprox.3 \
	SymbPlaneLineBisect.3 SymbPlanePointBisect.3 SymbPrisaGetCrossSections.3 \
	SymbPrisaGetOneCrossSection.3 SymbPrisaRuledSrf.3 SymbPrmtSclrCrvTo2D.3 \
	SymbPrmtSclrSrfTo3D.3 SymbPtCrvBisectOnSphere.3 SymbPtCrvBisectOnSphere2.3 \
	SymbRflctCircFree.3 SymbRflctCircGen.3 SymbRflctCircPrepSrf.3 \
	SymbRflctLnFree.3 SymbRflctLnGen.3 SymbRflctLnPrepSrf.3 \
	SymbRingRingIntersection.3 SymbRingRingZeroSetFunc.3 SymbRmKntBspCrvCleanKnots.3 \
	SymbRmKntBspCrvRemoveKnots.3 SymbRmKntBspCrvRemoveKnotsError.3 SymbRuledRuledIntersection.3 \
	SymbRuledRuledZeroSetFunc.3 SymbSetAdapIsoExtractMinLevel.3 SymbSphereLineBisect.3 \
	SymbSpherePlaneBisect.3 SymbSpherePointBisect.3 SymbSphereSphereBisect.3 \
	SymbSrf2Curves.3 SymbSrf2OptPolysBilinPolyError.3 SymbSrf2OptPolysCurvatureError.3 \
	SymbSrf2OptPolysCurvatureErrorPrep.3 SymbSrf2OptPolysIsoDirCurvatureErrorPrep.3 SymbSrf2OptimalPolygons.3 \
	SymbSrf2Polygons.3 SymbSrf2Polylines.3 SymbSrfAdd.3 \
	SymbSrfCrossProd.3 SymbSrfCurvatureUpperBound.3 SymbSrfDeterminant2.3 \
	SymbSrfDeterminant3.3 SymbSrfDistCrvCrv.3 SymbSrfDistFindPoints.3 \
	SymbSrfDotProd.3 SymbSrfFff.3 SymbSrfGaussCurvature.3 \
	SymbSrfInvert.3 SymbSrfIsoDirNormalCurvatureBound.3 SymbSrfIsoFocalSrf.3 \
	SymbSrfIsocline.3 SymbSrfMeanCurvatureSqr.3 SymbSrfMeanEvolute.3 \
	SymbSrfMergeScalar.3 SymbSrfMult.3 SymbSrfMultScalar.3 \
	SymbSrfNormalSrf.3 SymbSrfOffset.3 SymbSrfOrthotomic.3 \
	SymbSrfPtBisectorSrf3D.3 SymbSrfRtnlMult.3 SymbSrfScalarScale.3 \
	SymbSrfSilhouette.3 SymbSrfSplitScalar.3 SymbSrfSub.3 \
	SymbSrfSubdivOffset.3 SymbSrfVecCrossProd.3 SymbSrfVecDotProd.3 \
	SymbSwungAlgSumSrf.3 SymbTangentConeForCrv.3 SymbTangentToCrvAtTwoPts.3 \
	SymbTorusPointBisect.3 SymbTorusSphereBisect.3 SymbTwoCrvsMorphing.3 \
	SymbTwoCrvsMorphingCornerCut.3 SymbTwoCrvsMorphingMultiRes.3 SymbTwoSrfsMorphing.3 \
	SymbUniformAprxPtOnCrvDistrib.3 SymbUniformAprxPtOnSrfDistrib.3 SymbUniformAprxPtOnSrfGetDistrib.3 \
	SymbUniformAprxPtOnSrfPrepDistrib.3 TrimAffineTransTrimCurves.3 TrimAllPrisaSrfs.3 \
	TrimClipSrfToTrimCrvs.3 TrimCrvAgainstTrimCrvs.3 TrimCrvCopyList.3 \
	TrimCrvFree.3 TrimCrvFreeList.3 TrimCrvNew.3 \
	TrimCrvSegCopyList.3 TrimCrvSegFree.3 TrimCrvSegFreeList.3 \
	TrimCrvSegNew.3 TrimCrvTrimParamList.3 TrimCrvs2Polylines.3 \
	TrimDbg.3 TrimDescribeError.3 TrimEvalTrimCrvToEuclid.3 \
	TrimFatalError.3 TrimGetTrimmingCurves.3 TrimIntersectCrvsIsoVals.3 \
	TrimIntersectTrimCrvIsoVals.3 TrimIsPointInsideTrimSrf.3 TrimPiecewiseRuledSrfApprox.3 \
	TrimPointInsideTrimmedCrvs.3 TrimPrisaRuledSrf.3 TrimReadTrimmedSrfFromFile.3 \
	TrimRemoveCrvSegTrimCrvSegs.3 TrimRemoveCrvSegTrimCrvs.3 TrimSetEuclidComposedFromU.3 \
	TrimSetNumTrimVrtcsInCell.3 TrimSetTrimCrvLinearApprox.3 TrimSrf2Curves.3 \
	TrimSrf2Polygons.3 TrimSrf2Polygons2.3 TrimSrf2Polylines.3 \
	TrimSrfCopy.3 TrimSrfCopyList.3 TrimSrfDegreeRaise.3 \
	TrimSrfDomain.3 TrimSrfEval.3 TrimSrfFree.3 \
	TrimSrfFreeList.3 TrimSrfMatTransform.3 TrimSrfNew.3 \
	TrimSrfNew2.3 TrimSrfRefineAtParams.3 TrimSrfRegionFromTrimSrf.3 \
	TrimSrfReverse.3 TrimSrfSubdivAtParam.3 TrimSrfTransform.3 \
	TrimSrfTrimCrvAllDomain.3 TrimSrfTrimCrvSquareDomain.3 TrimSrfsFromContours.3 \
	TrimSrfsSame.3 TrimWriteTrimmedSrfToFile.3 TrimWriteTrimmedSrfToFile2.3 \
	TrivBspNew.3 TrivBspTVDegreeRaise.3 TrivBspTVDerive.3 \
	TrivBspTVKnotInsertNDiff.3 TrivBspTVReadFromFile.3 TrivBspTVReadFromFile2.3 \
	TrivBspTVWriteToFile2.3 TrivBzrNew.3 TrivBzrTVDegreeRaise.3 \
	TrivBzrTVDerive.3 TrivBzrTVReadFromFile.3 TrivBzrTVReadFromFile2.3 \
	TrivBzrTVWriteToFile.3 TrivBzrTVWriteToFile2.3 TrivCnvrtBezier2BsplineTV.3 \
	TrivCnvrtBspline2BezierTV.3 TrivCoerceTVTo.3 TrivCoverIsoSurfaceUsingStrokes.3 \
	TrivDbg.3 TrivDescribeError.3 TrivEditSingleTVPt.3 \
	TrivEvalCurvature.3 TrivEvalGradient.3 TrivEvalHessian.3 \
	TrivEvalTVCurvaturePostlude.3 TrivEvalTVCurvaturePrelude.3 TrivExtrudeTV.3 \
	TrivFatalError.3 TrivInterpTrivar.3 TrivLoadVolumeIntoT.3 \
	TrivMakeTVsCompatible.3 TrivParamInDomain.3 TrivParamsInDomain.3 \
	TrivPlaneFrom4Points.3 TrivReadModelFromFile2.3 TrivReadTrimmedSrfFromFile2.3 \
	TrivRuledTV.3 TrivSrfFromMesh.3 TrivSrfFromTV.3 \
	TrivSrfToMesh.3 TrivTV2CtrlMesh.3 TrivTVBBox.3 \
	TrivTVCopy.3 TrivTVCopyList.3 TrivTVDegreeRaise.3 \
	TrivTVDerive.3 TrivTVDeriveScalar.3 TrivTVDomain.3 \
	TrivTVEval.3 TrivTVEval2.3 TrivTVFree.3 \
	TrivTVFreeList.3 TrivTVFromSrfs.3 TrivTVInterpPts.3 \
	TrivTVInterpolate.3 TrivTVListBBox.3 TrivTVMatTransform.3 \
	TrivTVNew.3 TrivTVReadFromFile.3 TrivTVReadFromFile2.3 \
	TrivTVRefineAtParams.3 TrivTVRegionFromTV.3 TrivTVSubdivAtParam.3 \
	TrivTVTransform.3 TrivTVWriteToFile.3 TrivTVWriteToFile2.3 \
	TrivTVWriteToFile3.3 TrivTVsSame.3 TrivTriangleCopy.3 \
	TrivTriangleCopyList.3 TrivTriangleFree.3 TrivTriangleFreeList.3 \
	TrivTriangleNew.3 TrivTwoTVsMorphing.3 TrivVectCross3Vecs.3 \
	TrngBspTriSrfDerive.3 TrngBspTriSrfHasOpenEC.3 TrngBspTriSrfNew.3 \
	TrngBspTriSrfOpenEnd.3 TrngBspTriSrfReadFromFile.3 TrngBspTriSrfReadFromFile2.3 \
	TrngBspTriSrfWriteToFile.3 TrngBspTriSrfWriteToFile2.3 TrngBzrTriSrfDerive.3 \
	TrngBzrTriSrfDirecDerive.3 TrngBzrTriSrfNew.3 TrngBzrTriSrfReadFromFile.3 \
	TrngBzrTriSrfReadFromFile2.3 TrngBzrTriSrfWriteToFile.3 TrngBzrTriSrfWriteToFile2.3 \
	TrngCnvrtBezier2BsplineTriSrf.3 TrngCnvrtGregory2BezierTriSrf.3 TrngCoerceTriSrfTo.3 \
	TrngCrvFromTriSrf.3 TrngDbg.3 TrngDescribeError.3 \
	TrngFatalError.3 TrngGrgTriSrfNew.3 TrngGrgTriSrfReadFromFile.3 \
	TrngGrgTriSrfReadFromFile2.3 TrngGrgTriSrfWriteToFile.3 TrngGrgTriSrfWriteToFile2.3 \
	TrngParamInDomain.3 TrngParamsInDomain.3 TrngTriBzrSrf2Curves.3 \
	TrngTriSrf2Curves.3 TrngTriSrf2Polygons.3 TrngTriSrf2Polylines.3 \
	TrngTriSrfBBox.3 TrngTriSrfCopy.3 TrngTriSrfCopyList.3 \
	TrngTriSrfDerive.3 TrngTriSrfDomain.3 TrngTriSrfEval.3 \
	TrngTriSrfEval2.3 TrngTriSrfFree.3 TrngTriSrfFreeList.3 \
	TrngTriSrfListBBox.3 TrngTriSrfMatTransform.3 TrngTriSrfNew.3 \
	TrngTriSrfReadFromFile.3 TrngTriSrfReadFromFile2.3 TrngTriSrfTransform.3 \
	TrngTriSrfWriteToFile.3 TrngTriSrfWriteToFile2.3 TrngTriSrfWriteToFile3.3 \
	UserCntrSrfWithPlane.3 UserDescribeError.3 UserFatalError.3 \
	UserMarchOnSurface.3 UserMinDistLineBBox.3 UserMinDistLinePolygonList.3 \
	UserMinDistLinePolylineList.3 UserPolyline2LinBsplineCrv.3 UserPolylines2LinBsplineCrvs.3 \
	UserRegisterPointSetSrf.3 UserRegisterTestConvergance.3 UserRegisterTestSrfConvergance.3 \
	UserRegisterTwoPointSets.3 UserSrfSrfInter.3 UserSrfVisibConeDecomp.3 \
	UserTVZeroJacobian.3 UserTrivarZeros.3 UserTwoObjMaxZRelMotion.3 \
	UserViewingConeSrfDomains.3 UserVisibilityClassify.3 _IPFprintf.3 \
	_IPGetCloseParenToken.3 _IPGetToken.3 _IPParserAbort.3 \
	_IPSkipToCloseParenToken.3 _IPUnGetToken.3

MAN6=	3ds2irit.6 abs.6 acos.6 adapiso.6 adwidth.6 aisoshad.6 algsum.6 amiga.6 \
	animation.6 animeval.6 aoffset.6 apollo.6 arc.6 arc360.6 area.6 asin.6 \
	atan.6 atan2.6 attrib.6 attrprop.6 awidth.6 axes.6 bbox.6 bezier_type.6 \
	black.6 blossom.6 blue.6 boolone.6 boolsum.6 box.6 bsctconcon.6 bsctconln.6 \
	bsctconpl.6 bsctconpt.6 bsctconspr.6 bsctcylpl.6 bsctcylpt.6 bsctcylspr.6 \
	bsctplnln.6 bsctplnpt.6 bsctsprln.6 bsctsprpl.6 bsctsprpt.6 bsctsprspr.6 \
	bscttrspt.6 bscttrsspr.6 bsp2bzr.6 bspline_type.6 bugs_and_limitations.6 \
	bzr2bsp.6 carea.6 cbezier.6 cbisector.6 cbspline.6 ccinter.6 ccrvtr.6 \
	cderive.6 cdivide.6 ceditpt.6 cenvoff.6 ceval.6 cextremes.6 chdir.6 \
	cinflect.6 cinteg.6 cinterp.6 circle.6 circpoly.6 clients_all.6 \
	clntclose.6 clntcrsr.6 clntexec.6 clntread.6 clntwrite.6 cmesh.6 \
	cmoebius.6 cmorph.6 cmultires.6 cnormal.6 cnrmlcrv.6 cnvxhull.6 coerce.6 \
	col.6 color.6 commands.6 comment.6 comparison_operators.6 compose.6 \
	con2.6 cone.6 conicsec.6 contour.6 convex.6 coord.6 copyrights.6 cos.6 \
	coveriso.6 coverpt.6 cpoly.6 cpower.6 craise.6 creduce.6 crefine.6 \
	cregion.6 creparam.6 crossec.6 crv2tans.6 crvlndst.6 crvptdst.6 \
	crvpttan.6 csurface.6 ctangent.6 ctlpt.6 ctlpt_type.6 ctrimsrf.6 \
	curve_type.6 cyan.6 cylin.6 czeros.6 dat2bin.6 dat2irit.6 datafile_format.6 \
	depth.6 display_devices.6 drawctlpt.6 dstlnln.6 dstptln.6 dstptpln.6 \
	dxf2irit.6 e1.6 e2.6 e3.6 e4.6 e5.6 e6.6 e7.6 e8.6 e9.6 error.6 evolute.6 \
	exec.6 exit.6 exp.6 extrude.6 false.6 ffcompat.6 ffctlpts.6 ffextreme.6 \
	ffkntvec.6 ffmatch.6 ffmerge.6 ffmesh.6 ffmsize.6 fforder.6 ffpoles.6 \
	ffptdist.6 ffpttype.6 ffsplit.6 first_usage.6 flat4ply.6 floor.6 fmod.6 \
	for.6 free.6 function.6 function_description.6 functions_and_variables.6 \
	gbox.6 general_purpose_functions.6 geom_const.6 geometric_boolean_operations.6 \
	geometrictype_returning_functions.6 getattr.6 getline.6 getname.6 gginter.6 \
	gpolygon.6 gpolyline.6 help.6 hermite.6 homomat.6 hp.6 ibmnt.6 ibmos.6 \
	if.6 igs2irit.6 ihidden.6 illustrt.6 include.6 instance.6 interact.6 \
	iquery.6 irender.6 irit2dxf.6 irit2hgl.6 irit2igs.6 irit2iv.6 irit2nff.6 \
	irit2off.6 irit2plg.6 irit2pov.6 irit2ps.6 irit2ray.6 irit2scn.6 irit2stl.6 \
	irit2wrl.6 irit2xfg.6 iritstate.6 isgeom.6 isocline.6 izebra.6 knotclean.6 \
	knotremove.6 kv_float.6 kv_open.6 kv_periodic.6 language_description.6 \
	line_editing.6 lineshad.6 linterp.6 list.6 list_type.6 ln.6 load.6 loffset.6 \
	log.6 logfile.6 logical_operators.6 machine.6 magenta.6 matdecomp.6 \
	matposdir.6 matrix_type.6 mbisector.6 mderive.6 mdivide.6 mergepoly.6 \
	meshsize.6 meval.6 mfrommesh.6 mfrommv.6 mmerge.6 moffset.6 moment.6 \
	mpromote.6 mraise.6 mrchcube.6 mrefine.6 mregion.6 mreparam.6 mreverse.6 \
	msdos.6 msleep.6 multivar_type.6 mzero.6 nil.6 nref.6 nrmlcone.6 \
	nth.6 numeric_type.6 numerictype_returning_functions.6 obj2irit.6 object_transformation_functions.6 off.6 off2irit.6 \
	offset.6 on.6 orthotomc.6 overloading_astrisk.6 overloading_caret.6 overloading_minus.6 \
	overloading_plus.6 overloading_slash.6 p2.6 p3.6 p4.6 p5.6 p6.6 \
	p7.6 p8.6 p9.6 param_centrip.6 param_chord.6 param_nielfol.6 param_uniform.6 \
	pause.6 pcircle.6 pdecimate.6 pdomain.6 pi.6 plane_type.6 pln3pts.6 \
	pmorph.6 point.6 point_type.6 poly.6 poly3d-h.6 poly3d-r.6 poly_approx_opt.6 \
	poly_approx_tol.6 poly_approx_uv.6 poly_type.6 power.6 power_type.6 ppinter.6 printf.6 \
	priority_of_operators.6 prisa.6 procedure.6 prsp_mat.6 pt3bary.6 pthmspr.6 ptlnpln.6 \
	ptptln.6 pts2plln.6 ptslnln.6 quadric.6 random.6 raytrap.6 red.6 \
	reset.6 resolution.6 rflctln.6 rmattr.6 rotvec.6 rotx.6 roty.6 \
	rotz.6 rotz2v.6 rotz2v2.6 row.6 rrinter.6 ruledsrf.6 ruledtv.6 \
	saccess.6 save.6 sbezier.6 sbisector.6 sbspline.6 scale.6 scrvtr.6 \
	sderive.6 sdivide.6 seditpt.6 setname.6 setup.6 seval.6 sfocal.6 \
	sfromcrvs.6 sgauss.6 sgi.6 silhouette.6 sin.6 sinterp.6 sizeof.6 \
	skel2dint.6 smeansqr.6 smerge.6 smesh.6 smoebius.6 smoothnrml.6 smorph.6 \
	snoc.6 snormal.6 snrmlsrf.6 sparabolc.6 sphere.6 spower.6 sqrt.6 \
	sraise.6 srefine.6 sregion.6 sreparam.6 sreverse.6 srinter.6 ssinter.6 \
	stangent.6 strimsrf.6 string_type.6 strivar.6 sun.6 surface_type.6 surfprev.6 \
	surfrev.6 surfrev2.6 surfrevax2.6 surfrevaxs.6 svisible.6 sweepsrf.6 swpsclsrf.6 \
	swungasum.6 symbcprod.6 symbdiff.6 symbdprod.6 symbiprod.6 symbprod.6 symbsum.6 \
	system.6 system_constants.6 system_variables.6 tan.6 tbezier.6 tbspline.6 tcrvtr.6 \
	tderive.6 tdivide.6 teditpt.6 teval.6 textgeom.6 tfromsrfs.6 thisobj.6 \
	time.6 tinterp.6 tmorph.6 torus.6 traise.6 trans.6 trefine.6 \
	tregion.6 treparam.6 triangl.6 trimsrf.6 trimsrf_type.6 trivar_type.6 trmsrfs.6 \
	true.6 tsbezier.6 tsbspline.6 tsderive.6 tseval.6 tsgregory.6 tsnormal.6 \
	tvload.6 tvzrjacob.6 undef_type.6 unix.6 utilities.6 varlist.6 vector.6 \
	vector_type.6 view.6 view_mat.6 viewobj.6 viewset.6 volume.6 while.6 \
	white.6 yellow.6 zcollide.6

MANCOMPRESSED=	yes

.if defined(WITHOUT_MOTIF)
PLIST_SUB=	WITHOUT_MOTIF="@comment "
.else
PLIST_SUB=	WITHOUT_MOTIF=""
.endif

.ifndef (WITHOUT_MOTIF)
pre-everything::
	@${ECHO_CMD} "Define WITHOUT_MOTIF=yes not to build X11/Motif display drivers"
.endif

do-configure:
.ifdef (WITHOUT_MOTIF)
	@${REINPLACE_CMD} -e 's|^GRAPXMTLIBS|# GRAPXMTLIBS|; \
	s|^GRAPDRVS = nuldrvs x11drvs xmtdrvs|GRAPDRVS = nuldrvs x11drvs|' ${WRKSRC}/makeflag.unx
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/3ds2irit ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/aisoshad ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/dat2bin ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/dat2irit ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/dxf2irit ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/igs2irit ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/ihidden ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/illustrt ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/irender ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/irit ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/irit2dxf ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/irit2hgl ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/irit2igs ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/irit2iv ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/irit2nff ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/irit2off ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/irit2plg ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/irit2pov ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/irit2ps ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/irit2ray ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/irit2scn ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/irit2stl ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/irit2wrl ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/irit2xfg ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/izebra ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/lineshad ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/nuldrvs ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/obj2irit ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/off2irit ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/poly3d-h ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/skeletn1 ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/x11drvs ${PREFIX}/bin
.ifndef (WITHOUT_MOTIF)
	${INSTALL_PROGRAM} ${WRKSRC}/bin/xmtdrvs ${PREFIX}/bin
.endif

	@${MKDIR} ${PREFIX}/lib/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/lib/*.so ${PREFIX}/lib/${PORTNAME}
	@${MKDIR} ${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${PREFIX}/include/${PORTNAME}

	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bin/aisoshad.cfg ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bin/ihidden.cfg ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bin/illustrt.cfg ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bin/irender.cfg ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bin/irit.cfg ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bin/izebra.cfg ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bin/lineshad.cfg ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bin/poly3d-h.cfg ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bin/x11drvs.cfg ${DATADIR}
.ifndef (WITHOUT_MOTIF)
	${INSTALL_DATA} ${WRKSRC}/bin/xmtdrvs.cfg ${DATADIR}
.endif
	${INSTALL_DATA} ${WRKSRC}/bin/iritfont.dat ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bin/iritinit.irt ${DATADIR}

	@${MKDIR} ${EXAMPLESDIR}
	@${MKDIR} ${EXAMPLESDIR}/data
	${INSTALL_DATA} ${WRKSRC}/data/*.* ${EXAMPLESDIR}/data
	@${MKDIR} ${EXAMPLESDIR}/scripts
	${INSTALL_DATA} ${WRKSRC}/scripts/*.irt ${EXAMPLESDIR}/scripts

	for i in ${MAN3}; do \
		${INSTALL_MAN} ${WRKSRC}/docs/man/man3/$$i ${PREFIX}/man/man3 && \
		${GZIP_CMD} ${PREFIX}/man/man3/$$i; \
	done;

	for i in ${MAN6}; do \
		${INSTALL_MAN} ${WRKSRC}/docs/man/man6/$$i ${PREFIX}/man/man6 && \
		${GZIP_CMD} ${PREFIX}/man/man6/$$i; \
	done;

.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/disclaim ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/irit.hlp ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/docs/prog_man.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/user_man.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/user_man.html.index ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/general.inf ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/technion.inf ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/update.new ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/coding.std ${DOCSDIR}
.endif

post-install:
	@${ECHO_CMD} "*****************************************************************"
	@${ECHO_CMD} "In order to use IRIT you should set the following variables:"
	@${ECHO_CMD} "   setenv LD_LIBRARY_PATH ${LD_LIBRARY_PATH}:${PREFIX}/lib/irit"
	@${ECHO_CMD} "   setenv IRIT_PATH ${DATADIR}/"
	@${ECHO_CMD} "   setenv IRIT_DISPLAY \"x11drvs -s-\" - for X11 display drivers"
	@${ECHO_CMD} "or"
	@${ECHO_CMD} "   setenv IRIT_DISPLAY \"xmtdrvs -s-\" - for X11/Motif display drivers"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "and optionally:"
	@${ECHO_CMD} "   setenv IRIT_BIN_IPC 1"
	@${ECHO_CMD} "   setenv IRIT_SERVER_HOST `hostname`"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "For more information consult IRIT documentation"
	@${ECHO_CMD} "*****************************************************************"

.include <bsd.port.mk>
