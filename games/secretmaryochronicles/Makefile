# New ports collection makefile for:	secretmaryochronicles
# Date created:		31 Jan 2008
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	secretmaryochronicles
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	smclone
DISTNAME=	smc-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Secret Maryo Chronicles two-dimensional platform game

LIB_DEPENDS=	CEGUIBase.2:${PORTSDIR}/graphics/cegui \
		boost_filesystem.4:${PORTSDIR}/devel/boost \
		png.5:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_SDL=	sdl image mixer ttf
USE_GL=		gl glu
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include"

DATADIR=	${PREFIX}/share/smc

.if !defined(NOPORTDOCS)
PORTDOCS=	controls.html style.css

post-install:
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
