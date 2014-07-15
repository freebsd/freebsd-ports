# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	glog
PORTVERSION=	0.3.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Library of C++ classes for flexible logging

LIB_DEPENDS=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo \
		libgflags.so:${PORTSDIR}/devel/gflags

GNU_CONFIGURE=	yes
USES=		pathfix libtool:keepla
USE_LDCONFIG=	yes
PROJECTHOST=	google-glog

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lexecinfo

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|^docdir.*|docdir = ${DOCSDIR}|' ${WRKSRC}/Makefile.in
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -E -e '/^install-data-am/,/^$$/ s,install-(dist_doc|dist_html|html)DATA,,g' \
	    ${WRKSRC}/Makefile.in
.endif

regression-test:
	cd ${WRKSRC}; ${MAKE} check

.include <bsd.port.post.mk>
