# New ports collection makefile for:    ja-scim-anthy
# Date created:		2 Mar 2005
# Whom:			Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	scim-anthy
PORTVERSION=	0.6.0
PORTREVISION=	0
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=scim-imengine/15823

MAINTAINER=	ume@FreeBSD.org
COMMENT=	SCIM IMEngine module using Anthy

BUILD_DEPENDS=	scim:${PORTSDIR}/textproc/scim
LIB_DEPENDS=	anthy.1:${PORTSDIR}/japanese/anthy
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GNOME=	lthack
USE_X_PREFIX=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=15

CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

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
