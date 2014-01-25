# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	dancingparticles
PORTVERSION=	0.6
PORTREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=	http://tardyp.free.fr/dancingparticles/
PKGNAMEPREFIX=	xmms-
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Makes particles dance with pretty neon colors

LIB_DEPENDS=	libt1.so:${PORTSDIR}/devel/t1lib \
		libxmms.so:${PORTSDIR}/multimedia/xmms

USE_GL=		glut
USE_GNOME=	gtk12
USE_SDL=	sdl

PLIST_FILES=	lib/xmms/Visualization/libdancingparticles2.so \
		%%DATADIR%%/dance.epic \
		%%DATADIR%%/dancingparticles.conf \
		%%DATADIR%%/font.pfb \
		%%DATADIR%%/xmms.epic
PLIST_DIRS=	%%DATADIR%%

post-patch:
	@${FIND} ${WRKSRC} -name "*.cc" -or -name "*.h" -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e \
		's|\(#include.*\)SDL/\(SDL.*\)|\1\2| ; \
		 s|/usr/local|${PREFIX}|'

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/xmms/Visualization
	(cd ${WRKSRC} && ${INSTALL_LIB} libdancingparticles2.so \
		${STAGEDIR}${PREFIX}/lib/xmms/Visualization)
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for i in dance.epic dancingparticles.conf font.pfb xmms.epic
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${DATADIR})
.endfor

.include <bsd.port.mk>
