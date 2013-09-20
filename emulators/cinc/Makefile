# Created by: verm@drunkmonk.net
# $FreeBSD$

PORTNAME=	cinc
PORTVERSION=	2.1.3
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/OldFiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bell Laboratories cardiac computer emulator

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

PLIST_FILES=	bin/cinc \
		bin/casm

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} 's|-I-||g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
