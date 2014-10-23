# $FreeBSD$

PORTNAME=	liboggz
DISTVERSION=	1.1.1
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/liboggz/ \
		http://wickedmachine.net/mirror/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple Ogg API

OPTIONS_DEFINE=	DOCS

LIB_DEPENDS=	libogg.so:${PORTSDIR}/audio/libogg

USES=		pkgconfig pathfix libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ogg=${LOCALBASE} --program-transform-name=""
CONFIGURE_ENV=	HAVE_DOCBOOK2HTML=false DOCBOOKTOMAN=false HAVE_DOXYGEN=false HAVE_VALGRIND=false

# First REINPLACE_CMD line makes all timestimes relative to localtime, crude hack
post-patch:
	@${REINPLACE_CMD} -e 's/timezone/0/' \
		${WRKSRC}/src/tools/oggz-chop/httpdate.c \
		${WRKSRC}/src/tools/oggz-chop/httpdate_test.c

.include <bsd.port.mk>
