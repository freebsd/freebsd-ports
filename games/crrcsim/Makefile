PORTNAME=	crrcsim
PORTVERSION=	0.9.13
PORTREVISION=	4
CATEGORIES=	games education
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Model-airplane flight simulation program
WWW=		https://sourceforge.net/projects/crrcsim/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:x11-toolkits/plib
LIB_DEPENDS=	libportaudio.so:audio/portaudio

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USES=		gettext gl gmake jpeg localbase sdl xorg
USE_SDL=	sdl
USE_GL=		gl glu
USE_XORG=	x11

LIBS+=		-lintl

PORTDOCS=	*
PORTDATA=	*

DESKTOP_ENTRIES="CRRCsim" \
		"" \
		"${DATADIR}/icons/crrcsim.png" \
		"crrcsim" \
		"Game;Simulation;" \
		""

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/portaudio/ s|==|=|' ${WRKSRC}/configure

.include <bsd.port.mk>
