# New ports collection makefile for:	linux-allegro
# Date created:				18 Nov 2003
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	allegro
PORTVERSION=	4.0.3
CATEGORIES=	devel linux
MASTER_SITES=	http://membres.lycos.fr/ebotcazou/allegro/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-${PORTVERSION}-1.${MACHINE_ARCH}
EXTRACT_SUFX=	.rpm
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross-platform game programming library (linux version)

USE_LINUX_PREFIX=	yes
LDCONFIG_LINUX=	${LINUXBASE}/sbin/ldconfig

ONLY_FOR_ARCHS=	i386
DIST_SUBDIR=	rpm
NO_BUILD=	yes
NO_FILTER_SHLIBS=	yes

DBPATH=		/var/lib/rpm
RPMFLAGS=	--ignoreos --root ${PREFIX} --dbpath ${DBPATH} \
		--nodeps --replacepkgs
RPMDIR=		${DISTDIR}/${DIST_SUBDIR}

do-install:
	@${PREFIX}/bin/rpm -U ${RPMFLAGS} ${RPMDIR}/${DISTFILES}
	@${LDCONFIG_LINUX}
	@${RMDIR} ${PREFIX}/var/tmp

.include <bsd.port.mk>
