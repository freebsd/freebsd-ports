# New ports collection makefile for:	jdk
# Version required:     1.1.8
# Date created:		Feb, 8, 1998
# Whom:			Nate Williams <nate@FreeBSD.org>
#
# $Id: Makefile,v 1.19 1999/04/16 19:53:30 nate Exp $
#

DISTNAME=	jdk-1.1.8
CATEGORIES=	lang devel
#MASTER_SITES=	ftp://ftp.nuxi.com/pub/FreeBSD/JDK/ \
MASTER_SITES=		http://www.freebsd.org/java/

MAINTAINER=	nate@freebsd.org

NO_CDROM=	"License doesn't allow distribution with fee"

WRKSRC=		${WRKDIR}/jdk1.1.8
NO_BUILD=       yes

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "aout"
DISTFILES=	jdk1.1.8_AOUT.V99-6-3.tar.gz
.else
DISTFILES=	jdk1.1.8_ELF.V99-6-3.tar.gz
.endif

do-install:
	${MKDIR} ${PREFIX}/jdk1.1.8
	(cd ${WRKSRC} && tar -c -f - .) \
		| (cd ${PREFIX}/jdk1.1.8 && tar fx -)

.include <bsd.port.post.mk>
