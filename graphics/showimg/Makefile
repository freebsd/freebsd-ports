# ex:ts=8
# Ports collection makefile for:	showimg
# Date created:			Mar 12, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	showimg
PORTVERSION=	0.7
CATEGORIES=	graphics
MASTER_SITES=	http://www.jalix.org/projects/showimg/download/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	png:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg

USE_QT_VER=	2
USE_KDEBASE_VER=	2
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s,-lpthread,${PTHREAD_LIBS},g" ${WRKSRC}/showimg/Makefile.in

.include <bsd.port.mk>
