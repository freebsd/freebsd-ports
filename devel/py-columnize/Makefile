# $FreeBSD$

PORTNAME=	columnize
PORTVERSION=	0.3.9
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jpaetzel@FreeBSD.org
COMMENT=	Format a simple (i.e. not nested) list into aligned columns

LICENSE=	MIT

MY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=1.0:devel/py-nose

BUILD_DEPENDS=	${MY_DEPENDS}
RUN_DEPENDS=	${MY_DEPENDS}

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.pre.mk>

.if ${PYTHON_MAJOR_VER} == "3"
EXTRA_PATCHES=      ${FILESDIR}/extra-patch-____pkginfo____.py
.else
MY_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}backports.shutil_get_terminal_size=1.0:devel/py-backports.shutil_get_terminal_size
.endif

.include <bsd.port.post.mk>
