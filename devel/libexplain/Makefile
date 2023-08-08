PORTNAME=	libexplain
PORTVERSION=	1.3.${PATCHLEVEL}
PORTREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION:R}
DISTNAME=	${PORTNAME}-${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library which may be used to explain Unix and Linux system call errors
WWW=		http://libexplain.sourceforge.net/

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Upstream last release was in 2014
#BROKEN_FreeBSD_14=	Build fails with lots of error on llvm15

BUILD_DEPENDS=	gsed:textproc/gsed
RUN_DEPENDS=	lsof:sysutils/lsof

USES=		bison gettext ghostscript:build gmake groff iconv libtool:build localbase
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_header_linux_kd_h=no

OPTIONS_DEFINE=	DOCS

PATCHLEVEL=	D012

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
USES+=		llvm:max=14
CPP=            clang-cpp${LLVM_VERSION}
CC=             clang${LLVM_VERSION}
CXX=            clang++${LLVM_VERSION}
MAKE_JOBS_UNSAFE=	yes
.endif

.include <bsd.port.pre.mk>

.if empty(ICONV_LIB)
CONFIGURE_ARGS+=ac_cv_lib_iconv_iconv=no
.else
CONFIGURE_ARGS+=ac_cv_func_iconv_open=yes ac_cv_func_iconv_close=yes \
		ac_cv_lib_iconv_iconv=yes
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|$$(libdir)/pkgconfig|$$(libdir)/../libdata/pkgconfig|g ; \
		 s|\([[:blank:]]\)sed|\1gsed|g' ${WRKSRC}/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libexplain.so

.include <bsd.port.post.mk>
