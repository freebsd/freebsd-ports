# ex:ts=8
# Ports collection makefile for:	GDB 6
# Date created:				30 March 2001
# Whom:					David O'Brien <obrien@NUXI.com>
#
# $FreeBSD$
#

PORTNAME=	gdb
PORTVERSION=	6.6
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_GNU:S,$,:gdb,}	\
		http://aldan.algebra.com/~mi/:gdbtk
MASTER_SITE_SUBDIR=gdb/:gdb
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:gdb

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	GNU GDB of newer version than comes with the system

OPTIONS=	INSIGHT "Build the Tcl/Tk GUI (experimental!)" off

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CONFIGURED_M4=m4 CONFIGURED_BISON=byacc
CONFIGURE_ARGS=	--program-suffix=${PORTVERSION:S/.//g} \
		--enable-target=all \
		--enable-tui --with-libiconv-prefix=${LOCALBASE}
CFLAGS:=	${CFLAGS:C/ +$//}	# blanks at EOL creep in sometimes
CFLAGS+=	-DRL_NO_COMPAT
EXCLUDE=	dejagnu expect readline sim texinfo intl
EXTRACT_AFTER_ARGS=| ${TAR} -xf - ${EXCLUDE:S/^/--exclude /}
VER=	${PORTVERSION:S/.//}
PLIST_SUB=	VER=${VER}
MAN1=	gdb${VER}.1

#ONLY_FOR_ARCHS=	i386 amd64	# untested elsewhere, might work

.include <bsd.port.pre.mk>

.if defined(WITH_INSIGHT)
LIB_DEPENDS=	itk:${PORTSDIR}/x11-toolkits/itk
RUN_DEPENDS=	${LOCALBASE}/lib/iwidgets:${PORTSDIR}/x11-toolkits/iwidgets
DISTFILES+=	gdbtk-6.6${EXTRACT_SUFX}:gdbtk
PLIST_SUB+=	INSIGHT=''
EXTRA_PATCHES=	${FILESDIR}/itcl33-patch
CONFIGURE_ARGS+=--enable-gdbtk \
		--with-tclconfig=${LOCALBASE}/lib/tcl8.4 \
		--with-tclinclude=${LOCALBASE}/include/tcl8.4/generic \
		--with-tkconfig=${LOCALBASE}/lib/tk8.4 \
		--with-tkinclude=${LOCALBASE}/include/tk8.4/generic \
		--with-itclconfig=${LOCALBASE}/lib/itcl3.3 \
		--with-itkconfig=${LOCALBASE}/lib/itk3.3

pre-everything::
	#
	# The Tk-based GUI (Insight) is patched to work with [incr tcl]
	# version 3.3 and is currently experimental. Bug reports should
	# be accompanied by patches.
	#

pre-configure:
	${MKDIR} ${WRKSRC}/itcl/generic
	${LN} -s ${LOCALBASE}/include/it*3.3/*.h ${WRKSRC}/itcl/generic/
.else
PLIST_SUB+=	INSIGHT='@comment '
.endif

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}

.if ${OSVERSION} >= 800000
BROKEN=		does not compile
.endif

.endif

post-patch:
	@${REINPLACE_CMD} -e 's/$$/ [GDB v${PORTVERSION} for FreeBSD]/' \
		${WRKSRC}/gdb/version.in
	@${REINPLACE_CMD} -e 's/^READLINE/#READLINE/' \
		-e 's/^readline/#readline/' \
		-e 's,^LIBICONV =.*,LIBICONV=-L${LOCALBASE}/lib -liconv,' \
		${WRKSRC}/gdb/Makefile.in
	${ECHO} 'READLINE = -lreadline' >> ${WRKSRC}/gdb/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gdb/gdb ${PREFIX}/bin/gdb${VER}
	${LN} ${PREFIX}/bin/gdb${VER} ${PREFIX}/bin/gdbtui${VER}
	${INSTALL_MAN} ${WRKSRC}/gdb/gdb.1 ${MAN1PREFIX}/man/man1/gdb${VER}.1
.if defined(WITH_INSIGHT)
	${LN} ${PREFIX}/bin/gdb${VER} ${PREFIX}/bin/insight
	${MKDIR} ${PREFIX}/share/redhat/gui
	${CP} -p ${WRKSRC}/libgui/library/*.tcl	\
		${WRKSRC}/libgui/library/tclIndex \
			${PREFIX}/share/redhat/gui/
	${MKDIR} ${PREFIX}/lib/insight1.0
	${CP} -Rp ${WRKSRC}/gdb/gdbtk/library/*.tcl	\
		${WRKSRC}/gdb/gdbtk/library/*.itcl	\
		${WRKSRC}/gdb/gdbtk/library/*.ith	\
		${WRKSRC}/gdb/gdbtk/library/*.itb	\
		${WRKSRC}/gdb/gdbtk/library/help	\
		${WRKSRC}/gdb/gdbtk/library/images*	\
		${WRKSRC}/gdb/gdbtk/library/tclIndex	\
			${PREFIX}/lib/insight1.0
.endif

.include <bsd.port.post.mk>
