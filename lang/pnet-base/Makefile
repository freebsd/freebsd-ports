# Ports collection makefile for:  treecc
# Date created:			  Wed Jul 11 00:45:15 EDT 2001
# Whom:				  Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	pnet
PORTVERSION=	${PNET_VERSION}
CATEGORIES=	lang
MASTER_SITES=	${PNET_MASTER_SITES}
PKGNAMESUFFIX=	base

MAINTAINER=	ahze@ahze.net
COMMENT=	C\# compiler and runtime engine

BUILD_DEPENDS=	treecc:${PORTSDIR}/lang/treecc
LIB_DEPENDS=	ffi.2:${PORTSDIR}/devel/libffi

USE_LIBTOOL=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

CONFIGURE_ARGS+=	--enable-threads=posix

.if !defined(WITH_OPTIMIZED_CFLAGS)
CONFIGURE_ARGS+=	--disable-optimizations
.endif

INFO=	pnettools
MAN1=	clrwrap.1 csant.1 cscc.1 csdoc.1 csdoc2hier.1 csdoc2html.1 \
	csdoc2texi.1 cssrc2html.1 ilalink.1 ilasm.1 ildasm.1 ildd.1 \
	ilfind.1 ilheader.1 ilnative.1 ilranlib.1 ilrun.1 ilsize.1 \
	ilstrip.1 ilverify.1 resgen.1

.include <bsd.port.pre.mk>

post-everything::
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "Define optimized CFLAGS with"
	@${ECHO_MSG} "WITH_OPTIMIZED_CFLAGS=yes"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|`$$CC -print-multi-os-directory 2>/dev/null`|elf|' \
		${WRKSRC}/libffi/configure ${WRKSRC}/libffi/configure.in

.include "${.CURDIR}/../pnet/Makefile.pnet"
.include <bsd.port.post.mk>
