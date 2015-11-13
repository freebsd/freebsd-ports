# $FreeBSD$

PORTNAME=	capstone
PORTVERSION=	2.1.2
CATEGORIES=	devel

MAINTAINER=	oliver.pntr@gmail.com
COMMENT=	Multi-platform, multi-architecture disassembly framework

LICENSE=	BSD3CLAUSE

USES=		gmake
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	aquynh

MAKE_ENV+=	INSTALL_LIB="${INSTALL_LIB}" \
		INSTALL_DATA="${INSTALL_DATA}"

post-build:
	# The pkgconfig file is generated and points to stagedir
	${REINPLACE_CMD} -e '/libdir/s|\(libdir=\)\(.*\)\(devel/capstone/work/stage\)|\1|g' ${WRKSRC}/capstone.pc

.include <bsd.port.mk>
