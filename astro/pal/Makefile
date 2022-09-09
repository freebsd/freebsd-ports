PORTNAME=	pal
DISTVERSION=	0.9.8
CATEGORIES=	astro
MASTER_SITES=	https://github.com/Starlink/pal/releases/download/v${DISTVERSION}/
PKGNAMESUFFIX=	-astronomical

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Positional Astronomy Library
WWW=		https://github.com/Starlink/pal

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	liberfa.so:astro/erfa

USES=		gmake libtool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

PLIST_FILES=	include/star/pal.h \
		include/star/palmac.h \
		lib/libpal.a \
		lib/libpal.so \
		lib/libpal.so.0 \
		lib/libpal.so.0.0.0

post-install: # remove manifest file that contains stage dir, news and docs directories, and datadir with licenses
	@${RM} -r \
		${STAGEDIR}${PREFIX}/manifests \
		${STAGEDIR}${PREFIX}/news \
		${STAGEDIR}${PREFIX}/docs \
		${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
