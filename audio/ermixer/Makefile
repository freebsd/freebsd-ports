# ex:ts=8	-*-mode: makefile-*-
#
# New ports collection makefile for:	ermixer
# Date created:		2003-01-20
# Whom:			Alan Eldridge <alane@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	ermixer
PORTVERSION=	0.8
PORTREVISION=	1
PORTEPOCH=	0
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A command-line, ncurses, and Qt-GUI OSS audio mixer

USE_QT_VER=	3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-qt

CONFIGURE_ENV+=	QTDIR="${X11BASE}"
CONFIGURE_ENV+=	LDFLAGS="${PTHREAD_LIBS} -L${X11BASE}/lib"
CONFIGURE_ENV+=	CPPFLAGS="${PTHREAD_CFLAGS} -I${X11BASE}/include"

.include <bsd.port.pre.mk>
.include "${FILESDIR}/manpages.mk"
.include <bsd.port.post.mk>
