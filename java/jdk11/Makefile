# New ports collection makefile for:	jdk
# Date created:		Feb, 8, 1998
# Whom:			Nate Williams <nate@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jdk
PORTVERSION=	${JDK_VERSION}
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	nate/JDK1.1

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Java Development Kit 1.1

RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper

NO_CDROM=	"License doesn't allow distribution with fee"

ONLY_FOR_ARCHS=	i386
JDK_VERSION=	1.1.8
LATEST_LINK=	jdk11
PLIST_SUB+=	JDK_VERSION=${JDK_VERSION}

WRKSRC=		${WRKDIR}/jdk${JDK_VERSION}
NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "aout"
DISTFILES=	jdk${JDK_VERSION}_AOUT.V1999-11-9.tar.gz
.else
LIB_DEPENDS+=	c.3:${PORTSDIR}/misc/compat3x
DISTFILES=	jdk${JDK_VERSION}_ELF.V1999-11-9.tar.gz
.endif

post-patch:
	${FIND} ${WRKSRC} -name '*.orig' -delete

do-install:
	${MKDIR} ${PREFIX}/jdk${JDK_VERSION}
	cd ${WRKSRC} && ${FIND} . \
	   | ${CPIO} -pdmu -R ${LIBOWN}:${LIBGRP} ${PREFIX}/jdk${JDK_VERSION}
	${MKDIR} ${PREFIX}/share/java/classes
	${MKDIR} ${PREFIX}/share/doc/java

post-install:
	${LOCALBASE}/bin/registervm "${PREFIX}/jdk${JDK_VERSION}/bin/java # JDK${JDK_VERSION}"

.include <bsd.port.post.mk>
