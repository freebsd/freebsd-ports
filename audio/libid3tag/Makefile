# Created by: Sergey Akifyev <asa@gascom.ru>

PORTNAME=	libid3tag
PORTVERSION=	0.15.1b
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF/mad/${PORTNAME}/${PORTVERSION} \
		ftp://ftp.mars.org/pub/mpeg/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ID3 tags library (part of MAD project)

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		cpe libtool pkgconfig
USE_LDCONFIG=	yes

CPE_VENDOR=	libid3tag_project

BUILD_DEPENDS=	gsed:textproc/gsed

post-patch:
	@${REINPLACE_CMD} -e '/genre.dat.in/s/sed -/g&/g' ${WRKSRC}/Makefile.in

pre-build:
	cd ${WRKSRC} && ${MAKE} ./genre.dat

post-build:
	cd ${WRKSRC} && CONFIG_FILES=id3tag.pc CONFIG_HEADERS= ${SH} ./config.status

post-install:
	${INSTALL_DATA} ${WRKSRC}/id3tag.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/

.include <bsd.port.mk>
