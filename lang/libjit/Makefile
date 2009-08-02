# New ports collection makefile for:	libjit
# Date created:		2004-04-27
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	libjit
PORTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://download.savannah.gnu.org/releases/dotgnu-pnet/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Libjit implements Just-In-Time compilation functionality

USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

USE_LDCONFIG=	yes

INFO=		libjit
MAN3=		libjit.3

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		Segfault during build
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Fails to compile: internal gcc error
.endif

post-patch:
# fix for amd64, Upstream forgot a header file
	${CP} ${FILESDIR}/extra-jit-rules-interp.h ${WRKSRC}/jit/jit-rules-interp.h
	@${REINPLACE_CMD} -e 's|#undef HAVE_TGMATH_H||' \
		${WRKSRC}/config.h.in

post-configure:
.if ${ARCH} != "amd64"
	@${REINPLACE_CMD} -e 's|$$pic_flag -DPIC||' \
		${WRKSRC}/libtool
.endif

.include <bsd.port.post.mk>
