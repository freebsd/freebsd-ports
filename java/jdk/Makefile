# New ports collection makefile for:	jdk
# Version required:     1.1.8
# Date created:		Feb, 8, 1998
# Whom:			Nate Williams <nate@FreeBSD.org>
#
# $Id: Makefile,v 1.21 1999/06/08 21:57:38 steve Exp $
#

DISTNAME=	jdk-${JDK_VERSION}
CATEGORIES=	lang devel
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
NETPATCH=	AOUT.netpatch.tar.gz
DISTFILES=	jdk${JDK_VERSION}_AOUT.V99-6-3.tar.gz ${NETPATCH}
EXTRACT_ONLY=	jdk${JDK_VERSION}_AOUT.V99-6-3.tar.gz
.else
NETPATCH=	ELF.netpatch.tar.gz
DISTFILES=	jdk${JDK_VERSION}_ELF.V99-6-3.tar.gz ${NETPATCH}
EXTRACT_ONLY=	jdk${JDK_VERSION}_ELF.V99-6-3.tar.gz
.endif

do-install:
	${MKDIR} ${PREFIX}/jdk${JDK_VERSION}
	(cd ${WRKSRC} && tar -c -f - .) \
		| (cd ${PREFIX}/jdk${JDK_VERSION} && tar fx -)

post-install:
	tar xzf ${DISTDIR}/${NETPATCH} -C ${PREFIX}

.include <bsd.port.post.mk>
