# $FreeBSD$

PORTNAME=	liboggz
DISTVERSION=	1.1.1
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/liboggz/ \
		http://wickedmachine.net/mirror/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple Ogg API

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libogg.so:audio/libogg

OPTIONS_DEFINE=	DOCS

CONFIGURE_ARGS=	--program-transform-name="" --with-ogg=${LOCALBASE}
CONFIGURE_ENV=	DOCBOOKTOMAN=false HAVE_DOCBOOK2HTML=false HAVE_DOXYGEN=false HAVE_DOXYGEN=false
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USES=		libtool pathfix pkgconfig

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e '/-= timezone;/d' ${WRKSRC}/src/tools/oggz-chop/httpdate.c ${WRKSRC}/src/tools/oggz-chop/httpdate_test.c

.include <bsd.port.mk>
