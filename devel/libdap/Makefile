# New ports collection makefile for:	libdap
# Date created:				22 Feb, 2009
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libdap
PORTVERSION=	3.11.3
CATEGORIES=	devel
MASTER_SITES=	http://www.opendap.org/pub/source/ \
		LOCAL/sunpoet
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.sig
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	SDK which contains an implementation of DAP 2.0 and 3.1

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		uuid:${PORTSDIR}/misc/e2fsprogs-libuuid \
		xml2.5:${PORTSDIR}/textproc/libxml2

CFLAGS+=	${PTHREAD_CFLAGS}
CONFIGURE_ARGS=	--with-zlib=/usr
CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
USE_GMAKE=	yes
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes

MAN1=		dap-config.1 \
		getdap.1

post-patch:
	# do not alter ${PREFIX}/lib/charset.alias
	@${REINPLACE_CMD} -e '/^install-exec-am: / s|install-exec-local||' ${WRKSRC}/gl/Makefile.in

verify:	checksum
	gpg --verify ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}.sig

.include <bsd.port.mk>
