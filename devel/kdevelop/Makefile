# New ports collection makefile for:	kdevelop
# Date created:		12 Aug 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	kdevelop
PORTVERSION=	2.1.3
CATEGORIES?=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/3.0.3/src
DISTNAME=	${KDE_DISTNAME}
DIST_SUBDIR=	KDE

MAINTAINER?=	kde@FreeBSD.org

RUN_DEPENDS=	gmake:${PORTSDIR}/devel/gmake
.if defined(WITH_OPTIONAL_DEPENDS)
RUN_DEPENDS+=	autoconf:${PORTSDIR}/devel/autoconf \
		automake:${PORTSDIR}/devel/automake \
		kiconedit:${PORTSDIR}/graphics/kdegraphics3 \
		ark:${PORTSDIR}/misc/kdeutils3 \
		glimpse:${PORTSDIR}/textproc/glimpse \
		kbabel:${PORTSDIR}/devel/kdesdk3 \
		a2ps:${PORTSDIR}/print/a2ps-letter
.endif

KDE_DISTNAME=		${PORTNAME}-${PORTVERSION}_for_KDE_3.0
USE_KDELIBS_VER=3
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-qtdoc-dir=${X11BASE}/share/doc/qt/html

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"

pre-everything::
.if !defined(WITH_OPTIONAL_DEPENDS)
	@${ECHO_MSG}
	@${ECHO_MSG} "You may define WITH_OPTIONAL_DEPENDS (make WITH_OPTIONAL_DEPENDS=YES)"
	@${ECHO_MSG} "to automatically build the suggested programs to compliment kdevelop."
	@${ECHO_MSG}
.endif

.include <bsd.port.mk>
