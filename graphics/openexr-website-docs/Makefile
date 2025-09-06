PORTNAME=	openexr-website-docs
PORTVERSION=	3.4.0
PORTREVISION=	0
MASTER_SITES=	https://github.com/AcademySoftwareFoundation/openexr/releases/download/v${PORTVERSION}/:DEFAULT \
		https://raw.githubusercontent.com/AcademySoftwareFoundation/openexr-images/main/:website \
		LOCAL/mandree/openexr/:DEFAULT \
		LOCAL/mandree/openexr/:website

DISTFILES=	${EXTRACT_ONLY}:DEFAULT # defined in ../openexr/Makefile
# cat $(make -V WRKSRC)/website/test_images.txt  | grep -v ^$ | sed 's,^,DISTFILES+=\t,'
DISTFILES+=	TestImages/README.rst:website
DISTFILES+=	TestImages/AllHalfValues.exr:website
DISTFILES+=	TestImages/BrightRings.exr:website
DISTFILES+=	TestImages/BrightRingsNanInf.exr:website
DISTFILES+=	TestImages/GammaChart.exr:website
DISTFILES+=	TestImages/GrayRampsDiagonal.exr:website
DISTFILES+=	TestImages/GrayRampsHorizontal.exr:website
DISTFILES+=	TestImages/RgbRampsDiagonal.exr:website
DISTFILES+=	TestImages/SquaresSwirls.exr:website
DISTFILES+=	TestImages/WideColorGamut.exr:website
DISTFILES+=	TestImages/WideFloatRange.exr:website
DISTFILES+=	ScanLines/README.rst:website
DISTFILES+=	ScanLines/Blobbies.exr:website
DISTFILES+=	ScanLines/CandleGlass.exr:website
DISTFILES+=	ScanLines/Cannon.exr:website
DISTFILES+=	ScanLines/Carrots.exr:website
DISTFILES+=	ScanLines/Desk.exr:website
DISTFILES+=	ScanLines/MtTamWest.exr:website
DISTFILES+=	ScanLines/PrismsLenses.exr:website
DISTFILES+=	ScanLines/StillLife.exr:website
DISTFILES+=	ScanLines/Tree.exr:website
DISTFILES+=	Tiles/README.rst:website
DISTFILES+=	Tiles/GoldenGate.exr:website
DISTFILES+=	Tiles/Ocean.exr:website
DISTFILES+=	Tiles/Spirals.exr:website
DISTFILES+=	Chromaticities/README.rst:website
DISTFILES+=	Chromaticities/Rec709.exr:website
DISTFILES+=	Chromaticities/Rec709_YC.exr:website
DISTFILES+=	Chromaticities/XYZ.exr:website
DISTFILES+=	Chromaticities/XYZ_YC.exr:website
DISTFILES+=	LuminanceChroma/README.rst:website
DISTFILES+=	LuminanceChroma/CrissyField.exr:website
DISTFILES+=	LuminanceChroma/Flowers.exr:website
DISTFILES+=	LuminanceChroma/Garden.exr:website
DISTFILES+=	LuminanceChroma/MtTamNorth.exr:website
DISTFILES+=	LuminanceChroma/StarField.exr:website
DISTFILES+=	DisplayWindow/README.rst:website
DISTFILES+=	DisplayWindow/t01.exr:website
DISTFILES+=	DisplayWindow/t02.exr:website
DISTFILES+=	DisplayWindow/t03.exr:website
DISTFILES+=	DisplayWindow/t04.exr:website
DISTFILES+=	DisplayWindow/t05.exr:website
DISTFILES+=	DisplayWindow/t06.exr:website
DISTFILES+=	DisplayWindow/t07.exr:website
DISTFILES+=	DisplayWindow/t08.exr:website
DISTFILES+=	DisplayWindow/t09.exr:website
DISTFILES+=	DisplayWindow/t10.exr:website
DISTFILES+=	DisplayWindow/t11.exr:website
DISTFILES+=	DisplayWindow/t12.exr:website
DISTFILES+=	DisplayWindow/t13.exr:website
DISTFILES+=	DisplayWindow/t14.exr:website
DISTFILES+=	DisplayWindow/t15.exr:website
DISTFILES+=	DisplayWindow/t16.exr:website
DISTFILES+=	Beachball/README.rst:website
DISTFILES+=	Beachball/multipart.0001.exr:website
DISTFILES+=	Beachball/multipart.0002.exr:website
DISTFILES+=	Beachball/multipart.0003.exr:website
DISTFILES+=	Beachball/multipart.0004.exr:website
DISTFILES+=	Beachball/multipart.0005.exr:website
DISTFILES+=	Beachball/multipart.0006.exr:website
DISTFILES+=	Beachball/multipart.0007.exr:website
DISTFILES+=	Beachball/multipart.0008.exr:website
DISTFILES+=	Beachball/singlepart.0001.exr:website
DISTFILES+=	Beachball/singlepart.0002.exr:website
DISTFILES+=	Beachball/singlepart.0003.exr:website
DISTFILES+=	Beachball/singlepart.0004.exr:website
DISTFILES+=	Beachball/singlepart.0005.exr:website
DISTFILES+=	Beachball/singlepart.0006.exr:website
DISTFILES+=	Beachball/singlepart.0007.exr:website
DISTFILES+=	Beachball/singlepart.0008.exr:website
DISTFILES+=	MultiView/README.rst:website
DISTFILES+=	MultiView/Adjuster.exr:website
DISTFILES+=	MultiView/Balls.exr:website
DISTFILES+=	MultiView/Fog.exr:website
DISTFILES+=	MultiView/Impact.exr:website
DISTFILES+=	MultiView/LosPadres.exr:website
DISTFILES+=	MultiResolution/README.rst:website
DISTFILES+=	MultiResolution/Bonita.exr:website
DISTFILES+=	MultiResolution/ColorCodedLevels.exr:website
DISTFILES+=	MultiResolution/Kapaa.exr:website
DISTFILES+=	MultiResolution/KernerEnvCube.exr:website
DISTFILES+=	MultiResolution/KernerEnvLatLong.exr:website
DISTFILES+=	MultiResolution/MirrorPattern.exr:website
DISTFILES+=	MultiResolution/OrientationCube.exr:website
DISTFILES+=	MultiResolution/OrientationLatLong.exr:website
DISTFILES+=	MultiResolution/PeriodicPattern.exr:website
DISTFILES+=	MultiResolution/StageEnvCube.exr:website
DISTFILES+=	MultiResolution/StageEnvLatLong.exr:website
DISTFILES+=	MultiResolution/WavyLinesCube.exr:website
DISTFILES+=	MultiResolution/WavyLinesLatLong.exr:website
DISTFILES+=	MultiResolution/WavyLinesSphere.exr:website
DISTFILES+=	v2/Stereo/README.rst:website
DISTFILES+=	v2/Stereo/Balls.exr:website
DISTFILES+=	v2/Stereo/Ground.exr:website
DISTFILES+=	v2/Stereo/Leaves.exr:website
DISTFILES+=	v2/Stereo/Trunks.exr:website
DISTFILES+=	v2/Stereo/composited.exr:website
DISTFILES+=	v2/LeftView/README.rst:website
DISTFILES+=	v2/LeftView/Balls.exr:website
DISTFILES+=	v2/LeftView/Ground.exr:website
DISTFILES+=	v2/LeftView/Leaves.exr:website
DISTFILES+=	v2/LeftView/Trunks.exr:website
DISTFILES+=	v2/LowResLeftView/README.rst:website
DISTFILES+=	v2/LowResLeftView/Balls.exr:website
DISTFILES+=	v2/LowResLeftView/Ground.exr:website
DISTFILES+=	v2/LowResLeftView/Leaves.exr:website
DISTFILES+=	v2/LowResLeftView/Trunks.exr:website
DISTFILES+=	v2/LowResLeftView/composited.exr:website

BUILD_DEPENDS=	breathe-apidoc:devel/py-breathe \
		${PYTHON_PKGNAMEPREFIX}sphinx_press_theme>=0:textproc/py-sphinx_press_theme \
		convert:graphics/ImageMagick7 \
		openexr>=0:graphics/openexr
LIB_DEPENDS=
USES=		cmake python:build
CMAKE_ARGS=	-DPython_EXECUTABLE:STRING=${PYTHON_CMD} -DBUILD_WEBSITE=on -DSPHINX_OPTS= -Wno-dev
MAKE_ENV=	FREEBSD_DIST=${DISTDIR}/${DIST_SUBDIR}
ALL_TARGET=	website

MASTERDIR=	${.CURDIR}/../../graphics/openexr
PATCHDIR=	${.CURDIR}/files
PKGDIR=		${.CURDIR}
WRKSRC=		${WRKDIR}/openexr-${PORTVERSION}

BINARY_ALIAS=	python3=${PYTHON_CMD}

NO_ARCH=	yes

DISTINFO_FILE=	${.CURDIR}/distinfo

OPTIONS_EXCLUDE=EXAMPLES
OPTIONS_SLAVE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	( cd ${BUILD_WRKSRC}/website/sphinx && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} )
	${RM} -r ${STAGEDIR}${DOCSDIR}/.??* ${STAGEDIR}${DOCSDIR}/../OpenEXR/sphinx

.include "${MASTERDIR}/Makefile"
