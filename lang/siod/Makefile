# Created by: jkoshy
# $FreeBSD$

PORTNAME=	siod
PORTVERSION=	3.6.2
CATEGORIES=	lang scheme
MASTER_SITES=	http://people.delphiforums.com/gjc/
DISTNAME=	siod
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}	# Upstream aren't versioned :(

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Small footprint implementation of the Scheme programming language

LICENSE=	LGPL21	# Declared inside slib.c

USES=		uidfix tar:tgz dos2unix

USE_LDCONFIG=	${PREFIX}/lib ${PREFIX}/lib/siod

DOS2UNIX_FILES=	sql_oracle.c ss.c siod.scm
OPTIONS_DEFINE=	SQL_SYBASE GD NDBM REGEX SS DOCS
OPTIONS_DEFINE_i386=SQL_ORACLE	# oracle-client port only available for i386
OPTIONS_DEFAULT=NDBM REGEX SS
SQL_ORACLE_DESC=Build Oracle client-module (i386 only)
SQL_SYBASE_DESC=Build Sybase (and MS-SQL) client-module (using FreeTDS)
SS_DESC=	Sockets support - required for any network programs
NDBM_DESC=	Support for NDBM-databases
NO_WRKSUBDIR=	yes
EXTRACT_AFTER_ARGS=--exclude md5\* --exclude regex.h --exclude reg????*.c
MAKE_ARGS=	VPATH=${WRKSRC} MODULES=${MODULES:Q}
MAKEFILE=	${FILESDIR}/BSDmakefile
MAKE_ENV=	MKDIR=${MKDIR:Q} STAGEDIR=${STAGEDIR:Q}
MAKE_ENV+=	MAN1PREFIX=${MAN1PREFIX} PREFIX=${PREFIX:Q}
MAKE_ENV+=	INSTALL_MAN=${INSTALL_MAN:Q} INSTALL_SCRIPT=${INSTALL_SCRIPT:Q}
MAKE_ENV+=	INSTALL_DATA=${INSTALL_DATA:Q}

MODULES=	acct statfs tar parser_pratt

SQL_SYBASE_LIB_DEPENDS=	libct.so:databases/freetds	# Or freetds-devel
GD_LIB_DEPENDS=		libgd.so:graphics/gd	# Or ukrainian/gd
REGEX_LIB_DEPENDS=	libgnuregex.so:devel/libgnuregex
OPTIONS_SUB=	yes
SQL_ORACLE_BUILD_DEPENDS=${LOCALBASE}/oracle8-client/lib/libclntsh.a:databases/oracle8-client

.if "${PREFIX}" != "/usr/local"
post-patch:
	${REINPLACE_CMD} 's|/usr/local|${PREFIX}|g' ${WRKSRC}/slib.c \
		${WRKSRC}/*.man
.endif

post-build:
	${REINPLACE_CMD} -e 's|\./siod|env LD_LIBRARY_PATH=lib siod/siod|g' \
		-e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/makefile
	${MAKE} -C ${WRKSRC} -f makefile build_driver

.include <bsd.port.options.mk>
MODULES+=	${SELECTED_OPTIONS:NDOCS:tl}

# XXX This should not be necessary:
.if ${ARCH} != i386
PLIST_SUB+=	SQL_ORACLE="@comment "
.endif

do-configure:
	${MKDIR} ${WRKSRC}/lib
	${LN} -sf ${FILESDIR}/BSDmakefile.lib ${WRKSRC}/lib/BSDmakefile
.for s in ${MODULES}
	${MKDIR} ${WRKSRC}/$s
	${SED} "s,%%MODULE%%,$s,g" ${FILESDIR}/BSDmakefile.module > \
	    ${WRKSRC}/$s/BSDmakefile
.endfor
.for s in siod sample
	${MKDIR} ${WRKSRC}/$s
	${SED} "s,%%PROG%%,$s,g" ${FILESDIR}/BSDmakefile.prog >	\
	    ${WRKSRC}/$s/BSDmakefile
.endfor

post-install-DOCS-off:
	${RM} ${STAGEDIR}${PREFIX}/lib/siod/siod.html

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MV} ${STAGEDIR}${PREFIX}/lib/siod/siod.html ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
