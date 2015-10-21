# Created by: Sergei Kolobov <sergei@kolobov.com>
# $FreeBSD$

PORTNAME=	execline
PORTVERSION=	2.1.4.2
CATEGORIES=	lang shells
MASTER_SITES=	http://www.skarnet.org/software/${PORTNAME}/

MAINTAINER=	colin@heliocat.net
COMMENT=	Lightweight non-interactive sh(1)-like scripting language

LICENSE=	ISCL

BUILD_DEPENDS=	skalibs>=2.3.8.0:${PORTSDIR}/devel/skalibs

CONFLICTS_INSTALL=	ImageMagick-* # bin/import

USES=		gmake
USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix=${PREFIX} \
		--with-sysdeps=${LOCALBASE}/lib/skalibs/sysdeps \
		--with-lib=${LOCALBASE}/lib/skalibs \
		--with-dynlib=${LOCALBASE}/lib \
		--with-include=${LOCALBASE}/include \
		--enable-shared

DOCS=		AUTHORS COPYING INSTALL README doc/*.html
OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libexecline.so.${PORTVERSION}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_MAN} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
