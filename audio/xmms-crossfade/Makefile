# New ports collection makefile for:	xmms-crossfade
# Date created:			21 September 2000
# Whom:				Espen Skoglund <esk@ira.uka.de>
#
# $FreeBSD$
#

PORTNAME=	xmms-crossfade
PORTVERSION=	0.3.8
CATEGORIES=	audio
MASTER_SITES=	http://www.eisenlohr.org/xmms-crossfade/

MAINTAINER=	pat@FreeBSD.org
COMMENT=	XMMS Output plugin for crossfading between songs

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

USE_X_PREFIX=	yes
USE_INC_LIBTOOL_VER=	13
USE_GMAKE=	yes
USE_GNOME=	gtk12
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes

pre-patch:
	${REINPLACE_CMD} "s|@libdir@|${PREFIX}/lib/xmms/Output|" \
		${WRKSRC}/Makefile.in

post-install:
.ifndef(NOPORTDOCS)
	@${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m ${SHAREMODE} \
		${PREFIX}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/${PORTNAME}
.endif # !NOPORTDOCS

.include <bsd.port.mk>
