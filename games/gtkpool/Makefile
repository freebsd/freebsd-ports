# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtkpool
PORTVERSION=	0.5.0
PORTREVISION=	10
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.seul.org/pub/gtkpool/ \
		http://www.sourcefiles.org/Games/Sports/Pool/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	2D pool game using the GTK+ toolkit

USES=		autoreconf gmake perl5 pkgconfig
USE_GNOME=	gtk20
USE_PERL5=	build
GNU_CONFIGURE=	yes
USE_GCC=	any

PLIST_FILES=	bin/gtkpool \
		share/icons/gtkpool.png
PORTDATA=	*

post-patch:
.for file in application.cpp options.cpp
	@${REINPLACE_CMD} -e 's|/usr/local/share/gtkpool|${DATADIR}|' \
		${WRKSRC}/gtkpool/${file}
.endfor

.include <bsd.port.mk>
