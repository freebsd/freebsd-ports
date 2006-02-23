# New ports collection makefile for:	kbilliards
# Date created:				15 May 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$

PORTNAME=	kbilliards
PORTVERSION=	0.8.6
CATEGORIES=	games kde
MASTER_SITES=	http://www.hostnotfound.it/kbilliards/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Funny billiards simulator game for KDE

EXTRA_PATCHES=	${.CURDIR}/../../x11/kde3/files/extrapatch-old_configure

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_PERL5_BUILD=yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15

CFLAGS+=	-Dsqrtl=sqrt

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 502114
CFLAGS+=	-Dround=rint
.endif

pre-configure:
	@cd ${WRKSRC} && ${PERL} admin/am_edit

.include <bsd.port.post.mk>
