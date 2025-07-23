PORTNAME=	speexdsp
DISTVERSION=	1.2.1
CATEGORIES=	audio
MASTER_SITES=	http://downloads.us.xiph.org/releases/speex/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Audio compression format designed for speech
WWW=		https://www.speex.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		libtool
USE_LDCONFIG=	yes

.include <bsd.port.options.mk>

.if ${ARCH} == "aarch64"
CONFIGURE_ARGS+=--disable-neon
.endif

.include <bsd.port.mk>
