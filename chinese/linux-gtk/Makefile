# New ports collection makefile for: zh-linux-gtk
# Date created:         25 Oct 2000
# Whom:                 Jing-Tang Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	linux-gtk
PORTVERSION=	1.2.6
PORTREVISION=	1
CATEGORIES?=	chinese x11-toolkits linux
MASTER_SITES=	ftp://cle.linux.org.tw/pub/CLE/stable/v0.9p1/i386/RedHat/RPMS/ \
		ftp://freebsd.sinica.edu.tw/pub/keith/zh-rpm/
DISTFILES=	gtk+-1.2.6-7CLE.i386.rpm

MAINTAINER=	ports@FreeBSD.org
COMMENT=	RPM of the Gtk lib, zh-Big5/GB-ized

BUILD_DEPENDS=	rpm:${PORTSDIR}/archivers/rpm
RUN_DEPENDS=	/compat/linux/CLE-0.9p1:${PORTSDIR}/chinese/cle_base

DIST_SUBDIR=	zh-rpm
EXTRACT_ONLY=
NO_BUILD=	yes
NO_FILTER_SHLIBS=	yes
NO_MTREE=	yes
ONLY_FOR_ARCHS=	i386
PREFIX=		/compat/linux

DBPATH=		/var/lib/rpm
RPMFLAGS=	--ignoreos --root ${PREFIX} --dbpath ${DBPATH} \
		--nodeps --replacepkgs
RPMDIR=		${DISTDIR}/${DIST_SUBDIR}

REMOVE_DIRS=	/usr/share/themes/Default /usr/share/themes \
		/usr/share/locale/wa/LC_MESSAGES /usr/share/locale/wa \
		/usr/share/locale/uk/LC_MESSAGES /usr/share/locale/uk \
		/usr/share/locale/ro/LC_MESSAGES /usr/share/locale/ro \
		/usr/share/locale/lt/LC_MESSAGES /usr/share/locale/lt \
		/usr/share/locale/hu/LC_MESSAGES /usr/share/locale/hu \
		/usr/share/locale/hr/LC_MESSAGES /usr/share/locale/hr \
		/usr/share/locale/ga/LC_MESSAGES /usr/share/locale/ga \
		/usr/share/locale/eu/LC_MESSAGES /usr/share/locale/eu \
		/usr/share/locale/et/LC_MESSAGES /usr/share/locale/et \
		/usr/share/locale/da/LC_MESSAGES /usr/share/locale/da \
		/usr/share/locale/ca/LC_MESSAGES /usr/share/locale/ca

do-install:
	@${ECHO} ${DISTFILES}
	@rpm -U ${RPMFLAGS} ${RPMDIR}/${DISTFILES}
	@for D in ${REMOVE_DIRS}; do \
		${RM} -rf ${PREFIX}/$$D; \
	done

.include <bsd.port.mk>
