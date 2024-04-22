PORTNAME=	mysqltcl
PORTVERSION=	3.052
PORTREVISION=	2
CATEGORIES=	databases tcl
MASTER_SITES=	http://www.xdobry.de/mysqltcl/

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	TCL module for accessing MySQL databases based on msqltcl
WWW=		http://www.xdobry.de/mysqltcl/

USES=		mysql tcl
USE_LDCONFIG=	yes

PLIST_FILES=	lib/${PORTNAME}-${PORTVERSION}/libmysqltcl${PORTVERSION}.so \
		lib/${PORTNAME}-${PORTVERSION}/pkgIndex.tcl \
		share/man/mann/mysqltcl.n.gz

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

CONFIGURE_ARGS+=--with-tcl=${TCL_LIBDIR} \
		--with-mysql-include=${LOCALBASE}/include/mysql \
		--with-mysql-lib=${LOCALBASE}/lib/mysql \
		--exec-prefix=${PREFIX}

.include <bsd.port.mk>
