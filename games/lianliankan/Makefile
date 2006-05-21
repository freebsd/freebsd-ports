# New ports collection makefile for:	lianliankan
# Date created:				26 April 2006
# Whom:					Liu.Yinghong <liu_yinghong@yahoo.com.cn>
#
# $FreeBSD$
#

PORTNAME=	lianliankan
PORTVERSION=	2.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	llk-linux
DISTNAME=	llk_linux-${PORTVERSION}

MAINTAINER=	liu_yinghong@yahoo.com.cn
COMMENT=	A scarce recreation game

USE_GNOME=	gtk20 esound
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		does not compile
.endif

post-install:
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${FILESDIR}/lianliankan.desktop ${PREFIX}/share/applications

.include <bsd.port.post.mk>
