# New ports collection makefile for:	nil
# Date created:				28 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nil
DISTVERSION=	20050603-1400
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-cvs-backup-${DISTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A multiplayer game like Quake in 2D or Worms done right

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_SDL=	image mixer sdl ttf
GNU_CONFIGURE=	yes

OPTIONS=	OPTIMIZED_CFLAGS "Enable compilation optimizations" on

.include <bsd.port.pre.mk>

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
.if !defined(WITHOUT_OPTIMIZED_CFLAGS)
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

.include <bsd.port.post.mk>
