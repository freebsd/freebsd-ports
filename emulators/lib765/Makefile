# Created by: Alexey V. Antipovsky <kemm@in-line.ru>
# $FreeBSD$

PORTNAME=	lib765
PORTVERSION=	0.4.2
CATEGORIES=	emulators devel
MASTER_SITES=	http://www.seasip.demon.co.uk/Unix/LibDsk/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emulation of uPD765a Floppy Disc Controller

LICENSE=	LGPL20

USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS LIBDSK

LIBDSK_DESC=	Include LibDSK support (recommended)

OPTIONS_DEFAULT=	LIBDSK

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLIBDSK}
CONFIGURE_ARGS+=	--with-libdsk --with-libdsk-path=${LOCALBASE}
LIB_DEPENDS+=		dsk:${PORTSDIR}/emulators/libdsk
.else
CONFIGURE_ARGS+=	--without-libdsk
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ChangeLog doc/765.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
