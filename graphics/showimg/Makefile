# ex:ts=8
# Ports collection makefile for:	showimg
# Date created:			Mar 12, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	showimg
PORTVERSION=	0.9.3
CATEGORIES=	graphics
MASTER_SITES=	http://www.jalix.org/projects/showimg/download/${PORTVERSION}/

MAINTAINER=	shelton@granch.ru
COMMENT=	A picture viewer designed to run under KDE 3.x

USE_BZIP2=	yes
USE_KDEBASE_VER=	3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

MAN1=		showimg.1

OPTIONS=	DIGIKAM "Digikam plugins support" off

post-extract:
	@${TOUCH} ${WRKSRC}/config.h.in

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' -e "s,-lpthread,${PTHREAD_LIBS},g" \
		${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.pre.mk>

.if defined(WITH_DIGIKAM)
LIB_DEPENDS+=	digikam:${PORTSDIR}/graphics/digikam
CONFIGURE_ARGS+=	--enable-digiKam-plugin
.endif

.include <bsd.port.post.mk>
