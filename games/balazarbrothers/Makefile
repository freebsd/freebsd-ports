# New ports collection makefile for:	balazarbrothers
# Date created:		2006-05-07
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

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
USE_GETTEXT=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_TWISTED=	yes
USE_GL=		glew
USE_GMAKE=	yes

PYDISTUTILS_PKGNAME=	BalazarBrothers
PYDISTUTILS_EGGINFODIR=	${PREFIX}/share
DATADIR=	share/balazar_brothers

OPTIONS=	OPENAL	"Use openal sound system" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_OPENAL)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/_openal.so:${PORTSDIR}/audio/py-openal
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/setup.cfg

.include <bsd.port.post.mk>
