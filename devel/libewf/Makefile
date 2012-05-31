# New ports collection makefile for:	libewf
# Date created:		31 May 2012
# Whom:			MANTANI Nobutaka <nobutaka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libewf
PORTVERSION=	20120504
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}2/${PORTNAME}-${PORTVERSION}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	A library for support of the Expert Witness Compression Format (EWF)

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	uuid:${PORTSDIR}/misc/e2fsprogs-libuuid \
		fuse:${PORTSDIR}/sysutils/fusefs-libs
RUN_DEPENDS=	${LOCALBASE}/modules/fuse.ko:${PORTSDIR}/sysutils/fusefs-kmod

USE_GETTEXT=	yes
USE_ICONV=	yes
USE_LDCONFIG=	yes
USE_LIBTOOL=	yes
USE_OPENSSL=	yes
USE_PYTHON=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-python
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-D_FILE_OFFSET_BITS=64 -DFUSE_USE_VERSION=26

MAN1=		ewfacquire.1 ewfacquirestream.1 ewfexport.1 \
		ewfinfo.1 ewfmount.1 ewfverify.1
MAN3=		libewf.3

.include <bsd.port.mk>
