# Created by: Putrya Statislav
# $FreeBSD$

PORTNAME=	gtmixer
PORTVERSION=	1.0.2
CATEGORIES=	audio
MASTER_SITES=	http://github.com/svagner/gtmixer/archive/
DISTNAME=	${PORTVERSION}

MAINTAINER=	vagner@bsdway.ru
COMMENT=	GTK2.0 Sound Mixer

LICENSE=	BSD

USE_GNOME=	gtk20
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
FETCH_ARGS=	-Fpr

MAN1=	gtmixer.1

do-install:
	@${MKDIR} ${PREFIX}/share/gtmixer
	@${CP} -r ${WRKSRC}/icons ${PREFIX}/share/gtmixer/
	@${INSTALL_MAN} ${WRKSRC}/gtmixer.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
