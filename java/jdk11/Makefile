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

MAINTAINER=	nate@FreeBSD.org

RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper

NO_CDROM=	"License doesn't allow distribution with fee"

ONLY_FOR_ARCHS=	i386
JDK_VERSION=	1.1.8
PLIST_SUB+=	JDK_VERSION=${JDK_VERSION}

WRKSRC=		${WRKDIR}/jdk${JDK_VERSION}
NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "aout"
DISTFILES=	jdk${JDK_VERSION}_AOUT.V1999-11-9.tar.gz
.else
DISTFILES=	jdk${JDK_VERSION}_ELF.V1999-11-9.tar.gz
.endif

do-install:
	@${RM} -f ${WRKSRC}/include/freebsd/typedefs_md.h.orig
	${MKDIR} ${PREFIX}/jdk${JDK_VERSION}
	(cd ${WRKSRC} && ${TAR} -c -f - .) \
		| (cd ${PREFIX}/jdk${JDK_VERSION} && ${TAR} --unlink -x -f -)
	${MKDIR} ${PREFIX}/share/java/classes
	${MKDIR} ${PREFIX}/share/doc/java

post-install:
	${LOCALBASE}/bin/registervm "${PREFIX}/jdk${JDK_VERSION}/bin/java # JDK${JDK_VERSION}"
.if ${OSVERSION} > 400000
	${ECHO} "You will need to install the compat3x libraries to use this port."
.endif
  
.include <bsd.port.post.mk>
