# New ports collection makefile for:	jdk
# Version required:     1.1.5
# Date created:		Feb, 8, 1998
# Whom:			Martin Cracauer <cracauer@cons.org>
#
# $Id: Makefile,v 1.12 1998/07/27 10:29:45 cracauer Exp $
#

DISTNAME=	jdk1.1.6.V98-7-21
PKGNAME=	jdk-1.1.6
CATEGORIES=	lang devel
MASTER_SITES=	http://www.freebsd.org/java/

MAINTAINER=	cracauer@freebsd.org

NO_CDROM=	"License doesn't allow distribution with fee"

WRKSRC=		${WRKDIR}/jdk1.1.6
NO_BUILD=       yes

do-install:
	${MKDIR} ${PREFIX}/java
	(cd ${WRKSRC} && tar -c -f - --exclude '*.class' --exclude \
		demo/ImageMap/audio/dialog .) \
		| (cd ${PREFIX}/java/. && tar fx -)
	${MKDIR} ${PREFIX}/java/demo/ImageMap/audio/dialog

.include <bsd.port.mk>
