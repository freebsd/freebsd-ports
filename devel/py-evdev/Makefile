# $FreeBSD$

PORTNAME=	evdev
PORTVERSION=	0.5.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Bindings to the Linux input handling subsystem

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	v4l_compat>=1.0.20110603:multimedia/v4l_compat

USES=		python
USE_PYTHON=	autoplist distutils
CPPFLAGS+=	-I${LOCALBASE}/include # v4l_compat

post-patch:
	@${REINPLACE_CMD} -e '/header/s,/usr,${LOCALBASE},' \
		${WRKSRC}/${PYSETUP}

post-install:
	${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		-name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
