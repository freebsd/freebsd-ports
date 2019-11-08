# Created by: Filippo Natali <filippo@widestore.net>
# $FreeBSD$

PORTNAME=	lgeneral
PORTVERSION=	1.3.2
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

USES=		gmake localbase sdl
USE_CSTD=	gnu89
USE_SDL=	sdl

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=		DOCS NLS SOUND
OPTIONS_DEFAULT=	SOUND
OPTIONS_SUB=		yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
SOUND_USE=		sdl=mixer
SOUND_CONFIGURE_OFF=	--disable-sound

post-patch:
.for i in flags terrain units
	@${REINPLACE_CMD} -e '/mkinstalldirs/s/$$(${i}dir)/$$(DESTDIR)&/' \
		${WRKSRC}/src/gfx/${i}/Makefile.in
.endfor

post-install:
	${SETENV} DISPLAY= \
		${STAGEDIR}${PREFIX}/bin/lgc-pg --separate-bridges \
		-s ${WRKDIR}/pg-data \
		-d ${STAGEDIR}${DATADIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
