# New ports collection makefile for:	KDE2 Graphics
# Date created:				Saturday 2 September 2000
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdegraphics
PORTVERSION=	2.2.2
PORTREVISION=	1
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org

BUILD_DEPENDS=	dvips:${PORTSDIR}/print/teTeX \
		autoconf213:${PORTSDIR}/devel/autoconf213 \
		automake14:${PORTSDIR}/devel/automake14
.if ${MACHINE_ARCH} == "i386" && !defined(NO_KDE_OBJPRELINK)
BUILD_DEPENDS+=	objprelink:${PORTSDIR}/devel/objprelink
.endif
RUN_DEPENDS=	dvips:${PORTSDIR}/print/teTeX \
		gs:${PORTSDIR}/print/ghostscript-gnu

USE_KDELIBS_VER=2
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+=--without-kamera
.if ${MACHINE_ARCH} == "i386" && !defined(NO_KDE_OBJPRELINK)
CONFIGURE_ARGS+=--enable-objprelink
.endif
.if defined(PARALLEL_PACKAGE_BUILD) || defined(WANT_KDE_FINAL)
CONFIGURE_ARGS+=--enable-final
.endif
.if defined(PARALLEL_PACKAGE_BUILD) || defined(WANT_KDE_NDEBUG)
CONFIGURE_ARGS+=--disable-debug
.endif

.include <bsd.port.pre.mk>

# temporarily disable kamera, it requires gphoto2
PLIST_SUB+=	KAMERA="@comment "

SANE_CONFIG=	${LOCALBASE}/bin/sane-config

.if exists(${SANE_CONFIG})
WITH_SANE=	yes
.endif

.if defined(WITH_SANE) && ${WITH_SANE} == yes
LIB_DEPENDS+=	sane.1:${PORTSDIR}/graphics/sane-backends
PLIST_SUB+=	SANE=""
.else
PLIST_SUB+=	SANE="@comment "
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to compile with scanner (SANE) support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_SANE=yes\""
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
	${PERL} -pi -e "s@libkscan_la_LIBADD =@libkscan_la_LIBADD= -lintl@g" ${WRKSRC}/libkscan/Makefile.in
	${PERL} -pi -e "s@libkcm_kamera_la_LIBADD =@libkcm_kamera_la_LIBADD= -lintl@g" ${WKRSRC}/kamera/kcontrol/Makefile.in
	${PERL} -pi -e "s@name = item@name=(char*)item@g" ${WRKSRC}/kamera/kcontrol/kamera.cpp
	find ${WRKSRC} -name Makefile.in | xargs ${PERL} -pi -e \
		"s@GPHOTO2_LIBS =@GPHOTO2_LIBS= -lintl@g"

.include <bsd.port.post.mk>
