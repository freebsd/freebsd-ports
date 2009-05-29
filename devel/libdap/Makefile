# New ports collection makefile for:	libdap
# Date created:				22 Feb, 2009
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libdap
PORTVERSION=	3.9.3
CATEGORIES=	devel
MASTER_SITES=	http://www.opendap.org/pub/source/

MAINTAINER=	wenheping@gmail.com
COMMENT=	SDK which contains an implementation of DAP 2.0 and 3.1

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		xml2.5:${PORTSDIR}/textproc/libxml2

CFLAGS=		-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e \
	's#$(libdir)/pkgconfig#$(libdir)/libdata/pkgconfig#g' \
	${WRKSRC}/Makefile.in

.include <bsd.port.mk>
