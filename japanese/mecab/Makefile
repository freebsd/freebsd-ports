# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	mecab
PORTVERSION=	0.996
PORTREVISION=	1
CATEGORIES=	japanese textproc
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	yasu@utahime.org
COMMENT=	Yet Another Part-of-Speech and Morphological Analyzer

LICENSE=	BSD3CLAUSE GPLv2 LGPL21
LICENSE_COMB=	multi

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	ac_cv_lib_stdcpp_main=no
INSTALL_TARGET=	install-strip
USES=		iconv gettext:build libtool perl5
USE_AUTOTOOLS=	autoconf autoheader automake aclocal libtoolize
AUTOMAKE_ARGS=	--add-missing --copy --force
USE_PERL5=	build
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

PORTDOCS=	AUTHORS README *.html

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e 's/-O3/${CFLAGS}/' ${WRKSRC}/${CONFIGURE_SCRIPT}.in
	${REINPLACE_CMD} -e 's/conf_DATA = mecabrc/conf_DATA = mecabrc.dist/' ${WRKSRC}/Makefile.am

post-configure:
	${CP} ${WRKSRC}/mecabrc ${WRKSRC}/mecabrc.dist

pre-install:
	${CHMOD} a+x ${WRKSRC}/install-sh

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:N*.html:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
