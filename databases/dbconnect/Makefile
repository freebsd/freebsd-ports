# Created by: ijliao
# $FreeBSD$

PORTNAME=	dbconnect
PORTVERSION=	0.3.5
PORTREVISION=	5
CATEGORIES=	databases
MASTER_SITES=	SF/${PORTNAME}/DBConnect%20API%200.3%20Source%20Code/DBConnect%20API%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Use C++ object API to allow applications to connect to databases

USES=		gmake dos2unix

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf
USE_LDCONFIG=	yes

CXXFLAGS+=	-fPIC -DFREEBSD
LDFLAG+=	-lpthread

OPTIONS_DEFINE=	MYSQL PGSQL
OPTIONS_DEFAULT=	MYSQL

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
USES+=		pgsql
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
	${CP} -r include/dbconn ${STAGEDIR}${PREFIX}/include/; \
	for lib in `find lib -type l -name *.so`; do \
		libpath=`${DIRNAME} $${lib}`; \
		libname=`${BASENAME} $${lib}|${SED} -e 's/\.so$$//'`; \
		${INSTALL_LIB} $${libpath}/$${libname}-${PORTVERSION}.so \
			${STAGEDIR}${PREFIX}/lib; \
		${LN} -fs $${libname}-${PORTVERSION}.so \
			${STAGEDIR}${PREFIX}/lib/$${libname}.so; \
	done

.include <bsd.port.mk>
