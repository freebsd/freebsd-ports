# Created by: Martin Matuska <martin@matuska.org>
# $FreeBSD$

PORTNAME=	mysqltcl
PORTVERSION=	3.052
CATEGORIES=	databases tcl
MASTER_SITES=	http://www.xdobry.de/mysqltcl/

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	TCL module for accessing MySQL databases based on msqltcl

USE_LDCONFIG=	yes
USE_MYSQL=	yes
USE_TCL=	83+
USE_DOS2UNIX=	generic/mysqltcl.c

MANN=		mysqltcl.n

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=--with-tcl=${TCL_LIBDIR} \
		--with-mysql-include=${LOCALBASE}/include/mysql \
		--with-mysql-lib=${LOCALBASE}/lib/mysql \
		--exec-prefix=${PREFIX}

PLIST_SUB+=	LIB_DIR=${PORTNAME}-${PORTVERSION} \
		LIB_NAME=libmysqltcl${PORTVERSION}.so

.include <bsd.port.mk>
