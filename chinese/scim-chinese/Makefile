# New ports collection makefile for:    zh-scim-chinese
# Date created:		20 May 2004
# Whom:			Jie Gao	<gaoj@cpsc.ucalgary.ca>
#
# $FreeBSD$
#

PORTNAME=	scim-chinese
PORTVERSION=	0.4.1
CATEGORIES=	chinese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://freedesktop.org/~suzhe/scim-chinese/
MASTER_SITE_SUBDIR=scim

MAINTAINER=	gaoj@cpsc.ucalgary.ca
COMMENT=	SCIM Chinese Smart Pinyin input method

BUILD_DEPENDS=	scim:${PORTSDIR}/textproc/scim
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
BUILD_DEPENDS+= ${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport
RUN_DEPENDS+=   ${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport
CONFIGURE_ENV+= CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/stlport" \
                LDFLAGS="-L${LOCALBASE}/lib -lstlport_gcc -lintl ${PTHREAD_LIBS}"
EXTRA_PATCHES=	${FILESDIR}/extra-patch-4-stable
.else
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include -D__STDC_ISO_10646__" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl"
.endif

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO}
	@${ECHO} To display this message again, type \`make post-install\'
	@${ECHO}

.include <bsd.port.post.mk>
