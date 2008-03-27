# New ports collection makefile for:   xarchiver
# Date created:        27 Mart 2008
# Whom:            Andreev Maxim
#
# $FreeBSD$
#

PORTNAME=	xarchiver
PORTVERSION=	0.4.6
CATEGORIES=	archivers
MASTER_SITES=	SF

MAINTAINER=	andreevmaxim@gmail.com
COMMENT=	Desktop-agnostic GTK+2 frontend to various archiving tools

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 gtk20 intltool pkgconfig
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

post-patch:
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e 's|doc||g' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
