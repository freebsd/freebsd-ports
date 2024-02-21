PORTNAME=	liboggz
PORTVERSION=	1.1.1
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	https://downloads.xiph.org/releases/liboggz/ \
		https://ftp.osuosl.org/pub/xiph/releases/liboggz/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple Ogg API
WWW=		https://www.annodex.net/software/liboggz/html/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libogg.so:audio/libogg

OPTIONS_DEFINE=	DOCS

CONFIGURE_ARGS=	--program-transform-name="" --with-ogg=${LOCALBASE}
CONFIGURE_ENV=	DOCBOOKTOMAN=false HAVE_DOCBOOK2HTML=false HAVE_DOXYGEN=false HAVE_DOXYGEN=false
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USES=		libtool pathfix pkgconfig

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e '/-= timezone;/d' ${WRKSRC}/src/tools/oggz-chop/httpdate.c ${WRKSRC}/src/tools/oggz-chop/httpdate_test.c

.include <bsd.port.mk>
