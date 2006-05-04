# New ports collection makefile for:	nautilus-actions
# Date created:		2005-08-31
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nautilus-actions
PORTVERSION=	0.7.1
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	ftp://ftp2.grumz.net/grumz/

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Extension for Nautilus to configure programs to launch on files

USE_GNOME=	nautilus2 intlhack pygtk2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_PYTHON=	yes
USE_X_PREFIX=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-nautilus-extdir=${X11BASE}/lib/nautilus/extensions-1.0

post-patch:
	@${REINPLACE_CMD} -e 's|@datadir@datadir@/pixmaps|${DATADIR}/nact|' \
		${WRKSRC}/nact/nact.desktop.in.in

.include <bsd.port.mk>
