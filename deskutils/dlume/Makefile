# New ports collection makefile for:	dlume
# Date created:				07 November 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dlume
PORTVERSION=	0.2.0
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://clay.ll.pl/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK2 address book

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget gtk20 libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/dlume share/gnome/pixmaps/dlume.png

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
