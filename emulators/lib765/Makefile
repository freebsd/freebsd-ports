# Created by: Alexey V. Antipovsky <kemm@in-line.ru>
# $FreeBSD$

PORTNAME=	lib765
PORTVERSION=	0.4.2
PORTREVISION=	2
CATEGORIES=	emulators devel
MASTER_SITES=	http://www.seasip.demon.co.uk/Unix/LibDsk/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emulation of uPD765a Floppy Disc Controller

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/doc/COPYING.LIB

USES=		libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS LIBDSK
OPTIONS_DEFAULT=	LIBDSK

LIBDSK_DESC=	Include LibDSK support (recommended)
LIBDSK_CONFIGURE_ON=	--with-libdsk --with-libdsk-path=${LOCALBASE}
LIBDSK_CONFIGURE_OFF=	--without-libdsk
LIBDSK_LIB_DEPENDS=	libdsk.so:emulators/libdsk

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib765.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ChangeLog doc/765.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
