# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	mecab
PORTVERSION=	0.996
CATEGORIES=	japanese textproc
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	yasu@utahime.org
COMMENT=	Yet Another Part-of-Speech and Morphological Analyzer

LICENSE=	BSD3CLAUSE GPLv2 LGPL21
LICENSE_COMB=	multi

USE_AUTOTOOLS=	autoconf autoheader automake aclocal libtool
USES=		iconv gettext:build perl5
USE_PERL5=	build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV+=	ac_cv_lib_stdcpp_main=no

CPPFLAGS+=	${PTHREAD_CFLAGS} -I ${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

ACLOCAL_ARGS=	--system-acdir=${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	--add-missing

PORTDOCS=	AUTHORS README *.html

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e 's/-lpthread/${PTHREAD_LIBS}/g' \
			 -e 's/-O3/${CFLAGS}/' ${WRKSRC}/${CONFIGURE_SCRIPT}.in
	${REINPLACE_CMD} -e 's/conf_DATA = mecabrc/conf_DATA = mecabrc.dist/' ${WRKSRC}/Makefile.am

post-configure:
	${CP} ${WRKSRC}/mecabrc ${WRKSRC}/mecabrc.dist

pre-install:
	${CHMOD} a+x ${WRKSRC}/install-sh

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:N*.html:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmecab.so

.include <bsd.port.mk>
