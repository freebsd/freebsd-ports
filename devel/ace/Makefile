# Ports collection makefile for:	ace
# Date created:				5 January 2004
# Whom:					Sergey Matveychuk <sem@ciam.ru>
#
# $FreeBSD$
#

PORTNAME=	ace
PORTVERSION=	6.1.2
CATEGORIES=	devel
MASTER_SITES=	ftp://download.dre.vanderbilt.edu/previous_versions/ \
		http://download.dre.vanderbilt.edu/previous_versions/
DISTNAME=	ACE-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Adaptive Communication Environment for C++

OPTIONS_DEFINE=	SSL TRIO X11 FLTK TK QT4
OPTIONS_DEFAULT=SSL
TRIO_DESC=	Enable trio support
FLTK_DESC=	Enable FLTK support
TK_DESC=	Enable Tcl/Tk support

CONFLICTS=	ace+tao-5*

WRKSRC=		${WRKDIR}/ACE_wrappers

USE_BZIP2=	yes
USE_PERL5_BUILD=yes
USE_GMAKE=	yes
MAKE_ENV=	LD_LIBRARY_PATH="${WRKSRC}/lib" ACE_ROOT="${WRKSRC}" \
		CROSS-COMPILE=1
MAKEFILE=	GNUmakefile
USE_LDCONFIG=	yes
USE_PKGCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	VERSION="${PORTVERSION}"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSL}
USE_OPENSSL=	yes
MAKE_ENV+=	ssl=1
PLIST_SUB+=	OPENSSL=""
.else
PLIST_SUB+=	OPENSSL="@comment "
.endif

.if ${PORT_OPTIONS:MTRIO}
BUILD_DEPENDS+=	trio>=0:${PORTSDIR}/devel/trio
MAKE_ENV+=	trio=1
.endif

.if ${PORT_OPTIONS:MX11}
USE_XORG=	xt
MAKE_ENV+=	xt=1
PLIST_SUB+=	X11=""
.else
PLIST_SUB+=	X11="@comment "
.endif

.if ${PORT_OPTIONS:MFLTK}
LIB_DEPENDS+=	fltk:${PORTSDIR}/x11-toolkits/fltk
MAKE_ENV+=	fl=1
PLIST_SUB+=	FLTK=""
.else
PLIST_SUB+=	FLTK="@comment "
.endif

.if ${PORT_OPTIONS:MTK}
USE_TK_BUILD=	yes
USE_TK=		yes
MAKE_ENV+=	tk=1
PLIST_SUB+=	TK=""
.else
PLIST_SUB+=	TK="@comment "
.endif

.if ${PORT_OPTIONS:MQT4}
USE_QT4=	corelib gui moc_build
MAKE_ENV+=	qt=1 qt4=1 QTDIR="${QT_PREFIX}"
CPPFLAGS+=	-I${QT_INCDIR}
LDFLAGS+=	-L${QT_LIBDIR}
PLIST_SUB+=	QT=""
.else
PLIST_SUB+=	QT="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|/$$libdir/pkgconfig|/libdata/pkgconfig|g' ${WRKSRC}/bin/ace_install_pkgconfig.pl
	@${REINPLACE_CMD} -e \
		's|bin/moc)|bin/moc-qt4)|g ; \
		 s|bin/moc,|bin/moc-qt4,|'g ${WRKSRC}/ace/QtReactor/GNUmakefile.ACE_Qt4Reactor_moc

do-configure:
	@cd ${WRKSRC}/ace \
		&& ${ECHO_CMD} "#include <ace/config-${OPSYS:L}.h>" >> config.h
	@cd ${WRKSRC}/include/makeinclude \
		&& ${ECHO_CMD} "include \$$(ACE_ROOT)/include/makeinclude/platform_${OPSYS:L}.GNU" >> platform_macros.GNU \
		&& ${ECHO_CMD} "CC=	${CC}" >> platform_macros.GNU \
		&& ${ECHO_CMD} "CXX=	${CXX}" >> platform_macros.GNU \
		&& ${ECHO_CMD} "CPPFLAGS=	${CPPFLAGS}" >> platform_macros.GNU \
		&& ${ECHO_CMD} "LDFLAGS=	${LDFLAGS}" >> platform_macros.GNU \
		&& ${ECHO_CMD} "DCFLAGS=" >> platform_macros.GNU \
		&& ${ECHO_CMD} "OCFLAGS=	${CFLAGS}" >> platform_macros.GNU \
		&& ${ECHO_CMD} "INSTALL_PREFIX=	${PREFIX}" >> platform_macros.GNU

post-install:
	@for f in `${LS} -d \
		${PREFIX}/lib/libACE*.so.${PORTVERSION} \
		${PREFIX}/lib/libJAWS.so.${PORTVERSION} \
		${PREFIX}/lib/libKokyu.so.${PORTVERSION} \
		| ${XARGS} ${BASENAME}`; do \
		n=`echo $${f}|sed -e 's/.so.${PORTVERSION}/.so/'`; \
		${LN} -sf $${n}.${PORTVERSION} ${PREFIX}/lib/$${n}.6; \
	done

.include <bsd.port.post.mk>
