# $FreeBSD$

PORTNAME=	evdev
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Bindings to the Linux input handling subsystem

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto

USES=		python
USE_PYTHON=	autoplist distutils
CPPFLAGS+=	-I${LOCALBASE}/include # v4l_compat

EVDEV_INCLUDES=	${LOCALBASE}/include

PYDISTUTILS_BUILD_TARGET=	build_ecodes
PYDISTUTILS_BUILDARGS+=		--evdev-headers ${EVDEV_INCLUDES}/linux/input.h:${EVDEV_INCLUDES}/linux/input-event-codes.h
PYDISTUTILS_BUILDARGS+=		build_ext
PYDISTUTILS_BUILDARGS+=		--include-dirs ${EVDEV_INCLUDES}

# Supply install target with evdev headers path
PYDISTUTILS_INSTALL_TARGET=	${PYDISTUTILS_BUILD_TARGET} \
				${PYDISTUTILS_BUILDARGS} install

post-install:
	${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		-name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
