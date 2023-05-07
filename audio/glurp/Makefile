PORTNAME=	glurp
PORTVERSION=	0.12.3
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@mark.reidel.info
COMMENT=	Nice and clean GTK+-2.x based graphical client for musicpd
WWW=		https://sourceforge.net/projects/glurp/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Unmaintained for years and depends on deprecated GTK2
EXPIRATION_DATE=2023-06-30

LIB_DEPENDS=	libmpd.so:audio/libmpd

GNU_CONFIGURE=	yes
USES=		gmake gnome pkgconfig
USE_GNOME=	gtk20 glib20 libglade2
MAKE_ARGS+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -export-dynamic" \

.include <bsd.port.mk>
