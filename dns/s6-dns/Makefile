PORTNAME=	s6-dns
DISTVERSION=	2.4.1.1
CATEGORIES=	dns
MASTER_SITES=	http://www.skarnet.org/software/${PORTNAME}/

MAINTAINER=	crest@rlwinm.de
COMMENT=	Suite of DNS client programs and libraries for Unix systems
WWW=		https://www.skarnet.org/software/s6-dns/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	skalibs>=2.14.5.0:devel/skalibs
RUN_DEPENDS=	skalibs>=2.14.5.1:devel/skalibs
LIB_DEPENDS=	libskarnet.so:devel/skalibs

USES=		gmake
USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes

CFLAGS+=	-D__BSD_VISIBLE

CONFIGURE_ARGS+=--prefix=${PREFIX} \
	--with-include=${LOCALBASE}/include \
	--with-lib=${LOCALBASE}/lib \
	--with-lib=${LOCALBASE}/lib/execline \
	--with-lib=${LOCALBASE}/lib/s6 \
	--with-dynlib=${LOCALBASE}/lib \
	--disable-s6li \
	--livedir=${LIVEDIR} \
	--scandir=${SCANDIR} \
	--enable-shared

DOCS=		AUTHORS COPYING INSTALL README doc/*.html
OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
