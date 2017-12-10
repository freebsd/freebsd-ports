# Created by: Ashish Shukla <wahjava@gmail.com>
# $FreeBSD$

PORTNAME=	gtkparasite
PORTVERSION=	20090819
PORTREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	LOCAL/pav

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	GTK+ UI debugging tool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip
USES=		autoreconf libtool pkgconfig python:2.7
USE_GNOME=	gtk20 pygtk2
WRKSRC=		${WRKDIR}/chipx86-gtkparasite-a3d862d4a91ea27222e4273a6797f3e47efe6e83
PORTDOCS=	USAGE
PLIST_FILES=	lib/gtk-2.0/modules/libgtkparasite.so

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/USAGE ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
