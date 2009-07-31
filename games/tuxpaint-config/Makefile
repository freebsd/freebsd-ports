# New ports collection makefile for:	tuxpaint-config
# Date created:				28 Nov 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	tuxpaint-config
PORTVERSION=	0.0.11
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tuxpaint

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Graphical tool to change TuxPaint settings

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk \
		paper.2:${PORTSDIR}/print/libpaper
RUN_DEPENDS=	tuxpaint:${PORTSDIR}/games/tuxpaint

USE_GMAKE=	yes
USE_GETTEXT=	yes

MAN1=		tuxpaint-config.1
MANCOMPRESSED=	yes

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|install-doc\([^:]\)|\1|' ${WRKSRC}/${MAKEFILE}
.endif

.include <bsd.port.mk>
