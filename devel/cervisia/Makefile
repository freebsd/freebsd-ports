# New ports collection Makefile for: cervisia
# Date created:         17 Nov 1999
# Whom:                 Will Andrews <andrews@technologist.com>
#
# $FreeBSD$

PORTNAME=	cervisia
PORTVERSION=	1.0.b2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	cervisia-1.0beta2

MAINTAINER=	andrey@novikov.com

.if defined(KDE_VERSION) && ${KDE_VERSION} == "1"
LIB_DEPENDS=	kdecore.3:${PORTSDIR}/x11/kdelibs11
USE_QT=		yes
QT_VER=		""
.else
EXTRA_PATCHES=	${PATCHDIR}/kde2-patch-aa \
		${PATCHDIR}/kde2-patch-ab \
		${PATCHDIR}/kde2-patch-ac
LIB_DEPENDS=	kdecore.4:${PORTSDIR}/x11/kdelibs2
USE_QT2=	yes
MOC?=		${X11BASE}/bin/moc2
QT_VER=		2
.endif

MAN1=		cervisia.1
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

pre-fetch:
.if !defined(KDE_VERSION)
	@${ECHO}
	@${ECHO} "You may define KDE_VERSION=1 (make KDE_VERSION=1)"
	@${ECHO} "to build ${PORTNAME} against KDE1.1."
	@${ECHO}
	@sleep 3
.endif

KDE_VERSION?=	2

CONFIGURE_ARGS+=--with-kde-version=${KDE_VERSION} \
		--with-extra-includes="${LOCALBASE}/include" \
		--with-extra-libs="${LOCALBASE}/lib" \
		--with-qt-includes="${X11BASE}/include/qt${QT_VER}"
CONFIGURE_ENV+=	MOC="${MOC}" LIBQTFILE="libqt2" KDEDIR="${LOCALBASE}/kde"

.include <bsd.port.mk>
