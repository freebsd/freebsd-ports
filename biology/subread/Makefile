PORTNAME=		subread
DISTVERSION=		2.1.0
DISTVERSIONSUFFIX=	-source
CATEGORIES=		biology
MASTER_SITES=		SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	High-performance read alignment, quantification and mutation discovery
WWW=		https://subread.sourceforge.net/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${DISTNAME}/LICENSE

LIB_DEPENDS=	libsysinfo.so:devel/libsysinfo

USES=		gmake localbase:ldflags

WRKSRC_SUBDIR=	src

MAKEFILE=	${FILESDIR}/Makefile.pkg
INSTALL_TARGET=	install-strip

CFLAGS+=	-fcommon

.include <bsd.port.mk>
