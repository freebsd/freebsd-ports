# ex:ts=8
# Ports collection makefile for:	teddy
# Date created:			Apr 13, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	teddy
PORTVERSION=	1.81.5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	Teddy-${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphics Library for 3D Scenes

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

USE_ZIP=	yes
USE_SDL=	sdl image mixer
USE_GNOME=	pkgconfig
USE_GL=		yes
GNU_CONFIGURE=	yes
CFLAGS+=	-I${X11BASE}/include ${PTHREAD_CFLAGS}
USE_GMAKE=	yes

PLIST_FILES=	lib/libTeddy.a libdata/pkgconfig/Teddy.pc

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
BROKEN=		"Does not compile on FreeBSD >= 5.x"
.endif

post-extract:
	@${CHMOD} +x ${WRKSRC}/configure

do-install:
	@${MKDIR} ${PREFIX}/include/Teddy
	cd ${WRKSRC} && ${TAR} cf - `${FIND} Teddy -name "*.h"` | \
		(cd ${PREFIX}/include ; ${TAR} xfBp -)
	@${FIND} ${PREFIX}/include/Teddy ! -type d | ${XARGS} ${CHMOD} 644
	@${FIND} ${PREFIX}/include/Teddy ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/include/Teddy -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
	${INSTALL_DATA} ${WRKSRC}/libTeddy.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/Teddy.pc ${PREFIX}/libdata/pkgconfig

.include <bsd.port.post.mk>
