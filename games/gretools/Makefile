# New ports collection makefile for:	gretools
# Date created:				2004 January 15
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gretools
PORTVERSION=	1.2.2
CATEGORIES=	games
MASTER_SITES=	http://theory.cs.iitm.ernet.in/~arvindn/gretools/${PORTVERSION:R}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK2 vocabulary builder

USE_X_PREFIX=	yes
USE_PYTHON=	yes
USE_GNOME=	gnomehack gnometarget gnomeprefix pygnome2
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/bin/python|${PYTHON_CMD}|" \
		${WRKSRC}/${PORTNAME}.in

.include <bsd.port.mk>
