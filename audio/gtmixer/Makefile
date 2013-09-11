# Created by: Putrya Statislav
# $FreeBSD$

PORTNAME=	gtmixer
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	vagner@bsdway.ru
COMMENT=	GTK2.0 Sound Mixer

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	svagner
GH_COMMIT=	9e22be7

USES=		pkgconfig
USE_GNOME=	gtk20

MAN1=	gtmixer.1

do-install:
	@${MKDIR} ${PREFIX}/share/gtmixer
	${CP} -r ${WRKSRC}/icons ${PREFIX}/share/gtmixer/
	${INSTALL_MAN} ${WRKSRC}/gtmixer.1 ${MAN1PREFIX}/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
