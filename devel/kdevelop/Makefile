# New ports collection makefile for:	kdevelop
# Date created:		12 Aug 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	kdevelop
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/2.1/distribution/tar/generic/src

MAINTAINER=	demon@FreeBSD.org

BUILD_DEPENDS=	msgfmt:${PORTSDIR}/devel/gettext
LIB_DEPENDS=	kdeui.4:${PORTSDIR}/x11/kdelibs2
RUN_DEPENDS=	gmake:${PORTSDIR}/devel/gmake
.if defined(WITH_OPTIONAL_DEPENDS)
RUN_DEPENDS+=	autoconf:${PORTSDIR}/devel/autoconf \
		automake:${PORTSDIR}/devel/automake \
		${LOCALBASE}/share/doc/HTML/en/kdelibs/kdecore/index.html:${PORTSDIR}/devel/kdelibdocs \
		ktranslator:${PORTSDIR}/devel/ktranslator \
		kdoc:${PORTSDIR}/textproc/kdoc \
		kiconedit:${PORTSDIR}/graphics/kdegraphics2 \
		ark:${PORTSDIR}/misc/kdeutils2 \
		glimpse:${PORTSDIR}/textproc/glimpse \
		designer:${PORTSDIR}/devel/qt-designer \
		linguist:${PORTSDIR}/devel/linguist \
		kbabel:${PORTSDIR}/devel/kdesdk \
		a2ps:${PORTSDIR}/print/a2ps43-letter
.endif

USE_BZIP2=	yes
USE_QT2=	yes
MOC?=		${X11BASE}/bin/moc2
USE_GMAKE=	yes
USE_AUTOCONF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-qt-includes=${X11BASE}/include/qt2 \
		--with-qt-libraries=${X11BASE}/lib \
		--with-qtdoc-dir=${X11BASE}/share/doc/qt2/html \
		--with-extra-libs=${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${PREFIX}/include" \
		MOC="${MOC}" LIBQT="-lqt2" LIBQTFILE="libqt2" \
		LIBS="-Wl,-export-dynamic -L${LOCALBASE}/lib -ljpeg -lgcc -lstdc++"

pre-everything:
.if !defined(WITH_OPTIONAL_DEPENDS)
	@${ECHO_MSG}
	@${ECHO_MSG} "You may define WITH_OPTIONAL_DEPENDS (make WITH_OPTIONAL_DEPENDS=YES)"
	@${ECHO_MSG} "to automatically build the suggested programs to compliment kdevelop."
	@${ECHO_MSG}
.endif

.include <bsd.port.mk>
