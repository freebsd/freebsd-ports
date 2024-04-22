PORTNAME=	cgprof
PORTVERSION=	1.2
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	http://mvertes.free.fr/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generates colored graphs for profiled executables using gcc and gprof
WWW=		http://mvertes.free.fr/

RUN_DEPENDS=	gawk:lang/gawk \
		dot:graphics/graphviz

NO_BUILD=	yes
MAKE_ENV=	prefix=${PREFIX}

PLIST_FILES=	bin/cgprof share/man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
