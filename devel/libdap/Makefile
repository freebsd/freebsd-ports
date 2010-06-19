# New ports collection makefile for:	libdap
# Date created:				22 Feb, 2009
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libdap
PORTVERSION=	3.10.2
CATEGORIES=	devel
MASTER_SITES=	http://www.opendap.org/pub/source/ \
		http://sunpoet.net/distfiles/

MAINTAINER=	sunpoet@sunpoet.net
COMMENT=	SDK which contains an implementation of DAP 2.0 and 3.1

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		uuid:${PORTSDIR}/misc/e2fsprogs-libuuid \
		xml2.5:${PORTSDIR}/textproc/libxml2

CFLAGS=		-I${LOCALBASE}/include -L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ARGS+=--with-zlib=/usr
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes

post-patch:
	# do not alter ${PREFIX}/lib/charset.alias
	@${REINPLACE_CMD} -e '/^install-exec-am: / s|install-exec-local||' ${WRKSRC}/gl/Makefile.in

.include <bsd.port.mk>
