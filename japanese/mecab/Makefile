PORTNAME=	mecab
DISTVERSION=	0.996
PORTREVISION=	5
CATEGORIES=	japanese textproc
MASTER_SITES=	https://drive.google.com/uc?export=download&id=1SJjk4IylQaO2yGc0vMtx5MHhZcjaeMLZ&dummy=/

MAINTAINER=	mce@FreeBSD.org
COMMENT=	Yet Another Part-of-Speech and Morphological Analyzer
WWW=		https://taku910.github.io/mecab/

LICENSE=	BSD3CLAUSE GPLv2 LGPL21
LICENSE_COMB=	multi

USES=		gettext-tools iconv libtool localbase perl5
USE_CXXSTD=	c++14
USE_LDCONFIG=	yes
USE_PERL5=	build

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	ac_cv_lib_stdcpp_main=no

INSTALL_TARGET=	install-strip

PORTDOCS=	AUTHORS README *.html

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} '/^libmecab_la_LIBADD =/s/$$/ $$(LTLIBICONV)/' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} \
		-e '/CFLAGS/s|-O3|${CFLAGS}|' \
		-e '/CXXFLAGS/s|-O3|${CXXFLAGS}|' \
		${WRKSRC}/configure

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/mecabrc \
		${STAGEDIR}${PREFIX}/etc/mecabrc.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:N*.html:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
