# New ports collection makefile for:	The Neko Programming Language
# Date created:		08 August 2007
# Whom:			Masanori OZAWA (ozawa@ongs.co.jp)
#
# $FreeBSD$
#

PORTNAME=	neko
PORTVERSION=	1.8.0
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://nekovm.org/_media/

MAINTAINER=	ozawa@ongs.co.jp
COMMENT=	The Neko Programming Language

ONLY_FOR_ARCHS=	i386 amd64

USE_AUTOTOOLS=	libtool:15:env
USE_GMAKE=	yes

OPTIONS=	APACHE13 "Build with mod_neko for Apache 1.3.x" off \
		APACHE22 "Build with mod_neko for Apache 2.2.x" off \
		MYSQL4   "Build with MySQL 4.x library" off \
		SQLITE3  "Build with Sqlite 3.x SQL library" off \
		PCRE     "Build with PCRE library" on \
		GTK2     "Build with Gtk 2.x UI library" on

.include <bsd.port.pre.mk>

# Neko needs boehm-gc with POSIX thread support.
BC_DIR!=	cd ${PORTSDIR}/devel/boehm-gc && ${MAKE} -V WRKSRC
BC_MAKEARGS=	BATCH=yes WITH_THREADING=true

BC_CFLAGS:=	${CFLAGS}
CFLAGS+=	-I${WRKSRC} -I${LOCALBASE}/include
LDFLAGS+=	-L${BC_DIR}/.libs -L${LOCALBASE}/lib
LIBKEYNAME=

.if defined(WITH_APACHE13)
BUILD_DEPENDS+=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13
RUN_DEPENDS+=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13
CFLAGS+=	-I${LOCALBASE}/include/apache
PLIST_SUB+=	APACHE13=
.else
LIBKEYNAME+=	mod_neko mod_tora
PLIST_SUB+=	APACHE13="@comment "
.endif

.if defined(WITH_APACHE22)
BUILD_DEPENDS+=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache22
RUN_DEPENDS+=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache22
CFLAGS+=	-I${LOCALBASE}/include/apache22
PLIST_SUB+=	APACHE22=
.else
LIBKEYNAME+=	mod_neko2 mod_tora2
PLIST_SUB+=	APACHE22="@comment "
.endif

.if defined(WITH_MYSQL4)
BUILD_DEPENDS+=	mysql:${PORTSDIR}/databases/mysql41-client
RUN_DEPENDS+=	mysql:${PORTSDIR}/databases/mysql41-client
CFLAGS+=	-I${LOCALBASE}/include/mysql
PLIST_SUB+=	MYSQL4=
.else
LIBKEYNAME+=	mysql
PLIST_SUB+=	MYSQL4="@comment "
.endif

.if defined(WITH_SQLITE3)
BUILD_DEPENDS+=	sqlite3:${PORTSDIR}/databases/sqlite3
RUN_DEPENDS+=	sqlite3:${PORTSDIR}/databases/sqlite3
PLIST_SUB+=	SQLITE3=
.else
LIBKEYNAME+=	sqlite
PLIST_SUB+=	SQLITE3="@comment "
.endif

.if defined(WITH_PCRE)
BUILD_DEPENDS+=	${LOCALBASE}/include/pcre.h:${PORTSDIR}/devel/pcre
RUN_DEPENDS+=	${LOCALBASE}/include/pcre.h:${PORTSDIR}/devel/pcre
PLIST_SUB+=	PCRE=
.else
LIBKEYNAME+=	regexp
PLIST_SUB+=	PCRE="@comment "
.endif

.if defined(WITH_GTK2)
BUILD_DEPENDS+=	${LOCALBASE}/include/gtk-2.0:${PORTSDIR}/x11-toolkits/gtk20
RUN_DEPENDS+=	${LOCALBASE}/include/gtk-2.0:${PORTSDIR}/x11-toolkits/gtk20
PLIST_SUB+=	GTK2=
.else
LIBKEYNAME+=	ui
PLIST_SUB+=	GTK2="@comment "
.endif

.if ${ARCH} == "amd64"
BC_CFLAGS+=	-fPIC
CFLAGS+=	-D_64BITS -fPIC
.endif

post-patch:
	@${REINPLACE_CMD} \
	    -e '/INSTALL_PREFIX/s,/usr/local,${PREFIX},' \
	    -e '/^CFLAGS =/s,.$$, ${CFLAGS},' \
	    -e '/LIBNEKO_LIBS =/s,[-]ldl,${LDFLAGS},' \
	    -e '/LIBNEKO_LIBS =/s,[-]lgc,-lnekogc,' \
	    -e '/mkdir/s,\(INSTALL_PREFIX[}]/include\),\1/neko,' \
	    -e '/cp vm[/]neko[*][.]h/s,\(INSTALL_PREFIX[}]/include\),\1/neko,' \
	    ${WRKSRC}/Makefile
	@${REINPLACE_CMD} \
	    -e '/^[#]	include/s,wait.h,sys/wait.h,' \
	    ${WRKSRC}/libs/std/process.c
	@${REINPLACE_CMD} \
	    -e '/^linkcmd =/s,"ld",cc,' \
	    -e 's/= readline[(][)];/= "s";/' \
	    -e 's,/usr/local/include,${PREFIX}/include,' \
	    -e 's,/usr/local/lib,${PREFIX}/lib,' \
	    ${WRKSRC}/src/tools/install.neko
.if !empty(LIBKEYNAME)
.for LKN in ${LIBKEYNAME}
	@${REINPLACE_CMD} \
	    -e '/^	${LKN} =[>]/,/^	[}][,]\{0,1\}.$$/d' \
	    ${WRKSRC}/src/tools/install.neko
.endfor
.endif
.if defined(WITH_APACHE13)
	@${REINPLACE_CMD} \
	    -e 's,"/usr/include/apache-1.3","${PREFIX}/include/apache",' \
	    ${WRKSRC}/src/tools/install.neko
.endif
.if defined(WITH_APACHE22)
	@${REINPLACE_CMD} \
	    -e 's,"/usr/include/apache2","${PREFIX}/include/apache22",' \
	    ${WRKSRC}/src/tools/install.neko
.endif
.if defined(WITH_GTK2)
	@${REINPLACE_CMD} \
	    -e 's,"/usr/include/gtk-2.0","${PREFIX}/include/gtk-2.0",' \
	    ${WRKSRC}/src/tools/install.neko
	@${REINPLACE_CMD} \
	    -e 's,NEKO_LINUX,NEKO_BSD,' ${WRKSRC}/libs/ui/ui.c
.endif
.if ${ARCH} == "amd64" && defined(WITH_MYSQL4)
	@${ECHO_CMD}
	@${ECHO_CMD} "======================================================="
	@${ECHO_CMD}
	@${ECHO_CMD} " Notice: When not building MYSQL with 'CFLAGS+=-fPIC'"
	@${ECHO_CMD} " first, It fails in building of a MYSQL module."
	@${ECHO_CMD}
	@${ECHO_CMD} "======================================================="
	@${ECHO_CMD}
.endif

pre-build:
	@(cd ${PORTSDIR}/devel/boehm-gc/ && \
	    ${MAKE} CFLAGS="${BC_CFLAGS}" ${BC_MAKEARGS} clean all)
	@${RM} -f ${BC_DIR}/.libs/*.so*
	@for BLIB in `${LS} ${BC_DIR}/.libs/libgc.*`; do \
	    ${MV} $${BLIB} `echo $${BLIB} | ${SED} -e 's/libgc/libnekogc/'`; \
	done
	@${LN} -sf ${BC_DIR}/include ${WRKSRC}/gc

post-install:
.if defined(WITH_APACHE13) || defined(WITH_APACHE22)
	@${ECHO_CMD}
	@${ECHO_CMD} "======================================================="
	@${ECHO_CMD}
	@${ECHO_CMD} " If you want to use Apache with mod_neko, you need "
	@${ECHO_CMD} " edit the Apache configuration files."
	@${ECHO_CMD} " Please see 'http://nekovm.org/doc/mod_neko' for details."
	@${ECHO_CMD}
	@${ECHO_CMD} "======================================================="
	@${ECHO_CMD}
.endif

pre-clean:
	@(cd ${PORTSDIR}/devel/boehm-gc/ && ${MAKE} clean)

.include <bsd.port.post.mk>
