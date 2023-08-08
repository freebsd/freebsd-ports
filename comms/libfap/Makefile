PORTNAME=	libfap
PORTVERSION=	1.5
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.pakettiradio.net/downloads/libfap/${PORTVERSION}/ \
		LOCAL/db

MAINTAINER=	akh@nobugware.com
COMMENT=	C port for Ham::APRS::FAP Finnish APRS Parser Perl module
WWW=		https://www.pakettiradio.net/libfap/

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool
USE_LDCONFIG=	yes

HAS_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

.include <bsd.port.post.mk>
