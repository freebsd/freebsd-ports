# New ports collection makefile for:	pike
# Date created:		16 Jan 1999
# Whom:			vns@delta.odessa.ua
#
# $FreeBSD$
#

PORTNAME=	pike
PORTVERSION=	7.0.361
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.oav.net/pike/7.0/	\
		ftp://ftp.oav.net/caudium/pkg/FreeBSD/distfiles/ \
		ftp://ftp.caudium.net/caudium/snapshots/pike/7.0/ \
		http://grendel.firewall.com/caudium-pkg/
DISTNAME=	pike-${PORTVERSION}

MAINTAINER=	kiwi@oav.net
COMMENT=	A dynamic programming language with a syntax similar to C++

BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison/

ONLY_FOR_ARCHS=	i386

DEPRECATED=	Please use pike72
EXPIRATION_DATE=2007-03-01

WRKSRC=		${WRKDIR}/${DISTNAME}/src/
PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--without-debug --with-poll --with-oob --with-max-fds=10000 --without-GTK
MAN1=		hilfe.1 pike.1
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

OPTIONS=	FREETYPE        "TrueType font rendering" off \
		JPEG            "support JPEG" off \
		THREADS         "threads support" on \
		GDBM            "GNU database manager support" off \
		ZLIB            "zlib library support" on \
		GMP             "support bignums" on \
		READLINE        "support for command line editing" on \
		MYSQL           "MySQL database support" off \
		POSTGRESQL      "PostgreSQL database support" off \
		MSQL            "mSQL database support" off \
		SSL             "SSL support" off \

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_FREETYPE)
LIB_DEPENDS+=		ttf.4:${PORTSDIR}/print/freetype
CONFIGURE_ARGS+=	--with-ttflib
.else
CONFIGURE_ARGS+=	--without-ttflib
.endif
.if !defined(WITHOUT_THREADS)
CONFIGURE_ARGS+=	--with-threads
.else
CONFIGURE_ARGS+=	--without-threads
.endif
.if !defined(WITHOUT_GMP)
LIB_DEPENDS+=		gmp.7:${PORTSDIR}/math/libgmp4
CONFIGURE_ARGS+=	--with-gmp --with-bignums
.else
CONFIGURE_ARGS+=	--without-gmp --without-bignums
.endif
.if !defined(WITHOUT_READLINE)
CONFIGURE_ARGS+=	--with-readline
.else
CONFIGURE_ARGS+=	--without-readline
.endif
.if !defined(WITHOUT_JPEG)
LIB_DEPENDS+=		jpeg.9:${PORTSDIR}/graphics/jpeg
CONFIGURE_ARGS+=	--with-jpeg=${PREFIX}
.else
CONFIGURE_ARGS+=	--without-jpeg
.endif
.if !defined(WITHOUT_GDBM)
LIB_DEPENDS+=		gdbm.3:${PORTSDIR}/databases/gdbm
CONFIGURE_ARGS+=	--with-gdbm=${PREFIX}
.else
CONFIGURE_ARGS+=	--without-gdbm
.endif
.if !defined(WITHOUT_ZLIB)
CONFIGURE_ARGS+=	--with-zlib
.else
CONFIGURE_ARGS+=	--without-zlib
.endif
.if !defined(WITHOUT_MYSQL)
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mysql=${PREFIX}
.else
CONFIGURE_ARGS+=	--without-mysql
.endif
.if !defined(WITHOUT_POSTGRESQL)
USE_PGSQL=	yes
CONFIGURE_ARGS+=	--with-pgsql=${PREFIX}/pgsql
.else
CONFIGURE_ARGS+=	--without-pgsql
.endif
.if !defined(WITHOUT_MSQL)
BUILD_DEPENDS+=		msql:${PORTSDIR}/databases/msql
CONFIGURE_ARGS+=	--with-msql=${PREFIX}
.else
CONFIGURE_ARGS+=	--without-msql
.endif
.if !defined(WITHOUT_SSL)
CONFIGURE_ARGS+=	--with-ssleay
.else
CONFIGURE_ARGS+=	--without-ssleay
.endif

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}pike ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}hilfe ${PREFIX}/bin

.include <bsd.port.post.mk>
