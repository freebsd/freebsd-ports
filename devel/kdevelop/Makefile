# New ports collection makefile for:	kdevelop
# Date created:		12 Aug 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	kdevelop
PORTVERSION=	3.0.4
CATEGORIES?=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${KDE_VERSION}/src
# DISTNAME=	${KDE_DISTNAME}
DIST_SUBDIR=	KDE

MAINTAINER?=	kde@FreeBSD.org
COMMENT=	Powerful IDE for developing KDE/Qt-based apps

BUILD_DEPENDS=	cervisia:${PORTSDIR}/devel/kdesdk3 \
		msgfmt:${PORTSDIR}/devel/gettext
LIB_DEPENDS=	db4:${PORTSDIR}/databases/db4
RUN_DEPENDS=	extractrc:${PORTSDIR}/devel/kdesdk3 \
		gmake:${PORTSDIR}/devel/gmake
.if defined(WITH_OPTIONAL_DEPENDS)
RUN_DEPENDS+=	kiconedit:${PORTSDIR}/graphics/kdegraphics3 \
		ark:${PORTSDIR}/misc/kdeutils3 \
		glimpse:${PORTSDIR}/textproc/glimpse \
		a2ps:${PORTSDIR}/print/a2ps-letter
.endif

# KDE_DISTNAME=		${PORTNAME}-${PORTVERSION}_for_KDE_3.1

WANT_AUTOMAKE_VER=	18
WANT_AUTOMAKE_RUN=	yes
WANT_AUTOCONF_VER=	259
WANT_AUTOCONF_RUN=	yes
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
	@${ECHO_MSG} "to automatically build the suggested programs to complement kdevelop."
	@${ECHO_MSG}
.endif

post-patch:
	${TOUCH} -t 200401230000 ${WRKSRC}/Makefile.am.in

pre-configure:
	${REINPLACE_CMD} -e 's@extractrc@@g' ${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e 's@$$CXXFLAGS $$X_CFLAGS -ldb@-I/usr/local/include/db4 $$CXXFLAGS $$X_CFLAGS -L/usr/local/lib -ldb4@' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's@INCLUDES = $$(all_includes)@INCLUDES = -I/usr/local/include/db4 $$(all_includes)@' ${WRKSRC}/lib/catalog/Makefile.in
	${REINPLACE_CMD} -e 's@libkdevcatalog_la_LIBADD = -ldb@libkdevcatalog_la_LIBADD = -L/usr/local/lib -ldb4@' ${WRKSRC}/lib/catalog/Makefile.in
	${REINPLACE_CMD} -e 's@^all_includes = @all_includes = -I/usr/local/include/db4 @' ${WRKSRC}/languages/cpp/Makefile.in
	${REINPLACE_CMD} -e 's@^all_includes = @all_includes = -I/usr/local/include/db4 @' ${WRKSRC}/languages/java/Makefile.in
	${REINPLACE_CMD} -e 's@^all_includes = @all_includes = -I/usr/local/include/db4 @' ${WRKSRC}/languages/pascal/Makefile.in

.include <bsd.port.post.mk>
