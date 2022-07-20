PORTNAME=	spice-protocol
PORTVERSION=	0.14.4
CATEGORIES=	devel
MASTER_SITES=	http://www.spice-space.org/download/releases/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Simple Protocol for Independent Computing Environments

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}

USES=		meson ninja pathfix pkgconfig python tar:xz

MESON_ARGS=	-Ddatadir=libdata
NO_ARCH=	yes

.include <bsd.port.mk>
