# New ports collection makefile for:	ktextdecode
# Date created:				08.05.2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$

PORTNAME=	ktextdecode
PORTVERSION=	3.0
PORTREVISION=	1
CATEGORIES=	converters kde
MASTER_SITES=	http://webua.net/zavolzhsky/download/
MASTER_SITE_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	brueffer@phoenix-systems.de
COMMENT=	The simple text conversion utility for KDE 3

USE_BZIP2=	yes
USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
