# Created by: Sergei Kolobov <sergei@kolobov.com>
# $FreeBSD$

PORTNAME=	execline
PORTVERSION=	2.2.0.0
CATEGORIES=	lang shells
MASTER_SITES=	http://www.skarnet.org/software/${PORTNAME}/

MAINTAINER=	colin-ports@heliocat.net
COMMENT=	Lightweight non-interactive sh(1)-like scripting language

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libskarnet.so:devel/skalibs

CONFLICTS_INSTALL=	ImageMagick-* # bin/import

USES=		gmake
USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-sysdeps=${LOCALBASE}/lib/skalibs/sysdeps \
		--with-lib=${LOCALBASE}/lib/skalibs \
		--with-dynlib=${LOCALBASE}/lib \
		--with-include=${LOCALBASE}/include \
		--enable-shared

DOCS=		AUTHORS README doc/*.html

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libexecline.so.${PORTVERSION}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_MAN} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
