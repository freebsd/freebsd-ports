# Created by: ijliao
# $FreeBSD$

PORTNAME=	pcre++
PORTVERSION=	0.9.5
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://www.daemon.de/idisk/Apps/pcre++/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Wrapper class around the pcre library

LICENSE=	LGPL21

LIB_DEPENDS=	libpcre.so:devel/pcre

USES=		gmake libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CPPFLAGS+=	$$(${PCRE_CONFIG} --cflags)
LDFLAGS+=	$$(${PCRE_CONFIG} --libs)

DOCSDIR=	${PREFIX}/share/doc/lib${PORTNAME}-${PORTVERSION}

PCRE_CONFIG?=	${LOCALBASE}/bin/pcre-config

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's| ../COPYING|| ; \
		 s| $$(prefix)/doc| $${DESTDIR}$$(prefix)/share/doc|' \
		${WRKSRC}/doc/Makefile.in
.for i in examples/Makefile.in libpcre++/Makefile.in test/Makefile.in
	@${REINPLACE_CMD} -e \
		's|-O -g|@CXXFLAGS@|' ${WRKSRC}/${i}
.endfor

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libpcre++.so.0

.include <bsd.port.mk>
