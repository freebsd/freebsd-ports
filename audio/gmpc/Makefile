# New ports collection makefile for:	traymp
# Date created:		Oct 09 2003
# Whom:			Mark Reidel <ports@mark.reidel.info>
#
# $FreeBSD$
#

PORTNAME=	traymp
PORTVERSION=	0.12
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	musicpd

MAINTAINER=	ports@mark.reidel.info
COMMENT=	Tray-aware GTK2 client for musicpd

GNU_CONFIGURE=	yes
USE_GNOME=	glib20 gtk20 libglade2
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \

CFLAGS+=	-I${PREFIX}/include

.include <bsd.port.pre.mk>

.ifdef(WITH_XOSD)
CONFIGURE_ARGS+=--enable-xosd
LIB_DEPENDS+=xosd.4:${PORTSDIR}/misc/xosd
.endif

pre-everything::
.ifndef(WITH_XOSD)
	@${ECHO} "You can build ${PKGNAME} with the following option:"
	@${ECHO}
	@${ECHO} "WITH_XOSD             Make use of on-screen-display"
	@${ECHO}
	@sleep 3
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
