# Ports collection makefile for:  treecc
# Date created:			  Wed Jul 11 00:45:15 EDT 2001
# Whom:				  Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	pnet
PORTVERSION=	${PNET_VERSION}
PORTREVISION=	${PNET_REVISION}
CATEGORIES=	lang
MASTER_SITES=	${PNET_MASTER_SITES}
MASTER_SITE_SUBDIR=	${PNET_MASTER_SITE_SUBDIR}
PKGNAMESUFFIX=	base

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	C\# compiler and runtime engine

BUILD_DEPENDS=	treecc:${PORTSDIR}/lang/treecc

NOT_FOR_ARCHS=	sparc64

.if !defined(WITHOUT_X11)
USE_XLIB=	yes
.endif

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS+=	--enable-threads=posix

.if !defined(WITH_OPTIMIZED_CFLAGS)
CONFIGURE_ARGS+=	--disable-optimizations
.endif

PORTDOCS=	pnetasm.texi pnettools.info pnettools.texi texinfo.tex
INFO=	pnettools
MAN1=	clrwrap.1 csant.1 cscc.1 csdoc.1 csdoc2hier.1 csdoc2html.1 \
	cscc-cpp.1 csdoc2texi.1 cssrc2html.1 ilalink.1 ilasm.1 ildasm.1 \
	ildd.1 ilfind.1 ilgac.1 ilheader.1 ilnative.1 ilranlib.1 ilrun.1 \
	ilsize.1 ilstrip.1 ilverify.1 resgen.1
MLINKS=	ilasm.1 al.1 \
	ar.1 cli-unknown-ar.1 \
	cscc-cpp.1 cli-unknown-cpp.1 \
	cscc.1 cli-unknown-gcc.1 \
	ilranlib.1 cli-unknown-ranlib.1 \
	ilsize.1 cli-unknown-size.1 \
	ilstrip.1 cli-unknown-strip.1

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
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docfile in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
