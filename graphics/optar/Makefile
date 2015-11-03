# Created by: antonakis@gmail.com
# $FreeBSD$

PORTNAME=	optar
PORTVERSION=	1.0
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://ronja.twibright.com/
DISTFILES=	optar.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for encoding data on paper

LICENSE=	GPLv2

BROKEN=		Checksum and size mismatch
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26

LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png
RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick

WRKSRC=		${WRKDIR}/optar_dist

USES=		gmake

PLIST_FILES=	bin/optar bin/unoptar bin/pgm2ps

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CFLAGS|#CFLAGS| ; \
		 s|gcc |$$(CC) | ; \
		 s|-I/usr/local/include/libpng|`libpng-config --I_opts`| ; \
		 s|-L/usr/local/lib|`libpng-config --L_opts`|' \
		${WRKSRC}/Makefile

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} optar unoptar \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} pgm2ps \
		${STAGEDIR}${PREFIX}/bin)

.include <bsd.port.mk>
