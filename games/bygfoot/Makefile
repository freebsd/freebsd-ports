# Created by: Pav Lucistnik <pav@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bygfoot
PORTVERSION=	2.2.1
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Football (soccer) management game

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

# needed to save/load games
RUN_DEPENDS=	zip:archivers/zip

USES=		gettext pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lm

.include <bsd.port.mk>
