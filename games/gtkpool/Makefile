# New ports collection makefile for:	GTKPool
# Date created:				31 Jul 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtkpool
PORTVERSION=	0.5.0
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.seul.org/pub/gtkpool/ \
		http://www.sourcefiles.org/Games/Sports/Pool/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A 2D pool game using the GTK+ toolkit

USES=		perl5
USE_GNOME=	gtk20
USE_PERL5=	build
USE_GMAKE=	yes
USE_AUTOTOOLS=	aclocal automake autoheader autoconf
ACLOCAL_ARGS=	-I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	--add-missing

post-patch:
.for file in application.cpp options.cpp
	@${REINPLACE_CMD} -e 's|/usr/local/share/gtkpool|${DATADIR}|' \
		${WRKSRC}/gtkpool/${file}
.endfor

.include <bsd.port.mk>
