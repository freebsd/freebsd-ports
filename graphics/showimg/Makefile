# ex:ts=8
# Ports collection makefile for:	showimg
# Date created:			Mar 12, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	showimg
PORTVERSION=	0.8.20030305
CATEGORIES=	graphics
MASTER_SITES=	http://www.jalix.org/projects/showimg/download/0.8-Beta2/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.20/-20/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A picture viewer designed to run under KDE 3.x

LIB_DEPENDS=	png:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg

USE_KDEBASE_VER=3
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
CONFIGURE_ARGS+=	--program-prefix=''

#post-patch:
#	@${REINPLACE_CMD} -e "s,-lpthread,${PTHREAD_LIBS},g" ${WRKSRC}/showimg/Makefile.in

.include <bsd.port.mk>
