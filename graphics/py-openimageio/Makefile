PORTREVISION=	2
CATEGORIES=	graphics multimedia python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

COMMENT=	OpenImageIO python bindings

BROKEN=		broken due to OpenVDB using undefined STL function std::tuple_size_v, see https://github.com/AcademySoftwareFoundation/openvdb/issues/1814

MASTERDIR=	${.CURDIR}/../openimageio
OPTIONS_EXCLUDE=${OPTIONS_DEFINE}

.include "${MASTERDIR}/Makefile"
