# New ports collection makefile for:	cgprof
# Date created:				16 December 2004
# Whom:					Adam McLaurin
#
# $FreeBSD$
#

PORTNAME=	cgprof
PORTVERSION=	1.2
CATEGORIES=	devel
MASTER_SITES=	http://mvertes.free.fr/download/

MAINTAINER=	adam.freebsd@fastmail.fm
COMMENT=	Generates colored graphs for profiled executables using gcc and gprof

RUN_DEPENDS=	gawk:${PORTSDIR}/lang/gawk \
		dotty:${PORTSDIR}/graphics/graphviz

NO_BUILD=	yes
MAKE_ENV=	prefix=${PREFIX}

MAN1=		cgprof.1
PLIST_FILES=	bin/cgprof

.include <bsd.port.mk>
