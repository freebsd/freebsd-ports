# New ports collection makefile for:	jdk
# Version required:     1.1.8
# Date created:		Feb, 8, 1998
# Whom:			Nate Williams <nate@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	jdk-${JDK_VERSION}
CATEGORIES=	java devel
#MASTER_SITES=	ftp://ftp.nuxi.com/pub/FreeBSD/JDK/ \
MASTER_SITES=		http://www.freebsd.org/java/

MAINTAINER=	nate@freebsd.org

NO_CDROM=	"License doesn't allow distribution with fee"

JDK_VERSION=	1.1.8
PLIST_SUB+=	JDK_VERSION=${JDK_VERSION}

WRKSRC=		${WRKDIR}/jdk${JDK_VERSION}
NO_BUILD=       yes

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "aout"
DISTFILES=	jdk${JDK_VERSION}_AOUT.V99-7-19.tar.gz
.else
DISTFILES=	jdk${JDK_VERSION}_ELF.V99-7-19.tar.gz
.endif

do-install:
	${MKDIR} ${PREFIX}/jdk${JDK_VERSION}
	(cd ${WRKSRC} && tar -c -f - .) \
		| (cd ${PREFIX}/jdk${JDK_VERSION} && tar fx -)

.include <bsd.port.post.mk>
