# New ports collection makefile for:	dlume
# Date created:				07 November 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dlume
PORTVERSION=	0.1.8
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://clay.ll.pl/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK2 address book

USE_X_PREFIX=	yes
USE_GNOME=	gnometarget gtk20 libxml2
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/dlume

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
