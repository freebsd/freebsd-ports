PORTNAME=	liboggz
PORTVERSION=	1.1.3
CATEGORIES=	audio
MASTER_SITES=	https://ftp.osuosl.org/pub/xiph/releases/liboggz/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple Ogg API
WWW=		https://www.xiph.org/oggz/ \
		https://gitlab.xiph.org/xiph/liboggz

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libogg.so:audio/libogg

USES=		libtool pkgconfig

CONFIGURE_ARGS=	--program-transform-name="" --with-ogg=${LOCALBASE}
CONFIGURE_ENV=	DOCBOOKTOMAN=false HAVE_DOCBOOK2HTML=false HAVE_DOXYGEN=false HAVE_DOXYGEN=false
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

post-install:
	@${RMDIR} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
