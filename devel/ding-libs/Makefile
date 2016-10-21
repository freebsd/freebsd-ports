# Created by: Andrew Elble <aweits@rit.edu>
# $FreeBSD$

PORTNAME=	ding-libs
PORTVERSION=	0.5.0
CATEGORIES=	devel
MASTER_SITES=	https://fedorahosted.org/released/${PORTNAME}/

MAINTAINER=	aweits@rit.edu
COMMENT=	Collection of useful libraries for developers

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib ${ICONV_LIB} -lintl

USES=		autoreconf iconv gettext libtool pathfix pkgconfig
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ENV+=	DOXYGEN=""

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|g' ${WRKSRC}/collection/collection_tools.c \
		${WRKSRC}/refarray/ref_array.c
	@${REINPLACE_CMD} -e 's|git log -1 &>/dev/null|true|g' \
		${WRKSRC}/configure.ac

.include <bsd.port.mk>
