# New ports collection makefile for:	linux jdk 1.2.2
# Date created:		Nov 3 1999
# Whom:			Jose Marques
#
# $FreeBSD$
#

PORTNAME=	jdk
PORTVERSION=	1.2.2
CATEGORIES=	java devel
MASTER_SITES=	ftp://iodynamics.com/pub/mirror/linux-jdk/JDK-1.2.2/i386/rc4/ \
		ftp://ftp.tux.org/pub/java/JDK-1.2.2/i386/rc4/
PKGNAMEPREFIX=	linux-
DISTNAME=	jdk-1.2.2-RC4-linux-i386-glibc-2.1.2

MAINTAINER=	K.J.Koster@kpn.com

RUN_DEPENDS=	/compat/linux/usr/i486-linux-libc5/lib/libc.so.5:${PORTSDIR}/emulators/linux_base \
		javavm:${PORTSDIR}/java/javavmwrapper

NO_CDROM=	"License doesn\'t allow distribution with fee"
NO_PACKAGE=	"License doesn\'t allow binary distributions"

ONLY_FOR_ARCHS=	i386

USE_BZIP2=	YES
WRKSRC=		${WRKDIR}/jdk1.2.2
NO_BUILD=	yes

do-install:
	${MKDIR} ${PREFIX}/linux-jdk1.2.2
	(cd ${WRKSRC} && tar --exclude "*.orig" -c -f - .) \
		| (cd ${PREFIX}/linux-jdk1.2.2 && tar fx -)
	${LOCALBASE}/bin/registervm "${PREFIX}/linux-jdk1.2.2/bin/java # Linux-JDK1.2.2"

.include <bsd.port.mk>
