# New ports collection Makefile for: cervisia
# Date created:         17 Nov 1999
# Whom:                 Will Andrews <andrews@technologist.com>
#
# $FreeBSD$

PORTNAME=	cervisia
PORTVERSION=	1.3
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	andrey@novikov.com

.if defined(KDE_VERSION) && ${KDE_VERSION} == "1"
LIB_DEPENDS=	kdecore.3:${PORTSDIR}/x11/kdelibs11
USE_QT=		yes
QT_VER=		""
.else
LIB_DEPENDS=	kdecore.4:${PORTSDIR}/x11/kdelibs2
USE_QT2=	yes
MOC?=		${X11BASE}/bin/moc2
QT_VER=		2
.endif
LIB_DEPENDS+=	intl.1:${PORTSDIR}/devel/gettext

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		cervisia.1

pre-everything::
.if !defined(KDE_VERSION)
	@${ECHO}
	@${ECHO} "You may define KDE_VERSION=1 (make KDE_VERSION=1)"
	@${ECHO} "to build ${PORTNAME} against KDE1.1."
	@${ECHO}
	@sleep 3
.endif

KDE_VERSION?=	2

.include <bsd.port.pre.mk>

# Hack to make pthread support work correctly.
.if exists(${X11BASE}/lib/libqt2-mt.so)
.if exists(${X11BASE}/lib/libXThrStub.so)
QT_ADD=		-mt
.else
QT_ADD=		""
PTHREAD_CFLAGS=
PTHREAD_LIBS=
.endif
.endif
CFLAGS+=	${PTHREAD_CFLAGS} ${PTHREAD_LIBS}
LDFLAGS+=	${PTHREAD_LIBS}

CONFIGURE_ARGS+=--with-kde-version=${KDE_VERSION} \
		--with-extra-includes="${LOCALBASE}/include" \
		--with-extra-libs="${LOCALBASE}/lib" \
		--with-qt-libraries=${X11BASE}/lib \
		--with-qt-includes="${X11BASE}/include/qt${QT_VER}"
CONFIGURE_ENV+=	MOC="${MOC}" LIBQT="-lqt${QT_VER}${QT_ADD}" LIBQTFILE="libqt${QT_VER}${QT_ADD}" KDEDIR="${LOCALBASE}/kde" \
		CPPFLAGS="${PTHREAD_CFLAGS}" \
		LIBS="${PTHREAD_LIBS}" \
		USER_LDFLAGS="${PTHREAD_LIBS}"

post-configure:
	@${CP} ${WRKSRC}/libtool ${WRKSRC}/libtool.orig
	@${SED} -e 's@\\\$$compiler_flags@\\\$$compiler_flags ${PTHREAD_LIBS}@g' ${WRKSRC}/libtool.orig \
		> ${WRKSRC}/libtool

.include <bsd.port.post.mk>
