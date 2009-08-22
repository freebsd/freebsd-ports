# New ports collection makefile for:	py-ode
# Date created:		26 Jan 2007
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	ode
PORTVERSION=	1.2.0
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	SF/py${PORTNAME}/py${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyODE-${PORTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Python bindings for The Open Dynamics Engine

BUILD_DEPENDS=	${LOCALBASE}/lib/libode.a:${PORTSDIR}/devel/ode

USE_BZIP2=	yes

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	PyODE

OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

OPTIONS=	TRIMESH	"Trimesh support (sync with OPCODE opt of devel/ode)"	on

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/setup.py
.if defined(WITHOUT_TRIMESH)
	@${REINPLACE_CMD} -e '/TRIMESH_ENABLE/ s|True|False|' ${WRKSRC}/setup.py
.endif

.include <bsd.port.post.mk>
