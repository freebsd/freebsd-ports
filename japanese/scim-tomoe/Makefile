# New ports collection makefile for:	ja-scim-tomoe
# Date created:				18 Dec 2005
# Whom:					Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	scim-tomoe
PORTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=scim-imengine/17173

MAINTAINER=	ume@FreeBSD.org
COMMENT=	SCIM IMEngine module using Tomoe

BUILD_DEPENDS=	scim:${PORTSDIR}/textproc/scim
LIB_DEPENDS=	tomoe.1:${PORTSDIR}/japanese/tomoe \
		tomoe-gtk.0:${PORTSDIR}/japanese/libtomoe-gtk

USE_GNOME=	lthack
USE_X_PREFIX=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

PLIST_FILES=	lib/scim-1.0/1.4.0/Helper/tomoe.a \
		lib/scim-1.0/1.4.0/Helper/tomoe.la \
		lib/scim-1.0/1.4.0/Helper/tomoe.so \
		share/locale/ja/LC_MESSAGES/scim-tomoe.mo \
		share/scim/icons/scim-tomoe.png

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500035
BUILD_DEPENDS+=	${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport
RUN_DEPENDS+=	${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/stlport" \
		LDFLAGS="-L${LOCALBASE}/lib -lstlport_gcc ${PTHREAD_LIBS}"
.else
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include -D__STDC_ISO_10646__" \
		LDFLAGS="-L${LOCALBASE}/lib"
.endif

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO}
	@${ECHO} To display this message again, type \`pkg_info -D ${PKGNAME}\'
	@${ECHO}

.include <bsd.port.post.mk>
