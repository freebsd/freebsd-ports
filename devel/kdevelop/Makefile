# New ports collection makefile for:	kdevelop
# Date created:		12 Aug 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	kdevelop
PORTVERSION=	2.0.2
CATEGORIES?=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/2.2.2/src
DIST_SUBDIR=	KDE

MAINTAINER?=	kde@FreeBSD.org

BUILD_DEPENDS=	msgfmt:${PORTSDIR}/devel/gettext \
		autoconf213:${PORTSDIR}/devel/autoconf213 \
		automake14:${PORTSDIR}/devel/automake14
.if ${MACHINE_ARCH} == "i386" && !defined(NO_KDE_OBJPRELINK)
BUILD_DEPENDS+=	objprelink:${PORTSDIR}/devel/objprelink
.endif
RUN_DEPENDS=	gmake:${PORTSDIR}/devel/gmake
.if defined(WITH_OPTIONAL_DEPENDS)
RUN_DEPENDS+=	autoconf:${PORTSDIR}/devel/autoconf \
		automake:${PORTSDIR}/devel/automake \
		kdoc:${PORTSDIR}/textproc/kdoc \
		kiconedit:${PORTSDIR}/graphics/kdegraphics2 \
		ark:${PORTSDIR}/misc/kdeutils2 \
		glimpse:${PORTSDIR}/textproc/glimpse \
		designer:${PORTSDIR}/devel/qt-designer \
		linguist:${PORTSDIR}/devel/linguist \
		kdbg:${PORTSDIR}/devel/kdbg \
		kbabel:${PORTSDIR}/devel/kdesdk \
		a2ps:${PORTSDIR}/print/a2ps-letter
.endif

USE_KDELIBS_VER=2
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-qtdoc-dir=${X11BASE}/share/doc/qt2/html
.if ${MACHINE_ARCH} == "i386" && !defined(NO_KDE_OBJPRELINK)
CONFIGURE_ARGS+=--enable-objprelink
.endif
.if defined(PARALLEL_PACKAGE_BUILD) || defined(WANT_KDE_FINAL)
CONFIGURE_ARGS+=--enable-final
.endif
.if defined(PARALLEL_PACKAGE_BUILD) || defined(WANT_KDE_NDEBUG)
CONFIGURE_ARGS+=--disable-debug
.endif

pre-everything::
.if !defined(WITH_OPTIONAL_DEPENDS)
	@${ECHO_MSG}
	@${ECHO_MSG} "You may define WITH_OPTIONAL_DEPENDS (make WITH_OPTIONAL_DEPENDS=YES)"
	@${ECHO_MSG} "to automatically build the suggested programs to compliment kdevelop."
	@${ECHO_MSG}
.endif

pre-configure:
	${MKDIR} ${WRKSRC}/auto-bin
.for AC in autoconf autoheader
	${LN} -sf ${LOCALBASE}/bin/${AC}213 ${WRKSRC}/auto-bin/${AC}
.endfor
.for AM in automake aclocal
	${LN} -sf ${LOCALBASE}/bin/${AM}14 ${WRKSRC}/auto-bin/${AM}
.endfor
	cd ${WRKSRC} && env PATH=${WRKSRC}/auto-bin:$$PATH \
		${GMAKE} -f Makefile.cvs

pre-build:
	${PERL} -pi -e "s@libkdeui.so.3@libkdeui.so@g" ${WRKSRC}/kdevelop/main.cpp

.include <bsd.port.mk>
