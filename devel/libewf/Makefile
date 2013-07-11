# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libewf
PORTVERSION=	20130416
CATEGORIES=	devel
MASTER_SITES=	https://googledrive.com/host/0B3fBvzttpiiSMTdoaVExWWNsRjg/ \
		LOCAL/antoine

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	A library for support of the Expert Witness Compression Format (EWF)

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	uuid:${PORTSDIR}/misc/e2fsprogs-libuuid

USES=		fuse pathfix gettext iconv
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
USE_PYTHON=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-python
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		ewfacquire.1 ewfacquirestream.1 ewfexport.1 \
		ewfinfo.1 ewfmount.1 ewfrecover.1 ewfverify.1
MAN3=		libewf.3

.include <bsd.port.mk>
