# New ports collection makefile for:	jdk
# Date created:		Feb, 8, 1998
# Whom:			Nate Williams <nate@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jdk
PORTVERSION=	${JDK_VERSION}
CATEGORIES=	java devel
MASTER_SITES=	ftp://ftp.sc.sri.com/pub/FreeBSD/JDK/ \
		http://www.freebsd.org/java/

MAINTAINER=	nate@FreeBSD.org

NO_CDROM=	"License doesn't allow distribution with fee"

ONLY_FOR_ARCHS=	i386
JDK_VERSION=	1.1.8
PLIST_SUB+=	JDK_VERSION=${JDK_VERSION}

WRKSRC=		${WRKDIR}/jdk${JDK_VERSION}
NO_BUILD=       yes

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "aout"
DISTFILES=	jdk${JDK_VERSION}_AOUT.V1999-11-9.tar.gz
.else
DISTFILES=	jdk${JDK_VERSION}_ELF.V1999-11-9.tar.gz
.endif

do-install:
	${MKDIR} ${PREFIX}/jdk${JDK_VERSION}
	(cd ${WRKSRC} && ${TAR} -c -f - .) \
		| (cd ${PREFIX}/jdk${JDK_VERSION} && ${TAR} --unlink -x -f -)
	${MKDIR} ${PREFIX}/share/java/classes
	${MKDIR} ${PREFIX}/share/doc/java

.include <bsd.port.post.mk>
