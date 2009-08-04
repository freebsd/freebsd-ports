# New ports collection Makefile for:	kdegames
# Date created:				2008-02-08
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kdegames
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	games kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Games for the KDE integrated X11 desktop

LIB_DEPENDS=	ggzcore.9:${PORTSDIR}/games/ggz-client-libs \
		qca.2:${PORTSDIR}/devel/qca

LATEST_LINK=	${PORTNAME}4

USE_BZIP2=	yes
USE_KDE4=	kdelibs kdeprefix kdehier automoc4
KDE4_BUILDENV=	yes
USE_QT_VER=	4
QT_COMPONENTS=	opengl gui svg iconengines pixeltool \
		qmake_build moc_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes

OPTIONS=	FREEBSD "Install FreeBSD card desk" off

.include <bsd.port.pre.mk>

.if defined(WITH_FREEBSD)
RUN_DEPENDS=	kde4-freebsd-carddeck>=1.0:${PORTSDIR}/games/freebsd-carddeck-kde4
.endif

post-extract:
	${MKDIR} ${WRKSRC}

.include <bsd.port.post.mk>
