# New ports collection makefile for:	jdk
# Version required:     1.1.7
# Date created:		Feb, 8, 1998
# Whom:			Nate Williams <nate@FreeBSD.org>
#
# $Id: Makefile,v 1.18 1999/03/26 21:05:27 steve Exp $
#

DISTNAME=	jdk-1.1.7
CATEGORIES=	lang devel
#MASTER_SITES=	ftp://ftp.nuxi.com/pub/FreeBSD/JDK/ \
MASTER_SITES=		http://www.freebsd.org/java/

MAINTAINER=	nate@freebsd.org

NO_CDROM=	"License doesn't allow distribution with fee"

WRKSRC=		${WRKDIR}/jdk1.1.7
NO_BUILD=       yes

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "aout"
DISTFILES=	jdk1.1.7_AOUT.V99-4-16.tar.gz
.else
DISTFILES=	jdk1.1.7_ELF.V99-3-25.tar.gz
do-configure:
	@(cd ${WRKDIR}; sh ${FILESDIR}/dladdr-test.sh)
.endif

do-install:
	${MKDIR} ${PREFIX}/jdk1.1.7
	(cd ${WRKSRC} && tar -c -f - .) \
		| (cd ${PREFIX}/jdk1.1.7 && tar fx -)

.include <bsd.port.post.mk>
