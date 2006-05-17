# New ports collection makefile for:	balazarbrothers
# Date created:		2006-05-07
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	balazarbrothers
PORTVERSION=	0.2
CATEGORIES=	games python
MASTER_SITES=	http://download.gna.org/soya/
DISTNAME=	BalazarBrother-${PORTVERSION}

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Balazar Brother is a free software 3D puzzle game

LIB_DEPENDS=	cal3d.11:${PORTSDIR}/graphics/cal3d \
		GLEW.1:${PORTSDIR}/graphics/glew \
		freetype.9:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/cerealizer/__init__.py:${PORTSDIR}/security/py-cerealizer \
		${PYTHON_SITELIBDIR}/soya/__init__.py:${PORTSDIR}/graphics/py-soya3d \
		${PYTHON_SITELIBDIR}/tofu/__init__.py:${PORTSDIR}/net/py-tofu \
		${PYTHON_SITELIBDIR}/ogg/__init__.py:${PORTSDIR}/audio/py-vorbis

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_TWISTED=	yes
USE_GL=		yes
USE_GMAKE=	yes

DATADIR=	share/balazar_brother

OPTIONS=	OPENAL	"Use openal sound system" on \
		SDL	"Use sdl sound system" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_OPENAL)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/_openal.so:${PORTSDIR}/audio/py-openal
.endif

.if defined(WITH_SDL)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/pysdl_mixer/sdl_mixer.so:${PORTSDIR}/audio/py-sdl_mixer
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/setup.cfg

.include <bsd.port.post.mk>
