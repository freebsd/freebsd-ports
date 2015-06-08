# Created by: Filippo Natali <filippo@widestore.net>
# $FreeBSD$

PORTNAME=	lgeneral
PORTVERSION=	1.2.6
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME} \
		SF/${PORTNAME}/${PORTNAME}-data:data
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:DEFAULT \
		pg-data${EXTRACT_SUFX}:data

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Turn-based strategy engine inspired by Panzer General

LICENSE=	GPLv2

USES=		gmake
USE_CSTD=	gnu89
USE_SDL=	sdl
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

BROKEN_powerpc=	Does not install on ${ARCH}
BROKEN_sparc64=	Does not install on ${ARCH}

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

post-install:
.for i in flags terrain units
	@${MKDIR} ${STAGEDIR}${DATADIR}/gfx/${i}
.endfor
	(${STAGEDIR}${PREFIX}/bin/lgc-pg -s ${WRKDIR}/pg-data \
		-d ${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} README.* ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
