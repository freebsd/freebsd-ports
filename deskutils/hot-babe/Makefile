# New ports collection makefile for:	hot-babe
# Date created:		2004-11-06
# Whom:			Roman Bogorodskiy <bogorodskiy@inbox.ru>
#
# $FreeBSD$
#

PORTNAME=	hot-babe
PORTVERSION=	0.1.4
CATEGORIES=	deskutils
MASTER_SITES=	http://dindinx.net/hotbabe/downloads/

MAINTAINER=	bogorodskiy@inbox.ru
COMMENT=	Small utility which displays the system activity in a very special way

USE_BZIP2=	yes
USE_X_PREFIX=	yes
MAKE_ARGS+=	PREFIX="${PREFIX}" CC="${CC}"
USE_GNOME=	gdkpixbuf

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "Warning! This port contains some adults only content."
	@${ECHO_MSG} "You might hit Ctrl-C to abort."
	@${ECHO_MSG}

.include <bsd.port.mk>
