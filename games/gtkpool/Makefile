# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtkpool
PORTVERSION=	0.5.0
PORTREVISION=	13
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.seul.org/pub/gtkpool/ \
		http://www.sourcefiles.org/Games/Sports/Pool/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	2D pool game using the GTK+ toolkit

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf compiler:c++11-lang gmake perl5 pkgconfig
USE_CXXSTD=	c++11
USE_GNOME=	gtk20
USE_PERL5=	build
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/gtkpool \
		share/icons/gtkpool.png
PORTDATA=	*

post-patch:
.for file in application.cpp options.cpp
	@${REINPLACE_CMD} -e 's|/usr/local/share/gtkpool|${DATADIR}|' \
		${WRKSRC}/gtkpool/${file}
.endfor

.include <bsd.port.mk>
