# New ports collection makefile for:	linux jdk 1.2.2
# Date created:		Nov 3 1999
# Whom:			Jose Marques
#
# $FreeBSD$
#

PORTNAME=	jdk
PORTVERSION=	1.2.2
CATEGORIES=	java devel
MASTER_SITES=	ftp://ftp.tux.org/pub/java/JDK-1.2.2/i386/rc4/ \
		http://www.metaverse.nl/~ernst/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	znerd
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-${PORTVERSION}-RC4-linux-i386-glibc-2.1.2

MAINTAINER=	znerd@FreeBSD.org

RUN_DEPENDS=	/compat/linux/lib/ld.so:${PORTSDIR}/emulators/linux_base \
		javavm:${PORTSDIR}/java/javavmwrapper

NO_CDROM=	"License doesn\'t allow distribution with fee"
NO_PACKAGE=	"License doesn\'t allow binary distributions"

USE_LINUX=	YES
ONLY_FOR_ARCHS=	i386

USE_BZIP2=	YES
WRKSRC=		${WRKDIR}/jdk1.2.2
NO_BUILD=	YES

do-install:
	${MKDIR} ${PREFIX}/linux-jdk1.2.2
	(cd ${WRKSRC} && tar --exclude "*.orig" -c -f - .) \
		| (cd ${PREFIX}/linux-jdk1.2.2 && tar fx -)
	${LOCALBASE}/bin/registervm "${PREFIX}/linux-jdk1.2.2/bin/java # Linux-JDK1.2.2"

.include <bsd.port.mk>
