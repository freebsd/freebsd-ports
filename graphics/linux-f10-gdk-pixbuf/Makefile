# New ports collection makefile for:	linux-gdk-pixbuf
# Date created:		23 December 2003
# Whom:			Seth Kingsley <sethk@meowfishies.com>
#
# $FreeBSD$
#

PORTNAME=	gdk-pixbuf
PORTVERSION=	0.8.0.7
PORTREVISION=	1
CATEGORIES=	graphics linux
MASTER_SITES=	${MASTER_SITE_REDHAT_LINUX}
MASTER_SITE_SUBDIR=	${BASEVERSION}/${LANG}/os/${MACHINE_ARCH}/RedHat/RPMS
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.([^\.]+)$/-\1/}.${MACHINE_ARCH}
EXTRACT_SUFX=	.rpm
EXTRACT_ONLY=

MAINTAINER=	sethk@meowfishies.com
COMMENT=	Linux version of the graphic library for GTK+

BUILD_DEPENDS=	rpm:${PORTSDIR}/archivers/rpm

USE_LINUX_PREFIX=	yes
ONLY_FOR_ARCHS=	alpha i386
DIST_SUBDIR=	rpm
NO_BUILD=	yes
NO_FILTER_SHLIBS=	yes
PLIST=		${PKGDIR}/pkg-plist.${MACHINE_ARCH}
PLIST_SUB=	VERSION=${PORTVERSION:C/^(.+)\.[^\.]+$/\1/}
MD5_FILE=	${MASTERDIR}/distinfo.${MACHINE_ARCH}

# Let's avoid hardcoding 'en' as the language.
LANG=		en
# Set the version of linux_base
BASEVERSION?=	7.1
RPMFLAGS=	--ignoreos --root ${PREFIX} --dbpath /var/lib/rpm \
		--nodeps --replacepkgs

do-install:
	@for rpm in ${DISTFILES}; do\
		${ECHO_MSG} $$rpm;\
		rpm -U ${RPMFLAGS} ${DISTDIR}/${DIST_SUBDIR}/$$rpm || true;\
	done

.include <bsd.port.mk>
