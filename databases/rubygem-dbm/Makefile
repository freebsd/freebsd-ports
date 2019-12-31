# $FreeBSD$

PORTNAME=	dbm
PORTVERSION=	1.1.0
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	yasu@utahime.org
COMMENT=	Wrapper for the UNIX-style Database Manager Library

LICENSE=	BSD2CLAUSE

USES=		gem
USE_RUBY=	yes

OPTIONS_SINGLE=			BACKEND
OPTIONS_SINGLE_BACKEND=		BDB GDBM LIBC QDBM
OPTIONS_DEFAULT=		LIBC
BACKEND_DESC=			Select backend dbm library
BDB_USES=		bdb
BDB_CONFIGURE_ON=	--with-dbm-type=db${BDB_VER}
GDBM_CONFIGURE_ON=	--with-dbm-type=gdbm_compat
GDBM_LIB_DEPENDS=	libgdbm.so:databases/gdbm
LIBC_DESC=		libc ndbm support
LIBC_CONFIGURE_ON=	--with-dbm-type=libc
QDBM_DESC=		QDBM support
QDBM_CONFIGURE_ON=	--with-dbm-type=qdbm
QDBM_LIB_DEPENDS=	libqdbm.so:databases/qdbm

pre-configure-GDBM-on:
	@if [ ! -f ${LOCALBASE}/lib/libgdbm_compat.a ]; then ${ECHO_CMD} You need to reinstall database/gdbm with COMPAT option ON.; exit 1; fi

.include <bsd.port.mk>
