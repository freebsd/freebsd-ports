# New ports collection makefile for:	kdevelop
# Date created:		12 Aug 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	kdevelop
PORTVERSION=	1.3
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.e-technik.fh-muenchen.de/pub/unix/ide/KDevelop/ \
		ftp://ftp.chg.ru/pub/X11/kdevelop/ \
		ftp://gd.tuwien.ac.at/hci/KDevelop/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	msgfmt:${PORTSDIR}/devel/gettext
LIB_DEPENDS=	kdeui.3:${PORTSDIR}/x11/kdelibs11
.if defined(WITH_OPTIONAL_DEPENDS)
RUN_DEPENDS+=	autoconf:${PORTSDIR}/devel/autoconf \
		automake:${PORTSDIR}/deve/automake \
		kdbg:${PORTSDIR}/devel/kdbg \
		${LOCALBASE}/share/doc/HTML/en/kdelibs/kdecore/index.html:${PORTSDIR}/devel/kdelibdocs \
		ktranslator:${PORTSDIR}/devel/ktranslator \
		kiconedit:${PORTSDIR}/graphics/kdegraphics11 \
		glimpse:${PORTSDIR}/textproc/glimpse \
		a2ps:${PORTSDIR}/print/a2ps43-letter
.endif

USE_BZIP2=	yes
USE_QT=		yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	QTDIR="${X11BASE}" KDEDIR="${LOCALBASE}"
CONFIGURE_ARGS=	--with-qtdoc-dir=${X11BASE}/share/doc/qt/html \
		--with-qt-includes=${X11BASE}/include/X11/qt \
		--with-extra-includes=${LOCALBASE}/include \
		--with-extra-libs=${LOCALBASE}/lib
MAKE_ARGS=	SOMAJOR="${SOMAJOR}"
PLIST_SUB=	LIBVER="${SOMAJOR}"

SOMAJOR=	1

pre-everything:
.if !defined(WITH_OPTIONAL_DEPENDS)
	@${ECHO_MSG}
	@${ECHO_MSG} "You may define WITH_OPTIONAL_DEPENDS (make WITH_OPTIONAL_DEPENDS=YES)"
	@${ECHO_MSG} "to automatically build the suggested programs to compliment kdevelop."
	@${ECHO_MSG}
.endif

.include <bsd.port.mk>
