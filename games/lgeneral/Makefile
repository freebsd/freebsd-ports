# Created by: Filippo Natali <filippo@widestore.net>
# $FreeBSD$

PORTNAME=	lgeneral
PORTVERSION=	1.2.3
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME} \
		SF/${PORTNAME}/${PORTNAME}-data:data
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:DEFAULT \
		pg-data${EXTRACT_SUFX}:data

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Turn-based strategy engine inspired by Panzer General

LICENSE=	GPLv2

CONFLICTS=	lgeneral-data-[0-9]*

OPTIONS_DEFINE=	SOUND NLS DOCS
OPTIONS_DEFAULT=	SOUND
SOUND_DESC=	Enable sound support

USE_SDL=	sdl
USES=		gmake
GNU_CONFIGURE=	yes
USE_CSTD=	gnu89

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSOUND}
USE_SDL+=	mixer
.else
CONFIGURE_ARGS+=--disable-sound
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ENV+=	am_cv_func_iconv=no
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not install on ia64, powerpc, or sparc64
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/icons|/pixmaps|' ${WRKSRC}/Makefile.in

post-install:
	${STAGEDIR}${PREFIX}/bin/lgc-pg -s ${WRKDIR}/pg-data -d ${STAGEDIR}${DATADIR}
	@${FIND} ${STAGEDIR}${DATADIR} -type d | ${XARGS} ${CHMOD} a+rx
	@${FIND} ${STAGEDIR}${DATADIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.* ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
