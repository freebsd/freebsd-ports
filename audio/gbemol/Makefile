# Created by: Thomas M. Hermann <tmh.public@gmail.com>
# $FreeBSD$

PORTNAME=	gbemol
PORTVERSION=	0.3.2
PORTREVISION=	12
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	tmh.public@gmail.com
COMMENT=	Graphical frontend for the Music Player Daemon

LIB_DEPENDS=	libmpd.so:audio/libmpd \
		libcurl.so:ftp/curl \
		libxml2.so:textproc/libxml2

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
USES=		gettext gmake pkgconfig
USE_GNOME=	gtk20 intltool

post-patch:
	@${CHMOD} a+x ${WRKSRC}/install-sh

.include <bsd.port.mk>
