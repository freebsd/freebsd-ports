PORTNAME=	vo-aacenc
PORTVERSION=	0.1.3
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/opencore-amr/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	VisualOn AAC encoder library
WWW=		https://sourceforge.net/projects/opencore-amr/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Obsolete AAC encoder library, consider using audio/fdk-aac or audio/exhale
EXPIRATION_DATE=2023-03-31

USES=		libtool
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -E -e \
	's|^pkgconfigdir = .*|pkgconfigdir = $$(prefix)/libdata/pkgconfig|g' \
	${WRKSRC}/Makefile.in

.include <bsd.port.mk>
