PORTNAME=	gtmixer
PORTVERSION=	1.0.2
PORTREVISION=	3
CATEGORIES=	audio

MAINTAINER=	vagner@bsdway.ru
COMMENT=	GTK2.0 Sound Mixer
WWW=		https://github.com/svagner/gtmixer

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	svagner

USES=		gnome pkgconfig
USE_GNOME=	gtk20

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/gtmixer
	${CP} -r ${WRKSRC}/icons ${STAGEDIR}${PREFIX}/share/gtmixer/
	${INSTALL_MAN} ${WRKSRC}/gtmixer.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
