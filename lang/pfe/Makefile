# Created by: patrick
# $FreeBSD$

PORTNAME=	pfe
PORTVERSION=	0.33.71
CATEGORIES=	lang
MASTER_SITES=	SF

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Implementation of ANSI Forth

USE_BZIP2=	yes
USES=		gmake perl5
USE_PERL5=	build
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
LIBTOOLFILES=	pfe/configure
MAKE_ARGS=	pkgconfigdir="${PREFIX}/libdata/pkgconfig"

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		does not compile
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|#CFLAGS=|g ; \
		 s|-O$$opt_level||g' ${WRKSRC}/pfe/configure

.include <bsd.port.post.mk>
