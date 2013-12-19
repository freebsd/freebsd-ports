# Created by: ijliao
# $FreeBSD$

PORTNAME=	dbconnect
PORTVERSION=	0.3.5
PORTREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	SF/${PORTNAME}/DBConnect%20API%200.3%20Source%20Code/DBConnect%20API%20${PORTVERSION}

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Use C++ object API to allow applications to connect to databases

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf
USE_LDCONFIG=	yes

CXXFLAGS+=	${PTHREAD_CFLAGS} -fPIC -DFREEBSD
LDFLAG+=	${PTHREAD_LIBS}

OPTIONS_DEFINE=	MYSQL PGSQL
OPTIONS_DEFAULT=	MYSQL

NO_STAGE=	yes
.include <bsd.port.options.mk>

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=		YES
CONFIGURE_ARGS+=	--enable-mysql=yes \
			--with-mysql_include=${LOCALBASE}/include/mysql \
			--with-mysql_lib=${LOCALBASE}/lib/mysql
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL}
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
	@${REINPLACE_CMD} 's/gcc/${CC}/' ${WRKSRC}/src/dbconnect/Makefile.in
	@${REINPLACE_CMD} 's/gcc/${CC}/' ${WRKSRC}/src/driver_*/Makefile.in

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

.include <bsd.port.mk>
