PORTNAME=	gbemol
PORTVERSION=	0.3.2
PORTREVISION=	16
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	tmh.public@gmail.com
COMMENT=	Graphical frontend for the Music Player Daemon
WWW=		http://gbemol.sourceforge.net/

DEPRECATED=	Unmaintained for years and depends on deprecated GTK2
EXPIRATION_DATE=2023-06-30

LIB_DEPENDS=	libmpd.so:audio/libmpd \
		libcurl.so:ftp/curl \
		libxml2.so:textproc/libxml2

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
USES=		gettext gmake gnome pkgconfig
USE_GNOME=	gtk20 intltool

post-patch:
	@${CHMOD} a+x ${WRKSRC}/install-sh

.include <bsd.port.mk>
