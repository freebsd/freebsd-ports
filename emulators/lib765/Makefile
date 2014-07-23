# Created by: Alexey V. Antipovsky <kemm@in-line.ru>
# $FreeBSD$

PORTNAME=	lib765
PORTVERSION=	0.4.2
PORTREVISION=	1
CATEGORIES=	emulators devel
MASTER_SITES=	http://www.seasip.demon.co.uk/Unix/LibDsk/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emulation of uPD765a Floppy Disc Controller

LICENSE=	LGPL20

USES=		libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS LIBDSK
OPTIONS_DEFAULT=	LIBDSK

LIBDSK_DESC=	Include LibDSK support (recommended)
LIBDSK_CONFIGURE_ON=	--with-libdsk --with-libdsk-path=${LOCALBASE}
LIBDSK_CONFIGURE_OFF=	--without-libdsk
LIBDSK_LIB_DEPENDS=	libdsk.so:${PORTSDIR}/emulators/libdsk

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ChangeLog doc/765.txt ${STAGEDIR}${DOCSDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib765.so

.include <bsd.port.mk>
