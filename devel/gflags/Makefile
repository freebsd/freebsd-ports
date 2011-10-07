# New ports collection makefile for:	gflags
# Date created:				19 December 2006
# Whom:	      				Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gflags
PORTVERSION=	1.6
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	Commandline flags module for C++

PROJECTHOST=	google-gflags
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README README_windows.txt \
		designstyle.css gflags.html

post-patch:
	${REINPLACE_CMD} -e 's|\(pkgconfigdir = \).*|\1$$\(DESTDIR\)$$\(prefix\)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e 's|^docdir.*|docdir = ${DOCSDIR}|' ${WRKSRC}/Makefile.in
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e '/^install/s/ install-dist_docDATA//' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
