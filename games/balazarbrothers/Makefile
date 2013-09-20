# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	balazarbrothers
PORTVERSION=	0.3.1
PORTREVISION=	5
CATEGORIES=	games python
MASTER_SITES=	http://download.gna.org/${PORTNAME:S/brothers//}/
DISTNAME=	${PORTNAME:S/b/B/g}-${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Balazar Brother is a free software 3D puzzle game

LIB_DEPENDS=	cal3d.12:${PORTSDIR}/graphics/cal3d \
		freetype.9:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/cerealizer/__init__.py:${PORTSDIR}/security/py-cerealizer \
		${PYTHON_SITELIBDIR}/soya/__init__.py:${PORTSDIR}/graphics/py-soya3d \
		${PYTHON_SITELIBDIR}/tofu/__init__.py:${PORTSDIR}/net/py-tofu \
		${PYTHON_SITELIBDIR}/ogg/__init__.py:${PORTSDIR}/audio/py-vorbis

USE_BZIP2=	yes
USES=		gettext
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_TWISTED=	yes
USE_GL=		glew
USE_GMAKE=	yes

PYDISTUTILS_PKGNAME=	BalazarBrothers
PYDISTUTILS_EGGINFODIR=	${PREFIX}/share
DATADIR=	share/balazar_brothers

OPTIONS_DEFINE=	OPENAL
OPTIONS_DEFAULT=	OPENAL

NO_STAGE=	yes
.include <bsd.port.options.mk>
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MOPENAL}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}openal>=0:${PORTSDIR}/audio/py-openal
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/setup.cfg

.include <bsd.port.post.mk>
