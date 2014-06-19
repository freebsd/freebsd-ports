# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libewf
PORTVERSION=	20140608
CATEGORIES=	devel
MASTER_SITES=	https://googledrive.com/host/0B3fBvzttpiiSMTdoaVExWWNsRjg/ \
		LOCAL/antoine

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Library for support of the Expert Witness Compression Format (EWF)

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid

USES=		fuse gettext iconv libtool:keepla pathfix pkgconfig
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
USE_PYTHON=	2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-python --with-libintl-prefix=${LOCALBASE} --with-libuuid=${LOCALBASE} ${ICONV_CONFIGURE_ARG} --with-libsmdev=no
INSTALL_TARGET=	install-strip

.include <bsd.port.pre.mk>

# posix_fadvise(2) did not return correct value on error
.if (${OSVERSION} >= 1100000 && ${OSVERSION} < 1100007) || (${OSVERSION} >= 1000000 && ${OSVERSION} < 1000703) || (${OSVERSION} < 902507)
CONFIGURE_ENV+=	ac_cv_func_posix_fadvise=no
.endif

.include <bsd.port.post.mk>
