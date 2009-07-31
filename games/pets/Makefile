# New ports collection makefile for:	pets
# Date created:		2006-07-28
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	pets
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://www.loria.fr/~rougier/pub/Software/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Funny pets to follow your mouse pointer

WRKSRC=		${WRKDIR}/pet-${PORTVERSION}

USE_GNOME=	gtk20 pkgconfig

SUB_FILES=	pkg-message

GTK_CFLAGS=	pkg-config gtk+-2.0 gdk-pixbuf-xlib-2.0 --cflags
GTK_LDFLAGS=	pkg-config gtk+-2.0 gdk-pixbuf-xlib-2.0 --libs

do-build:
	(cd ${WRKSRC} && ${CXX} ${CFLAGS} `${GTK_CFLAGS}` -c pet.cc)
	(cd ${WRKSRC} && ${CXX} ${LDFLAGS} `${GTK_LDFLAGS}` pet.o -o pets)

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/pets ${PREFIX}/bin
	@(cd ${WRKSRC}/data; ${PAX} -rw -p e -l . ${DATADIR})
	@${FIND} ${DATADIR}/ -type f -name "*~" -delete
	@${FIND} ${DATADIR}/ -type f -exec ${CHMOD} ${SHAREMODE} {} \;
	@${FIND} ${DATADIR}/ -exec ${CHOWN} ${SHAREOWN} {} \;

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
