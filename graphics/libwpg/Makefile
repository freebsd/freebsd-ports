# $FreeBSD$

PORTNAME=	libwpg
PORTVERSION=	0.2.2
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library and tools to work with WordPerfect Graphics (WPG) files

DEPRECATED=	Not used any more
EXPIRATION_DATE=2016-03-26

LICENSE=	LGPL21 MPL
LICENSE_COMB=	dual

LIB_DEPENDS=	libwpd-0.9.so:${PORTSDIR}/textproc/libwpd

USES=		libtool:keepla pathfix perl5 pkgconfig shebangfix tar:bzip2
SHEBANG_FILES=	${WRKSRC}/src/conv/svg/wpg2svgbatch.pl
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--disable-werror --without-docs

post-stage:
	@${RM} ${STAGEDIR}${PREFIX}/bin/wp*

.include <bsd.port.mk>
