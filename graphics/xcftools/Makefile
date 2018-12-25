# $FreeBSD$

PORTNAME=	xcftools
PORTVERSION=	1.0.8.20130212
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://freeheimdall.spdns.org/files/

MAINTAINER=	kalten@gmx.at
COMMENT=	Command-line tools for extracting from XCF format (graphics/gimp)

LIB_DEPENDS=	libpng.so:graphics/png

# xcftools is under a public domain licence

USE_GITHUB=	yes
GH_ACCOUNT=	j-jorge
GH_TAGNAME=	d72ba82

# option NLS (for gettext) is wrong as this port allways needs NLS:
USES=	libtool cmake:insource,noninja gmake iconv pkgconfig perl5 gettext
USE_PERL5=	build run
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	preinstall

# manual pages not built but there is -h for each program.
# regression tests (TESTS option) fail

PORTDOCS=	ChangeLog README TRANSLATION
PLIST_FILES=	bin/xcf2png \
		bin/xcf2pnm \
		bin/xcfinfo \
		bin/xcfview

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS TESTS
TESTS_DESC=	Run self-tests (faulty) (pulls in graphics/netpbm shells/bash)

TEST_BUILD_DEPENDS=	pngtopnm:graphics/netpbm \
			bash:shells/bash

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e "s|^#! \(/bin/bash\)|#!${PREFIX}\1|" \
		${WRKSRC}/test/dotest
	@${REINPLACE_CMD} -e "s|perl|${PERL}|" \
		${WRKSRC}/test/dotest
	@${REINPLACE_CMD} -e "s|^#! /usr/bin/perl|#!${PERL}|" \
		${WRKSRC}/xcfview \
		${WRKSRC}/mancombine.pl \
		${WRKSRC}/manpo/mantranslate.pl \
		${WRKSRC}/manpo/optipot.pl \
		${WRKSRC}/mkenumsc.pl \
		${WRKSRC}/mkenumsh.pl \
		${WRKSRC}/mkopti.pl \
		${WRKSRC}/mktablec.pl

test:
.if ${PORT_OPTIONS:MTESTS}
	cd ${WRKSRC}/test && \
		${SETENV} ${MAKE_ENV} limits -m 20m ${GMAKE} check
.endif

post-build: test

post-install:
	${STRIP_CMD} ${WRKSRC}/bin/xcf2png ${WRKSRC}/bin/xcf2pnm \
		${WRKSRC}/bin/xcfinfo
	${INSTALL_SCRIPT} ${WRKSRC}/bin/xcf2png ${WRKSRC}/bin/xcf2pnm \
		${WRKSRC}/bin/xcfinfo ${WRKSRC}/xcfview \
		${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
