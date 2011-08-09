# New ports collection makefile for:   lgeneral
# Date created:                27 Aug 2002
# Whom:                        Filippo Natali <filippo@widestore.net>
#
# $FreeBSD$
#

PORTNAME=	lgeneral
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME} \
		SF/${PORTNAME}/${PORTNAME}-data:data
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:DEFAULT \
		pg-data${EXTRACT_SUFX}:data

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A turn-based strategy engine inspired by Panzer General

CONFLICTS=	lgeneral-data-[0-9]*

USE_SDL=	sdl
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}"

MAN1=		lgc-pg.1
MAN6=		lgeneral.6

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.if defined(WITHOUT_SOUND)
CONFIGURE_ARGS+=--disable-sound
.else
USE_SDL+=	mixer
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ENV+=	am_cv_func_iconv=no
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-g -Wall|-Wall| ; \
		 s|/games||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/icons|/pixmaps|' ${WRKSRC}/Makefile.in

post-install:
	@${PREFIX}/bin/lgc-pg -s ${WRKDIR}/pg-data -d ${DATADIR}
	@${FIND} ${DATADIR} | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	@${FIND} ${DATADIR} -type d | ${XARGS} ${CHMOD} a+rx
	@${FIND} ${DATADIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.* ${DOCSDIR}
.endif

.include <bsd.port.mk>
