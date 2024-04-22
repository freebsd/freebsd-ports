PORTNAME=	firedns
PORTVERSION=	0.9.12
PORTREVISION=	1
CATEGORIES=	dns devel
MASTER_SITES=	https://BSDforge.com/projects/source/dns/firedns/ \
		http://www.firestuff.org/projects/ \
		http://www.wa.apana.org.au/~dean/sources/ \
		ftp://ftp.wa.apana.org.au/pub/pc/unix/packages/

MAINTAINER=	dean@odyssey.apana.org.au
COMMENT=	C library for handling asynchronous DNS queries
WWW=		https://www.firestuff.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/GPL

DEPRECATED=	Abandonware, upstream is gone and last release in 2004 and it also depends on unfetchable misc/firestring. Consider dns/c-ares
EXPIRATION_DATE=2024-04-30

BUILD_DEPENDS=	${LOCALBASE}/include/firestring.h:misc/firestring

USES=		tar:bzip2
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	MANDIR="${PREFIX}/share/man"
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

pre-configure:
	@-${RM} ${WRKSRC}/firemake/*.orig

.include <bsd.port.mk>
