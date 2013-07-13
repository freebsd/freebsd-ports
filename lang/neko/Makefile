# Created by: Masanori OZAWA (ozawa@ongs.co.jp)
# $FreeBSD$

PORTNAME=	neko
PORTVERSION=	1.8.2
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://nekovm.org/_media/

MAINTAINER=	ozawa@ongs.co.jp
COMMENT=	The Neko Programming Language

LIB_DEPENDS=	gc-threaded.1:${PORTSDIR}/devel/boehm-gc-threaded

ONLY_FOR_ARCHS=	i386 amd64

USES=		gmake
USE_AUTOTOOLS=	libtool:env
USE_DOS2UNIX=	yes
MAKE_JOBS_UNSAFE=	yes
DOS2UNIX_REGEX= .*(Makefile|\.(c|h|neko|nml))$$

OPTIONS_DEFINE=		APACHE MYSQL SQLITE PCRE GTK2
OPTIONS_DEFAULT=	PCRE GTK2

OPTIONS_SINGLE=		MYSQL
OPTIONS_SINGLE_MYSQL=	MYSQL4 MYSQL5

MYSQL4_DESC=		Build against MySQL 4.1
MYSQL5_DESC=		Build against MySQL 5.1

.include <bsd.port.options.mk>

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
LIBKEYNAME+=	mod_neko mod_tora

.if ${PORT_OPTIONS:MAPACHE}
USE_APACHE=	22
CFLAGS+=	-I${LOCALBASE}/include/apache22
PLIST_SUB+=	APACHE22=""
.else
LIBKEYNAME+=	mod_neko2 mod_tora2
PLIST_SUB+=	APACHE22="@comment "
.endif

.if ${PORT_OPTIONS:MMYSQL4}
USE_MYSQL=	41
CFLAGS+=	-I${LOCALBASE}/include/mysql
PLIST_SUB+=	MYSQL4=""
.else
LIBKEYNAME+=	mysql
PLIST_SUB+=	MYSQL4="@comment "
.endif

.if ${PORT_OPTIONS:MMYSQL5}
USE_MYSQL=	51
CFLAGS+=	-I${LOCALBASE}/include/mysql
PLIST_SUB+=	MYSQL5=""
.else
LIBKEYNAME+=	mysql5
PLIST_SUB+=	MYSQL5="@comment "
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_SQLITE=	yes
PLIST_SUB+=	SQLITE3=""
.else
LIBKEYNAME+=	sqlite
PLIST_SUB+=	SQLITE3="@comment "
.endif

.if ${PORT_OPTIONS:MPCRE}
LIB_DEPENDS+=	pcre:${PORTSDIR}/devel/pcre
PLIST_SUB+=	PCRE=""
.else
LIBKEYNAME+=	regexp
PLIST_SUB+=	PCRE="@comment "
.endif

.if ${PORT_OPTIONS:MGTK2}
USE_GNOME=	gtk20
PLIST_SUB+=	GTK2=""
.else
LIBKEYNAME+=	ui
PLIST_SUB+=	GTK2="@comment "
.endif

.if ${ARCH} == "amd64"
CFLAGS+=	-D_64BITS -fPIC
.endif

post-patch:
	@${REINPLACE_CMD} \
	    -e '/INSTALL_PREFIX/s,/usr/local,${PREFIX},' \
	    -e '/^CFLAGS =/s,.$$, ${CFLAGS},' \
	    -e '/LIBNEKO_LIBS =/s,[-]ldl,${LDFLAGS},' \
	    -e '/LIBNEKO_LIBS =/s,[-]lgc,-lgc-threaded,' \
	    -e '/NEKOVM_FLAGS =/s,[-]lneko,-L${LOCALBASE}/lib -lneko -lgc-threaded,' \
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
.if ${PORT_OPTIONS:MAPACHE}
	@${REINPLACE_CMD} \
	    -e 's,"/usr/include/apache2","${PREFIX}/include/apache22",' \
	    ${WRKSRC}/src/tools/install.neko
.endif
.if ${PORT_OPTIONS:MGTK2}
	@${REINPLACE_CMD} \
	    -e 's,"/usr/include/gtk-2.0","${PREFIX}/include/gtk-2.0",' \
	    ${WRKSRC}/src/tools/install.neko
	@${REINPLACE_CMD} \
	    -e 's,NEKO_LINUX,NEKO_BSD,' ${WRKSRC}/libs/ui/ui.c
.endif
.if ${ARCH} == "amd64" && ${PORT_OPTIONS:MMYSQL4}
	@${ECHO_CMD}
	@${ECHO_CMD} "======================================================="
	@${ECHO_CMD}
	@${ECHO_CMD} " Notice: When not building MYSQL with 'CFLAGS+=-fPIC'"
	@${ECHO_CMD} " first, It fails in building of a MYSQL module."
	@${ECHO_CMD}
	@${ECHO_CMD} "======================================================="
	@${ECHO_CMD}
.endif

post-install:
.if ${PORT_OPTIONS:MAPACHE}
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

.include <bsd.port.mk>
