# New ports collection makefile for:	jdk
# Version required:     1.1.7
# Date created:		Feb, 8, 1998
# Whom:			Nate Williams <nate@FReeBSD.org>
#
# $Id: Makefile,v 1.14 1998/08/19 14:56:37 nate Exp $
#

DISTNAME=	jdk1.1.7.V98-11-5
PKGNAME=	jdk-1.1.7
CATEGORIES=	lang devel
MASTER_SITES=	ftp://ftp.nuxi.com/pub/FreeBSD/JDK/ \
		http://www.freebsd.org/java/

MAINTAINER=	nate@freebsd.org

NO_CDROM=	"License doesn't allow distribution with fee"

WRKSRC=		${WRKDIR}/jdk1.1.7
NO_BUILD=       yes

do-install:
	${MKDIR} ${PREFIX}/jdk1.1.7
	(cd ${WRKSRC} && tar -c -f - --exclude '*.class' .) \
		| (cd ${PREFIX}/jdk1.1.7 && tar fx -)

.include <bsd.port.mk>
