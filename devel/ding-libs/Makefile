# Created by: Andrew Elble <aweits@rit.edu>
# $FreeBSD$

PORTNAME=	ding-libs
DISTVERSION=	0.1.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://fedorahosted.org/released/${PORTNAME}/

MAINTAINER=	aweits@rit.edu
COMMENT=	Collection of useful libraries for developers

LICENSE=	GPLv3

GNU_CONFIGURE=	yes
CPPFLAGS=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

USES=		gettext libtool pkgconfig
USE_LDCONFIG=	yes

CONFIGURE_ENV+=	DOXYGEN=""

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS=	--docdir=${DOCSDIR}
.else
CONFIGURE_ARGS=	--docdir=/dev/null
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|libdir)/pkgconfig|prefix)/libdata/pkgconfig|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|g' ${WRKSRC}/collection/collection_tools.c \
		${WRKSRC}/refarray/ref_array.c
	@${REINPLACE_CMD} -e 's|if git log -1 &>/dev/null; then|if true; then|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
