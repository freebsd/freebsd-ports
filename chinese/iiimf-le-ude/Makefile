# New ports collection makefile for:	iiimf-le-ude
# Date created:		11 Sep 2004
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	le-ude
PORTVERSION=	${IIIMF_VER:S/_/./g:C/-.*//}
CATEGORIES=	chinese textproc
MASTER_SITES=	http://www.openi18n.org/download/im-sdk/src/
PKGNAMEPREFIX=	iiimf-
DISTNAME=	im-sdk
DISTFILES=	${DISTNAME}-src-${IIIMF_VER}.tgz

MAINTAINER=	kcwu@csie.org
COMMENT=	IIIMF User Defined language Engine for Simplified Chinese conversion

RUN_DEPENDS=	${LOCALBASE}/lib/im/htt:${PORTSDIR}/textproc/iiimf-server

IIIMF_VER=	r12_0_1-svn1891
WRKSRC=		${WRKDIR}/${DISTNAME}-${IIIMF_VER}/leif
BUILD_WRKSRC=	${WRKSRC}/ude
INSTALL_WRKSRC=	${WRKSRC}/ude
USE_REINPLACE=	yes
USE_AUTOCONF_VER=	259
USE_AUTOHEADER_VER=	259
USE_AUTOMAKE_VER=	19
USE_LIBTOOL_VER=	15
AUTOMAKE_ARGS+=	--add-missing --copy --gnu
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

post-patch:
	${REINPLACE_CMD} -e "s,/usr/lib/im,${PREFIX}/lib/im,g" \
		${WRKSRC}/../acfiles/im_common.m4 \
		${WRKSRC}/configure.ac \
		${WRKSRC}/ude/UDEngine.c

pre-configure:
	cd ${WRKSRC} && ${ACLOCAL} -I ${LOCALBASE}/share/aclocal -I ../acfiles
	${TOUCH} ${WRKSRC}/config.h.in
	cd ${WRKSRC} && ${LIBTOOLIZE} --copy --force --automake

.include <bsd.port.mk>
