# Created by: Fabian Keil <fk@fabiankeil.de>
# $FreeBSD$

PORTNAME=	liballium
PORTVERSION=	0.0.1
CATEGORIES=	devel security
MASTER_SITES=	GH
DISTNAME=	g-${GH_ACCOUNT}-${GH_PROJECT}-${PORTVERSION}-${GH_COMMIT}

MAINTAINER=	fk@fabiankeil.de
COMMENT=	Tor pluggable transports utility library

USE_GITHUB=	yes
GH_ACCOUNT=	Yawning
GH_COMMIT=	0c9b50f
GH_TAGNAME=	${GH_COMMIT}

GNU_CONFIGURE=	yes
USES=		libtool:build pkgconfig tar:bzip2 pathfix
USE_AUTOTOOLS=	autoconf aclocal automake
USE_LDCONFIG=	yes

PLIST_SUB+=	PKGNAME=${PKGNAME}

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -E -e "s@^(pkgconfigdir =) .*@\1 ${LOCALBASE}/libdata/pkgconfig@" \
		${WRKSRC}/Makefile.am

pre-configure:
	@(cd ${WRKSRC}; ./autogen.sh)

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
