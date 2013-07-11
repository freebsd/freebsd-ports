# Created by: Kai Wang <kaiwang27@gmail.com>
# $FreeBSD$

PORTNAME=	frobtads
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	games lang
MASTER_SITES=	http://www.tads.org/${PORTNAME}/ \
		http://www.ifarchive.org/if-archive/programming/tads3/source/

MAINTAINER=	kaiwang27@gmail.com
COMMENT=	TADS interpreter and the compilers for both TADS 2 and 3

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		execinfo:${PORTSDIR}/devel/libexecinfo

CONFLICTS=	tads-2.*

USE_GMAKE=	yes
USE_AUTOTOOLS=	automake autoconf
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-lcompat"
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

pre-configure:
	(cd ${WRKSRC}; ${SH} bootstrap)

.include <bsd.port.mk>
