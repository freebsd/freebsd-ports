# New ports collection makefile for:	wmusic
# Date created:				16 September 2000
# Whom:					eric
#
# $FreeBSD$
#

PORTNAME=	wmusic
PORTVERSION=	1.4.12
CATEGORIES=	audio windowmaker
MASTER_SITES=	http://home.jtan.com/~john/wmusic/downloads/
EXTRACT_SUFX=	-src.tar.gz

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

post-extract:
	-${RM} -f ${WRKSRC}/config.cache

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/wmusic ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/debian/wmusic.1 ${MANPREFIX}/man/man1
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
