# New ports collection makefile for:	gxneur
# Date created:				07 December 2008
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	gxneur
PORTVERSION=	0.9.4
CATEGORIES=	deskutils
MASTER_SITES=	http://dists.xneur.ru/release-${PORTVERSION}/tgz/

MAINTAINER=	ports@logvinov.com
COMMENT=	GTK frontend for XNeur keyboard layout switcher

BUILD_DEPENDS=	xneur:${PORTSDIR}/deskutils/xneur
RUN_DEPENDS=	xneur:${PORTSDIR}/deskutils/xneur

MAKE_JOBS_SAFE=	yes

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 libglade2

MAN1=		${PORTNAME}.1

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.post.mk>
