# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libvshadow
PORTVERSION=	20140323
CATEGORIES=	devel
MASTER_SITES=	https://googledrive.com/host/0B3fBvzttpiiSZDZXRFVMdnZCeHc/ \
		LOCAL/antoine
DISTNAME=	${PORTNAME}-alpha-${PORTVERSION}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	A library to support the Volume Service Snapshot (VSS) format

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		fuse gettext iconv libtool pathfix pkgconfig
USE_PYTHON=	2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-python --with-libintl-prefix=${LOCALBASE} ${ICONV_CONFIGURE_ARG}
INSTALL_TARGET=	install-strip
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
