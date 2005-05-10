# New ports collection makefile for:    ja-scim-canna
# Date created:				2005-04-03
# Whom:					Norikatsu Shigemura <nork@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	scim-canna
PORTVERSION=	0.0.0
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	http://www.homa.ne.jp/~ashie/linux/files/

MAINTAINER=	nork@FreeBSD.org
COMMENT=	SCIM IMEngine module using Canna

BUILD_DEPENDS=	scim:${PORTSDIR}/textproc/scim
LIB_DEPENDS+=	canna.1:${PORTSDIR}/japanese/Canna
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GNOME=	lthack
USE_X_PREFIX=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=15

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500035
BUILD_DEPENDS+=	${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport
RUN_DEPENDS+=	${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/stlport" \
		LDFLAGS="-L${LOCALBASE}/lib -lstlport_gcc"
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
