# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	oniguruma
DISTVERSIONPREFIX=	v
DISTVERSION=	6.9.5_rev1
PORTREVISION=	1
CATEGORIES=	devel textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Regular expressions library compatible with POSIX/GNU/Perl

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=			autoreconf pathfix libtool  # configure provided in the tarball breaks: https://github.com/kkos/oniguruma/issues/73
USE_GITHUB=		yes
GH_ACCOUNT=		kkos
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--disable-static --enable-posix-api=yes
PATHFIX_MAKEFILEIN=	Makefile.am
USE_LDCONFIG=		yes
INSTALL_TARGET=		install-strip
TEST_WRKSRC=		${WRKSRC}/test
TEST_TARGET=		test

OPTIONS_DEFINE=			STATISTICS DOCS EXAMPLES
STATISTICS_DESC=		Take matching time statistical data (debug feature)

STATISTICS_CONFIGURE_WITH=	statistics

PORTDOCS=	*
PORTEXAMPLES=	*

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} HISTORY README ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} * ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/sample && ${INSTALL_DATA} *.c ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
