# New ports collection makefile for:	wmusic
# Date created:				16 September 2000
# Whom:					eric
#
# $FreeBSD$
#

PORTNAME=	wmusic
PORTVERSION=	1.4.9
CATEGORIES=	audio windowmaker
MASTER_SITES=	http://home.jtan.com/~john/wmusic/downloads/
DISTFILES=	${PORTNAME}-${PORTVERSION}-src${EXTRACT_SUFX}

MAINTAINER=	eric@FreeBSD.org

BUILD_DEPENDS=	xmms:${PORTSDIR}/audio/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/audio/xmms

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PATH_GTKCONFIG=${PREFIX}/bin/gtk12-config

USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_X_PREFIX=	yes
USE_XPM=	yes

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/wmusic ${PREFIX}/bin
.ifndef(NOPORTDOCS)
	@${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m ${SHAREMODE} \
		${PREFIX}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/${PORTNAME}
.endif

.include <bsd.port.mk>
