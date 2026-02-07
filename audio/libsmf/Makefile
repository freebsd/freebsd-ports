PORTNAME=	libsmf
PORTVERSION=	1.3
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Standard MIDI File format library
WWW=		https://github.com/nilsgey/libsmf

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnome libtool pkgconfig readline
USE_GNOME=	glib20
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

CONFLICTS_INSTALL=	jack-smf-utils # bin/smfsh

.include <bsd.port.mk>
