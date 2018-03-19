# $FreeBSD$

PORTNAME=	libslang2
PORTVERSION=	2.3.1
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://www.jedsoft.org/releases/slang/
DISTNAME=	slang-${PORTVERSION}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Routines for rapid alpha-numeric terminal applications development

LICENSE=	GPLv2

CONFLICTS=	libslang-1.*.j[0-9]

USES=		tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
PLIST_SUB+=	SHLIB_VERSION=${PORTVERSION}

CONFIGURE_ARGS+=--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig

ALL_TARGET=	all static
INSTALL_TARGET=	install install-static

DOCSDIR=	${PREFIX}/share/doc/slang
DATADIR=	${PREFIX}/share/slsh

OPTIONS_DEFINE=	PCRE PNG ICONV ONIG DOCS
OPTIONS_DEFAULT=PCRE PNG ICONV
OPTIONS_SUB=	yes

ONIG_DESC=	Oniguruma support

PORTDOCS=	*

PCRE_CONFIGURE_WITH=	pcre
PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PNG_CONFIGURE_WITH=	png
PNG_LIB_DEPENDS=	libpng.so:graphics/png
ICONV_USES=		iconv
ONIG_CONFIGURE_WITH=	onig
ONIG_LIB_DEPENDS=	libonig.so:devel/oniguruma

.include <bsd.port.pre.mk>

.if ! ${PORT_OPTIONS:MICONV} || empty(ICONV_LIB)
CONFIGURE_ARGS+=	--without-iconv
.endif

post-patch:
	@${REINPLACE_CMD} -E 's,doc/slsh,doc/slang/v\@slang_major_version\@,' \
		${WRKSRC}/slsh/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in NEWS changes.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/slsh
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libslang.so.${PORTVERSION}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/slang/v2/modules/*.so

.include <bsd.port.post.mk>
