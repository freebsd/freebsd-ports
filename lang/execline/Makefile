PORTNAME=	execline
DISTVERSION=	2.9.7.0
CATEGORIES=	lang shells
MASTER_SITES=	https://www.skarnet.org/software/${PORTNAME}/

MAINTAINER=	crest@rlwinm.de
COMMENT=	Lightweight non-interactive sh(1)-like scripting language
WWW=		https://www.skarnet.org/software/execline/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	skalibs>=2.14.4.0:devel/skalibs
LIB_DEPENDS=	libskarnet.so:devel/skalibs

USES=		gmake
USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-sysdeps=${LOCALBASE}/lib/skalibs/sysdeps \
		--with-lib=${LOCALBASE}/lib \
		--with-dynlib=${LOCALBASE}/lib \
		--with-include=${LOCALBASE}/include \
		--enable-shared

OPTIONS_DEFINE=	DOCS

DOCS=		AUTHORS README doc/*.html

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libexecline.so.${PORTVERSION}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
