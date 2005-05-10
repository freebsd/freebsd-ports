# New ports collection makefile for:    ja-scim-uim
# Date created:		15 Nov 2004
# Whom:			Seiya Yanagita <s_yanagita@ybb.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	scim-uim
PORTVERSION=	0.1.3
PORTREVISION=	2
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://freedesktop.org/~suzhe/sources/
MASTER_SITE_SUBDIR=scim

MAINTAINER=	s_yanagita@ybb.ne.jp
COMMENT=	SCIM IMEngine module using UIM input method library

BUILD_DEPENDS=	scim:${PORTSDIR}/textproc/scim
LIB_DEPENDS=	uim.0:${PORTSDIR}/japanese/uim
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GNOME=	lthack
USE_X_PREFIX=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=	15

CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500035
BUILD_DEPENDS+=	${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport
RUN_DEPENDS+=	${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include -I${LOCALBASE}/include/stlport" \
		LDFLAGS="-L${LOCALBASE}/lib -lstlport_gcc -lintl ${PTHREAD_LIBS}"
EXTRA_PATCHES=	${FILESDIR}/extra-patch-4-stable
.else
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include -D__STDC_ISO_10646__" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl"
.endif

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO}
	@${ECHO} To display this message again, type \`pkg_info -D ${PKGNAME}\'
	@${ECHO}

.include <bsd.port.post.mk>
