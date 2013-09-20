# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nil
DISTVERSION=	20050603-1400
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/NiL%20%28old%29/${PORTNAME}-20050603
DISTNAME=	${PORTNAME}-cvs-backup-${DISTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A multiplayer game like Quake in 2D or Worms done right

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_SDL=	image mixer sdl ttf
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=OPTIMIZED_CFLAGS

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${ARCH} == "ia64"
BROKEN=		does not link on ${ARCH}
.endif

post-patch:
	@${FIND} ${WRKSRC} -type f -name configure -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e \
		's|[[:<:]]make[[:>:]]|${GMAKE}|; \
		 s|sdl-config|${SDL_CONFIG}|'
	@${REINPLACE_CMD} -e 's|\.\./data|${DATADIR}|' \
		${WRKSRC}/src/common/configuration/configuration.cpp
.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
	@${REINPLACE_CMD} -e 's|\(--subcall\)|\1 --enable-optimize|' \
		${WRKSRC}/configure
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/data/* ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/HOWTO ${DOCSDIR}
.endif

.include <bsd.port.mk>
