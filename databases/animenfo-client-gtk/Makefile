# $FreeBSD$

PORTNAME=	animenfo
PORTVERSION=	20020819
PORTREVISION=	10
CATEGORIES=	databases
MASTER_SITES=	http://www.animenfo.com/extension/files/
PKGNAMESUFFIX=	-client-gui-gtk${PKGNAMESUFFIX2}
DISTNAME=	${PORTNAME}-client-gui-gtk
EXTRACT_SUFX=	.tgz

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	AnimeNfo client with GTK support

LICENSE=	GPLv2

USES=		pkgconfig gettext gmake
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CPPFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include
CFLAGS+=	${CPPFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_FILES=	bin/animenfo-client-gtk

.include <bsd.port.mk>
