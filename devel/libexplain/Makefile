# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libexplain
PORTVERSION=	1.3.${PATCHLEVEL}
PORTREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION:R}
DISTNAME=	${PORTNAME}-${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library which may be used to explain Unix and Linux system call errors

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gsed:textproc/gsed
RUN_DEPENDS=	lsof:sysutils/lsof

USES=		bison gettext ghostscript:build gmake iconv libtool:build
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_header_linux_kd_h=no
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

PATCHLEVEL=	D012

OPTIONS_DEFINE=	DOCS

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
