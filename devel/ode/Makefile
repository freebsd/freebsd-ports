PORTNAME=	ode
DISTVERSION=	0.16.6
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	https://bitbucket.org/odedevs/${PORTNAME}/downloads/

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Articulated rigid body dynamics library
WWW=		https://www.ode.org/

LICENSE=	LGPL21 BSD3CLAUSE
LICENSE_COMB=	dual

USES=		cmake:testing

FLAVORS=	single double
FLAVOR?=	${FLAVORS:[1]}

single_CONFLICTS=	odoo-double
double_CONFLICTS=	odoo-single

.if ${FLAVOR} == double
PKGNAMESUFFIX=	-double
CMAKE_ON=	ODE_DOUBLE_PRECISION
.else
PKGNAMESUFFIX=	-single
CMAKE_OFF=	ODE_DOUBLE_PRECISION
.endif

CMAKE_OFF=	ODE_WITH_TESTS
CMAKE_TESTING_ON=	ODE_WITH_TESTS

CXXFLAGS+=	-Wno-c++11-narrowing

OPTIONS_DEFINE=		DEMOS GIMPACT LIBCCD OU TRIMESH # it looks like TRIMESH isn't defined but is needed because ODE_NO_TRIMESH is never defined otherwise
OPTIONS_DEFAULT=	TRIMESH

DEMOS_DESC=		Build demos (not installed)
DEMOS_CMAKE_BOOL=	ODE_WITH_DEMOS
DEMOS_USES=		gl localbase pkgconfig
DEMOS_USE=		GL=gl,glu

GIMPACT_DESC=		Enable gimpact instead of opcode support
GIMPACT_CMAKE_BOOL=	ODE_WITH_GIMPACT
GIMPACT_PREVENTS=	TRIMESH

LIBCCD_DESC=		Use libccd for handling some collision tests absent in ODE
LIBCCD_CMAKE_BOOL=	ODE_WITH_LIBCCD ODE_WITH_LIBCCD_SYSTEM
LIBCCD_CXXFLAGS=	-I${WRKSRC}/libccd/src/custom
LIBCCD_LIB_DEPENDS=	libccd.so:math/libccd

OU_DESC=		Enable Thread-local storage (Experimental)
OU_CMAKE_BOOL=		ODE_WITH_OU

TRIMESH_DESC=		Build with trimesh
TRIMESH_CMAKE_OFF=	-DODE_NO_TRIMESH=ON

.include <bsd.port.mk>
