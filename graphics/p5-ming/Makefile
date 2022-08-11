PORTNAME=	ming
DISTVERSIONPREFIX=	ming-
DISTVERSION=	0_4_8
CATEGORIES=	graphics perl5
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl module for Ming which allows you to create Flash 4/5 movies

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/LICENSE_GPL2
LICENSE_FILE_LGPL21=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libgif.so:graphics/giflib \
		libming.so:graphics/ming \
		libpng.so:graphics/png

USES=		autoreconf bison gmake libtool localbase perl5 pkgconfig  shebangfix

CONFIGURE_ARGS=	--enable-perl
GNU_CONFIGURE=	yes

BUILD_WRKSRC=	${WRKSRC}/perl_ext
INSTALL_WRKSRC=	${WRKSRC}/perl_ext
PORTEXAMPLES=	*

USE_GITHUB=	yes
GH_ACCOUNT=	libming
GH_PROJECT=	libming

PORTSCOUT=	limit:^ming-

SHEBANG_FILES=	perl_ext/examples/*.cgi

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e '/ming_is_compiled()/ s|^|#|; /LIBS/d' ${WRKSRC}/perl_ext/Makefile.PL
	@${REINPLACE_CMD} -e 's|\.3pm|.3|g' ${WRKSRC}/perl_ext/Makefile.PL ${WRKSRC}/perl_ext/mkdoc
	@${REINPLACE_CMD} -e 's|GvCV(\(.*\)) = \(.*\);|GvCV_set(\1, \2);|' ${WRKSRC}/perl_ext/Exports.c

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/SWF/SWF.so

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/perl_ext/examples/*.cgi ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
