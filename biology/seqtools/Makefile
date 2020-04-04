# $FreeBSD$

PORTNAME=	seqtools
PORTVERSION=	4.44.1
PORTREVISION=	4
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.sanger.ac.uk/pub4/resources/software/seqtools/PRODUCTION/

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Tools for visualising sequence alignments

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2020-05-05

LICENSE=	GPLv3

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libsqlite3.so:databases/sqlite3 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		compiler:c++14-lang gettext gnome libtool pkgconfig xorg
GNU_CONFIGURE=	yes
USE_GNOME=	cairo gdkpixbuf2 gtk20
USE_XORG=	x11
CFLAGS+=	-I${LOCALBASE}/include
LLD_UNSAFE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib -lexecinfo -lcurl -lsqlite3 -lm
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
