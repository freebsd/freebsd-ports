# New ports collection makefile for:    ja-linux_locale
# Version required:	9.1
# Date created:         March 20 2000
# Whom:                 imura@FreeBSD.org
#
# $FreeBSD$
#

DISTNAME=	locale-ja-9-1.noarch
PKGNAME=	ja-linux_locale-9.1
CATEGORIES=	japanese emulators linux
MASTER_SITES=	ftp://ftp.linux.or.jp/pub/RPM/JRPM60/ALL/
EXTRACT_SUFX=	.rpm

MAINTAINER=	imura@FreeBSD.org

BUILD_DEPENDS=	rpm2cpio:${PORTSDIR}/misc/rpm
RUN_DEPENDS=	/compat/linux/etc/redhat-release:${PORTSDIR}/emulators/linux_base

PREFIX=		/compat/linux
NO_MTREE=	yes
NO_BUILD=	yes
EXTRACT_ONLY=	# none

do-install:
	cd ${PREFIX} \
	&& rpm2cpio ${DISTDIR}/${DISTNAME}.rpm | cpio -idv -R 0.0

.include <bsd.port.mk>
