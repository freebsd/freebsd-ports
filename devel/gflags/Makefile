# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gflags
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Commandline flags module for C++

LICENSE=	BSD3CLAUSE

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USES=		libtool pathfix shebangfix

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README README_windows.txt \
		designstyle.css gflags.html

SHEBANG_FILES=	src/gflags_completions.sh

post-patch:
	@${REINPLACE_CMD} -e '/^docdir = / s| = .*| = ${DOCSDIR}|' ${WRKSRC}/Makefile.in

regression-test test: build
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check

.include <bsd.port.mk>
