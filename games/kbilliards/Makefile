# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	kbilliards
PORTVERSION=	0.8.7b
PORTREVISION=	6
CATEGORIES=	games kde
MASTER_SITES=	http://www.hostnotfound.it/kbilliards/ \
		LOCAL/arved

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Funny billiards simulator game for KDE

LICENSE=	GPLv2 # (or later)

EXTRA_PATCHES=	${.CURDIR}/../../x11/kde3/files/extrapatch-old_configure

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_PERL5_BUILD=yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
MAKE_JOBS_SAFE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800024
CFLAGS+=	-Dsqrtl=sqrt
.endif

pre-configure:
	@cd ${WRKSRC} && ${PERL} admin/am_edit

.include <bsd.port.post.mk>
