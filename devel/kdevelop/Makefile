# New ports collection makefile for:	kdevelop
# Date created:		12 Aug 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	kdevelop
PORTVERSION=	2.1.5
PORTREVISION=	1
CATEGORIES?=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/kdevelop-${PORTVERSION}/src
DISTNAME=	${KDE_DISTNAME}
DIST_SUBDIR=	KDE

MAINTAINER?=	kde@FreeBSD.org
COMMENT=	Powerful IDE for developing KDE/Qt-based apps

RUN_DEPENDS=	extractrc:${PORTSDIR}/devel/kdesdk3 \
		gmake:${PORTSDIR}/devel/gmake
.if defined(WITH_OPTIONAL_DEPENDS)
RUN_DEPENDS+=	autoconf:${PORTSDIR}/devel/autoconf \
		automake:${PORTSDIR}/devel/automake \
		kiconedit:${PORTSDIR}/graphics/kdegraphics3 \
		ark:${PORTSDIR}/misc/kdeutils3 \
		glimpse:${PORTSDIR}/textproc/glimpse \
		a2ps:${PORTSDIR}/print/a2ps-letter
.endif

KDE_DISTNAME=		${PORTNAME}-${PORTVERSION}_for_KDE_3.1
USE_KDELIBS_VER=3
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-qtdoc-dir=${X11BASE}/share/doc/qt/html
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"

pre-everything::
.if !defined(WITH_OPTIONAL_DEPENDS)
	@${ECHO_MSG}
	@${ECHO_MSG} "You may define WITH_OPTIONAL_DEPENDS (make WITH_OPTIONAL_DEPENDS=YES)"
	@${ECHO_MSG} "to automatically build the suggested programs to compliment kdevelop."
	@${ECHO_MSG}
.endif

pre-configure:
	${REINPLACE_CMD} -e 's@extractrc@@g' ${WRKSRC}/kdevelop/Makefile.in
	${REINPLACE_CMD} -e 's@-pedantic @@g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
