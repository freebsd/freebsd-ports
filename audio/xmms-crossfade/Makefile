# New ports collection makefile for:	xmms-crossfade
# Date created:			21 September 2000
# Whom:				Espen Skoglund <esk@ira.uka.de>
#
# $FreeBSD$
#

PORTNAME=	xmms-crossfade
PORTVERSION=	0.2.9
CATEGORIES=	audio
MASTER_SITES=	http://www.netcologne.de/~nc-eisenlpe2/xmms-crossfade/ \
		ftp://ftp.falsehope.com/pub/xmms-crossfade/

MAINTAINER=	pat@FreeBSD.org

LIB_DEPENDS=	xmms.3:${PORTSDIR}/audio/xmms

USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes
USE_GTK=	yes
INSTALLS_SHLIB=	yes

post-install:
.ifndef(NOPORTDOCS)
	@${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m ${SHAREMODE} \
		${PREFIX}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/${PORTNAME}
.endif # !NOPORTDOCS

.include <bsd.port.mk>
