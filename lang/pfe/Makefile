# New ports collection makefile for:    pfe-devel
# Date created:         29 October 2000
# Whom:                 patrick
#
# $FreeBSD$
#

PORTNAME=	pfe
PORTVERSION=	0.33.70
CATEGORIES=	lang
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implementation of ANSI Forth

LATEST_LINK=	pfe-devel

USE_BZIP2=	yes
USE_PERL5_BUILD=yes
USE_GCC=	4.2+
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
LIBTOOLFILES=	pfe/configure
MAKE_ARGS=	pkgconfigdir="${PREFIX}/libdata/pkgconfig"

MAN1=		pfe.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386" && ${OSVERSION} < 700000
BROKEN=		does not compile
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|#CFLAGS=|g ; \
		 s|-O$$opt_level||g' ${WRKSRC}/pfe/configure

.include <bsd.port.post.mk>
