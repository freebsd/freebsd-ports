# Created by: Dean Hollister <dean@odyssey.apana.org.au>
# $FreeBSD$

PORTNAME=	firedns
PORTVERSION=	0.9.12
CATEGORIES=	dns devel
MASTER_SITES=	https://BSDforge.com/projects/source/dns/firedns/ \
		http://www.firestuff.org/projects/ \
		http://www.wa.apana.org.au/~dean/sources/ \
		ftp://ftp.wa.apana.org.au/pub/pc/unix/packages/

MAINTAINER=	dean@odyssey.apana.org.au
COMMENT=	C library for handling asynchronous DNS queries

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/GPL

BUILD_DEPENDS=	${LOCALBASE}/include/firestring.h:misc/firestring

USES=		tar:bzip2
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

pre-configure:
	@-${RM} ${WRKSRC}/firemake/*.orig

.include <bsd.port.mk>
