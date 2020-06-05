# $FreeBSD$

PORTNAME=		subread
DISTVERSION=		2.0.1
DISTVERSIONSUFFIX=	-source
CATEGORIES=		biology
MASTER_SITES=		SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	High-performance read alignment, quantification and mutation discovery

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${DISTNAME}/LICENSE

LIB_DEPENDS=	libsysinfo.so:devel/libsysinfo

USES=		gmake localbase:ldflags

MAKEFILE=	${FILESDIR}/Makefile.pkg
WRKSRC_SUBDIR=	src
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
