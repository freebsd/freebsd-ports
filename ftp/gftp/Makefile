PORTNAME=	gftp
PORTVERSION=	2.7.0b
CATEGORIES=	ftp

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Free multithreaded GTK-based FTP and SFTP client

LICENSE=	GPLv2

USES=		autoreconf gnome gmake libtool pathfix pkgconfig ssl tar:bzip2
USE_GITHUB=	yes
GH_ACCOUNT=	masneyb
USE_GNOME=	glib20 gtk20

GNU_CONFIGURE=	yes

CFLAGS+=	-D_WANT_SEMUN

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_USE=		GNOME=intltool
NLS_CONFIGURE_OFF=	--disable-nls

post-patch:
	@${TOUCH} ${WRKSRC}/config.rpath

.include <bsd.port.mk>
