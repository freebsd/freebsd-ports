# New ports collection makefile for:	lianliankan
# Date created:				26 April 2006
# Whom:					Yinghong Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	lianliankan
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	llk-linux
DISTNAME=	llk_linux-${PORTVERSION}

MAINTAINER=	relaxbsd@gmail.com
COMMENT=	A scarce recreation game

USE_GNOME=	gtk20 esound
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

post-install:
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${FILESDIR}/lianliankan.desktop ${PREFIX}/share/applications

.include <bsd.port.post.mk>
