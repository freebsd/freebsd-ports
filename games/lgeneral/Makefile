# Created by: Filippo Natali <filippo@widestore.net>
# $FreeBSD$

PORTNAME=	lgeneral
PORTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME} \
		SF/${PORTNAME}/${PORTNAME}-data:data
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		pg-data${EXTRACT_SUFX}:data

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Turn-based strategy engine inspired by Panzer General

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_powerpc=	does not install
BROKEN_sparc64=	does not install

USES=		gmake localbase
USE_CSTD=	gnu89
USE_SDL=	sdl
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=		DOCS NLS SOUND
OPTIONS_DEFAULT=	SOUND
OPTIONS_SUB=		yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
NLS_CONFIGURE_ENV_OFF=	am_cv_func_iconv=no
SOUND_USE=		sdl=mixer
SOUND_CONFIGURE_OFF=	--disable-sound

post-patch:
	@${REINPLACE_CMD} -e 's|/icons.*|/pixmaps|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|^CFLAGS=|#CFLAGS=|' ${WRKSRC}/configure

post-install:
.for i in flags terrain units
	@${MKDIR} ${STAGEDIR}${DATADIR}/gfx/${i}
.endfor
	${SETENV} DISPLAY= \
		${STAGEDIR}${PREFIX}/bin/lgc-pg --separate-bridges \
		-s ${WRKDIR}/pg-data \
		-d ${STAGEDIR}${DATADIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
