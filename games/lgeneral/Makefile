# Created by: Filippo Natali <filippo@widestore.net>
# $FreeBSD$

PORTNAME=	lgeneral
PORTVERSION=	1.2.3
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME} \
		SF/${PORTNAME}/${PORTNAME}-data:data
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:DEFAULT \
		pg-data${EXTRACT_SUFX}:data

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A turn-based strategy engine inspired by Panzer General

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

MAN1=		lgc-pg.1
MAN6=		lgeneral.6

NO_STAGE=	yes
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

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not install on ia64, powerpc, or sparc64
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/icons|/pixmaps|' ${WRKSRC}/Makefile.in

post-install:
	@${PREFIX}/bin/lgc-pg -s ${WRKDIR}/pg-data -d ${DATADIR}
	@${FIND} ${DATADIR} | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	@${FIND} ${DATADIR} -type d | ${XARGS} ${CHMOD} a+rx
	@${FIND} ${DATADIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
