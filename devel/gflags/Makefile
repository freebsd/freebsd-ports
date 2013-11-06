# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gflags
PORTVERSION=	2.0
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Commandline flags module for C++

LICENSE=	BSD

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes
MAKE_ENV=	INSTALL_STRIP_FLAG=${STRIP}
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USES=		pathfix shebangfix

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README README_windows.txt \
		designstyle.css gflags.html

SHEBANG_FILES=	src/gflags_completions.sh

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|^\(docdir = \).*|\1${DOCSDIR}|' ${WRKSRC}/Makefile.in
.if !${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/^install-data-am: / s| install-dist_docDATA||' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
