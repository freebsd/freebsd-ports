# New ports collection makefile for:	wmusic
# Date created:				16 September 2000
# Whom:					eric
#
# $FreeBSD$
#

PORTNAME=	wmusic
PORTVERSION=	1.5.0
CATEGORIES=	audio windowmaker
MASTER_SITES=	http://home.jtan.com/~john/wmusic/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A remote control dockapp for xmms

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PATH_GTKCONFIG=${GTK_CONFIG}

MAN1=		wmusic.1
PORTDOCS=	README
PLIST_FILES=	bin/wmusic

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/wmusic ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/debian/wmusic.1 ${MANPREFIX}/man/man1
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
