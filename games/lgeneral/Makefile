PORTNAME=	lgeneral
DISTVERSION=	1.4.4
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME} \
		SF/${PORTNAME}/${PORTNAME}-data:data
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		pg-data${EXTRACT_SUFX}:data

MAINTAINER=	cmanv@duck.com
COMMENT=	Turn-based strategy engine inspired by Panzer General
WWW=		http://lgames.sourceforge.net/index.php?project=LGeneral

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_powerpc=	does not install

USES=		gmake localbase sdl
USE_CSTD=	gnu89
USE_SDL=	sdl

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

OPTIONS_DEFINE=		DOCS NLS SOUND
OPTIONS_DEFAULT=	SOUND
OPTIONS_SUB=		yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
SOUND_USE=		SDL=mixer
SOUND_CONFIGURE_OFF=	--disable-sound

post-install:
	${SETENV} DISPLAY= \
		${STAGEDIR}${PREFIX}/bin/lgc-pg --separate-bridges \
		-s ${WRKDIR}/pg-data \
		-d ${STAGEDIR}${DATADIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
