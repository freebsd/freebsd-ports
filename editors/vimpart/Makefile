# New ports collection makefile for:	vimpart
# Date created:				11 Febrary 2004
# Whom:					Michael Nottebrock <lofi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	${VIMPART_PORTNAME}
PORTVERSION=	${VIMPART_PORTVERSION}
PORTREVISION=	${VIMPART_PORTREVISION}
CATEGORIES=	editors kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE wrapper for gvim

KDE_SPLIT=	${VIMPART_PORTNAME:S/${KDE_SPLIT_DIST}-//}
KDE_DOC_SPLIT=	# none
USE_KDELIBS_VER=3

USE_BZIP2=	yes
PREFIX=		${KDE_PREFIX}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib/kde3

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include "${.CURDIR}/../../misc/kdeaddons3/Makefile.split"
.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/gvim)
RUN_DEPENDS+=	gvim:${PORTSDIR}/editors/vim
.endif

.include <bsd.port.post.mk>
