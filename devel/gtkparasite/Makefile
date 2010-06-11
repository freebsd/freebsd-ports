# New ports collection makefile for:	gtkparasite
# Date created:		2009-02-19
# Whom:			Ashish Shukla <wahjava@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	gtkparasite
PORTVERSION=	20090819
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	pav

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	GTK+ UI debugging tool

USE_PYTHON=	2.5+
USE_GNOME=	gtk20 pygtk2
WRKSRC=		${WRKDIR}/chipx86-gtkparasite-a3d862d4a91ea27222e4273a6797f3e47efe6e83
GNU_CONFIGURE=	yes
PORTDOCS=	USAGE
PLIST_FILES=	lib/gtk-2.0/modules/libgtkparasite.a \
		lib/gtk-2.0/modules/libgtkparasite.la \
		lib/gtk-2.0/modules/libgtkparasite.so
USE_AUTOTOOLS=	autoconf:262 automake:110 libtool:22

pre-configure:
	cd ${WRKSRC} && ${REINPLACE_CMD} -e '/.\/configure/d' ./autogen.sh \
		&& ./autogen.sh

post-install:
.ifndef NOPORTDOCS
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/USAGE ${DOCSDIR}
.endif

.include <bsd.port.mk>
