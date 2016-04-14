# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	ming
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	0_4_7
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

OPTIONS_DEFINE=	EXAMPLES

PORTSCOUT=	limit:^ming-

CONFIGURE_ARGS=	--enable-perl
GNU_CONFIGURE=	yes
USES=		autoreconf bison gmake libtool localbase perl5 shebangfix
SHEBANG_FILES=	perl_ext/examples/*.cgi

BUILD_WRKSRC=	${WRKSRC}/perl_ext
INSTALL_WRKSRC=	${WRKSRC}/perl_ext
PORTEXAMPLES=	*

USE_GITHUB=	yes
GH_ACCOUNT=	lib${PORTNAME}
GH_PROJECT=	lib${PORTNAME}

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
