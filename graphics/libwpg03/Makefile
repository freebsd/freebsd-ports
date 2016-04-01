# $FreeBSD$

PORTNAME=	libwpg
PORTVERSION=	0.3.1
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMESUFFIX=	03

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library and tools to work with WordPerfect Graphics (WPG) files

LICENSE=	LGPL21 MPL
LICENSE_COMB=	dual

LIB_DEPENDS=	librevenge-0.0.so:textproc/librevenge \
		libwpd-0.10.so:textproc/libwpd010

USES=		libtool pathfix perl5 pkgconfig shebangfix tar:bzip2
SHEBANG_FILES=	${WRKSRC}/src/conv/svg/wpg2svgbatch.pl
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--disable-werror --without-docs

.include <bsd.port.mk>
