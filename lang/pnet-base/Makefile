# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	pnet
PORTVERSION=	${PNET_VERSION}
PORTREVISION=	${PNET_REVISION}
CATEGORIES=	lang
MASTER_SITES=	${PNET_MASTER_SITES}
MASTER_SITE_SUBDIR=	${PNET_MASTER_SITE_SUBDIR}
PKGNAMESUFFIX=	base

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C\# compiler and runtime engine

BUILD_DEPENDS=	treecc:${PORTSDIR}/lang/treecc

DEPRECATED=	Alpha-quality abandonware - Decommissioned Dec 2012 - Use mono
EXPIRATION=	2014-05-01

NOT_FOR_ARCHS=	sparc64

.if !defined(WITHOUT_X11)
USE_XLIB=	yes
.endif

GNU_CONFIGURE=	yes
USES=		gmake
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

CONFIGURE_ARGS+=	--enable-threads=posix

.if !defined(WITH_OPTIMIZED_CFLAGS)
CONFIGURE_ARGS+=	--disable-optimizations
.endif

PORTDOCS=	pnetasm.texi pnettools.info pnettools.texi texinfo.tex
INFO=	pnettools
.include "${.CURDIR}/../pnet/Makefile.pnet"
.include <bsd.port.pre.mk>

.if ${ARCH} != "i386" || ${OSVERSION} < 700000
CONFIGURE_ARGS+=	--without-libffi \
			--without-libgc
PLIST_SUB=	I386="@comment "
.else
PLIST_SUB=	I386=""

.endif

post-everything::
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "Define optimized CFLAGS with"
	@${ECHO_MSG} "WITH_OPTIMIZED_CFLAGS=yes"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|`$$CC -print-multi-os-directory 2>/dev/null`|elf|' \
		${WRKSRC}/libffi/configure
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/ltconfig \
		${WRKSRC}/libgc/configure

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docfile in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${docfile} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
