# Created by: Adam McLaurin
# $FreeBSD$

PORTNAME=	cgprof
PORTVERSION=	1.2
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://mvertes.free.fr/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generates colored graphs for profiled executables using gcc and gprof

RUN_DEPENDS=	gawk:lang/gawk \
		dotty:graphics/graphviz

NO_BUILD=	yes
MAKE_ENV=	prefix=${PREFIX}

PLIST_FILES=	bin/cgprof man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
