PORTNAME=	gumbo
PORTVERSION=	0.12.1
CATEGORIES=	devel textproc
MASTER_SITES=	https://codeberg.org/grisha/gumbo-parser/archive/${PORTVERSION}${EXTRACT_SUFX}?dummy/

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Pure-C HTML5 parser
WWW=		https://codeberg.org/grisha/gumbo-parser

LICENSE=	APACHE20

USES=		autoreconf gmake pathfix libtool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

post-extract:
	${MV} ${WRKDIR}/gumbo-parser ${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgumbo.so.2.0.1

.include <bsd.port.mk>
