# New ports collection makefile for:    gdbmods
# Date created:         24 August 2002
# Whom:                 Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gdbmods
PORTVERSION=	20020824
CATEGORIES=	devel
MASTER_SITES=	http://people.freebsd.org/~gallatin/
DISTFILES=	gdbmods
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}
EXTRACT_ONLY=

MAINTAINER=	bms@FreeBSD.org
COMMENT=	Wrapper for gdb -k to provide kld symbol information

NO_BUILD=	yes
PLIST_FILES=	bin/gdbmods

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} ${PREFIX}/bin

.include <bsd.port.mk>
