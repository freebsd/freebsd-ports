PORTNAME=	mecab
PORTVERSION=	0.996
PORTREVISION=	3
CATEGORIES=	japanese textproc
MASTER_SITES=	https://drive.google.com/uc?export=download&id=0B4y35FiV1wh7cENtOXlicTFaRUE&dummy=/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet Another Part-of-Speech and Morphological Analyzer
WWW=		https://code.google.com/p/mecab/

LICENSE=	BSD3CLAUSE GPLv2 LGPL21
LICENSE_COMB=	multi

BROKEN_mips=		fails to link: Nonrepresentable section on output
BROKEN_mips64=		fails to link: Nonrepresentable section on output

USES=		gettext-tools iconv libtool localbase perl5
USE_LDCONFIG=	yes
USE_PERL5=	build

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	ac_cv_lib_stdcpp_main=no

INSTALL_TARGET=	install-strip

PORTDOCS=	AUTHORS README *.html

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400091
CPPFLAGS+=  -Dregister=
.endif

post-patch:
	@${REINPLACE_CMD} '/^libmecab_la_LIBADD =/s/$$/ $$(LTLIBICONV)/' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} \
		-e '/CFLAGS/s|-O3|${CFLAGS}|' \
		-e '/CXXFLAGS/s|-O3|${CXXFLAGS}|' \
		${WRKSRC}/configure
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400091
	@${REINPLACE_CMD} -e 's|std::binary_function|std::__binary_function|' \
		${WRKSRC}/src/dictionary.cpp
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:N*.html:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}
	${MV} ${STAGEDIR}${PREFIX}/etc/mecabrc \
		${STAGEDIR}${PREFIX}/etc/mecabrc.sample

.include <bsd.port.mk>
