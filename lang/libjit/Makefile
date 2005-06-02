# New ports collection makefile for:	libjit
# Date created:		2004-04-27
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	libjit
PORTVERSION=	0.0.4
CATEGORIES=	lang
MASTER_SITES=	http://www.southern-storm.com.au/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Libjit implements Just-In-Time compilation functionality

USE_GMAKE=	yes
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes
USE_CONFIGURE=	yes

INSTALLS_SHLIB=	yes

INFO=		libjit
MAN3=		libjit.3

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		"Segfault during build"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure
.if ${OSVERSION} >=	502128
	@${REINPLACE_CMD} -e 's|#undef HAVE_TGMATH_H||' \
		${WRKSRC}/config.h.in
.endif

post-configure:
.if ${OSVERSION} >=	502123 && ${ARCH} != "amd64"
	@${REINPLACE_CMD} -e 's|$$pic_flag -DPIC||' \
		${WRKSRC}/libtool
.endif

.include <bsd.port.post.mk>
