# New ports collection makefile for:	xmms-crossfade
# Date created:			21 September 2000
# Whom:				Espen Skoglund <esk@ira.uka.de>
#
# $FreeBSD$
#

PORTNAME=	xmms-crossfade
PORTVERSION=	0.1.1
CATEGORIES=	audio
MASTER_SITES=	http://www.netcologne.de/~nc-eisenlpe2/xmms-crossfade/ \
		ftp://ftp.falsehope.com/pub/xmms-crossfade/

MAINTAINER=	esk@ira.uka.de

LIB_DEPENDS=	xmms.1:${PORTSDIR}/audio/xmms

USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes
USE_GTK=	yes

post-configure:
	${PERL} -pi.bak -e 's:linkopts=\Z:linkopts=-nostartfiles:' \
	  ${WRKSRC}/libtool

.include <bsd.port.mk>
