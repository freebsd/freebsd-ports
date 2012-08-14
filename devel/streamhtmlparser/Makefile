# New ports collection makefile for:	streamhtmlparser
# Date created:        7 August 2012
# Whom:                HU Dong <itechbear@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	streamhtmlparser
PORTVERSION=	0.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	itechbear@gmail.com
COMMENT=	C/C++/Python streaming HTML parser library from Google

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS+=--enable-shared

OPTIONS_DEFINE=	DOCS STATIC PYBINDINGS
PYBINDINGS_DESC=Install Python bindings
STATIC_DESC=	Install static library
OPTIONS_DEFAULT=STATIC

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYBINDINGS}
USE_PYTHON=	yes
CONFIGURE_ARGS+=--enable-python
CFLAGS+=	-I${PYTHON_INCLUDEDIR}
PLIST_SUB+=	PYBINDINGS=""
.else
CONFIGURE_ARGS+=--disable-python
PLIST_SUB+=	PYBINDINGS="@comment "
.endif

.if ${PORT_OPTIONS:MSTATIC}
CONFIGURE_ARGS+=--enable-static
PLIST_SUB+=	STATIC=""
.else
CONFIGURE_ARGS+=--disable-static
PLIST_SUB+=	STATIC="@comment "
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|^docdir.*|docdir = ${DOCSDIR}|' ${WRKSRC}/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -E -e '/^install-data-am/,/^$$/ s,install-dist_docDATA,,g' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.post.mk>
