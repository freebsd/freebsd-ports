# ex:ts=8
# New ports collection makefile for:	dbconnect
# Date created:			Jul 23, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	dbconnect
PORTVERSION=	0.3.5
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	SF/${PORTNAME}/DBConnect%20API%200.3%20Source%20Code/DBConnect%20API%20${PORTVERSION}

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Use C++ object API to allow applications to connect to databases

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:262
USE_LDCONFIG=	yes

CXXFLAGS+=	${PTHREAD_CFLAGS} -fPIC -DFREEBSD
LDFLAG+=	${PTHREAD_LIBS}

OPTIONS=	MYSQL "With MySQL driver" on \
		PGSQL "With PostgreSQL driver" off

.include <bsd.port.pre.mk>

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.if !defined(WITHOUT_MYSQL)
USE_MYSQL=		YES
CONFIGURE_ARGS+=	--enable-mysql=yes \
			--with-mysql_include=${LOCALBASE}/include/mysql \
			--with-mysql_lib=${LOCALBASE}/lib/mysql
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	yes
CONFIGURE_ARGS+=	--enable-pgsql=yes \
			--with-pgsql_include=${LOCALBASE}/include \
			--with-pgsql_lib=${LOCALBASE}/lib
PLIST_SUB+=	PGSQL=""
.else
PLIST_SUB+=	PGSQL="@comment "
.endif

post-patch:
	@${RM} -f ${WRKSRC}/include/dbconn/README

do-install:
	@cd ${WRKSRC}; \
	${CP} -r include/dbconn ${PREFIX}/include/; \
	for lib in `find lib -type l -name *.so`; do \
		libpath=`${DIRNAME} $${lib}`; \
		libname=`${BASENAME} $${lib}|${SED} -e 's/\.so$$//'`; \
		${INSTALL_DATA} $${libpath}/$${libname}-${PORTVERSION}.so \
			${PREFIX}/lib; \
		(cd ${PREFIX}/lib; ${LN} -fs $${libname}-${PORTVERSION}.so \
			$${libname}.so); \
	done

.include <bsd.port.post.mk>
