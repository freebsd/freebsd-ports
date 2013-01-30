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
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README README_windows.txt \
		designstyle.css gflags.html

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} \
		-e 's|^\(docdir = \).*|\1${DOCSDIR}|' \
		-e 's|^\(pkgconfigdir = \).*|\1$$(DESTDIR)$$(prefix)/libdata/pkgconfig|' \
			${WRKSRC}/Makefile.in
.if empty(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} -e '/^install-data-am: / s| install-dist_docDATA||' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
