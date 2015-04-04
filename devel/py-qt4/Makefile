# Created by: Dima Panov <fluffy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qt4
PORTVERSION=	${PYQT4_VERSION}
CATEGORIES=	devel python
MASTER_SITES=	# empty
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	# none
EXTRACT_ONLY=	# empty

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt 4 toolkit (meta port)

USES=		python

NO_BUILD=	yes
NO_INSTALL=	yes
NO_MTREE=	yes

OPTIONS_DEFINE=	ALL ${PYQT4_COMPONENTS}
OPTIONS_DEFAULT=	ALL
ALL_DESC=	All PyQt4 components

.include "${.CURDIR}/bsd.pyqt.mk"

.for component in ${PYQT4_COMPONENTS}
${component}_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt4-${component}>=0:${PORTSDIR}/${${component}_PORT}
ALL_RUN_DEPENDS+=		${${component}_RUN_DEPENDS}
.endfor

.include <bsd.port.mk>
