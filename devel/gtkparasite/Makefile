# Created by: Ashish Shukla <wahjava@gmail.com>
# $FreeBSD$

PORTNAME=	gtkparasite
PORTVERSION=	20090819
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	pav

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	GTK+ UI debugging tool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		pkgconfig
USE_PYTHON=	yes
USE_GNOME=	gtk20 pygtk2
WRKSRC=		${WRKDIR}/chipx86-gtkparasite-a3d862d4a91ea27222e4273a6797f3e47efe6e83
GNU_CONFIGURE=	yes
PORTDOCS=	USAGE
PLIST_FILES=	lib/gtk-2.0/modules/libgtkparasite.a \
		lib/gtk-2.0/modules/libgtkparasite.la \
		lib/gtk-2.0/modules/libgtkparasite.so
USE_AUTOTOOLS=	autoconf automake libtool

OPTIONS_DEFINE=	DOCS

pre-configure:
	cd ${WRKSRC} && ${REINPLACE_CMD} -e '/.\/configure/d' ./autogen.sh \
		&& ./autogen.sh

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/USAGE ${STAGEDIR}/${DOCSDIR}
.endif

.include <bsd.port.mk>
