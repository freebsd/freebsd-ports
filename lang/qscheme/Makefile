# New ports collection makefile for:	qscheme
# Date created:			6 Dec 2001
# Whom:				erik@smluc.org
#
# $FreeBSD$
#

PORTNAME=	qscheme
PORTVERSION=	0.5.1
CATEGORIES=	lang
MASTER_SITES=	http://www.sof.ch/dan/qscheme/files/

MAINTAINER=	erik@smluc.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libavcall.a:${PORTSDIR}/devel/ffcall\
		${LOCALBASE}/lib/libpcre.a:${PORTSDIR}/devel/pcre
LIB_DEPENDS=	getline:${PORTSDIR}/devel/libgetline

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
#USE_AUTOCONF=	yes
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

CONFIGURE_ARGS=	--with-pcre-dir=${LOCALBASE}/lib \
		--with-pcre-inc=${LOCALBASE}/include \
		--with-avcall-dir=${LOCALBASE}/lib \
		--with-avcall-inc=${LOCALBASE}/include

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
BUILD_DEPENDS+= ${LOCALBASE}/include/gmp.h:${PORTSDIR}/math/libgmp4
CONFIGURE_ARGS+= --with-gmp-lib=${LOCALBASE}/lib \
		--with-gmp-inc=${LOCALBASE}/include
.endif

.include <bsd.port.post.mk>
