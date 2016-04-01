# Created by: Kai Wang <kaiwang27@gmail.com>
# $FreeBSD$

PORTNAME=	frobtads
PORTVERSION=	1.2.3
CATEGORIES=	games lang
MASTER_SITES=	http://www.tads.org/${PORTNAME}/ \
		http://www.ifarchive.org/if-archive/programming/tads3/source/

MAINTAINER=	kaiwang27@gmail.com
COMMENT=	TADS interpreter and the compilers for both TADS 2 and 3

LIB_DEPENDS=	libcurl.so:ftp/curl

CONFLICTS=	tads-2.*

USES=		autoreconf execinfo gmake localbase ncurses
GNU_CONFIGURE=	yes

LIBS+=		-lcompat

.include <bsd.port.mk>
