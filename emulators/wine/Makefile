# ex:ts=8
# New ports collection makefile for:    wine
# Date created:         Sa   9 Nov 1996 00:52:22 MET
# Whom:			se
#
# $FreeBSD$
#

PORTNAME=	wine
PORTVERSION=	2000.05.26
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	ALPHA/wine/development
DISTNAME=	Wine-${PORTVERSION:S/.//g}

MAINTAINER=	pfeifer@dbai.tuwien.ac.at

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		GL.14:${PORTSDIR}/graphics/Mesa3

WRKSRC=		${WRKDIR}/wine-${PORTVERSION:S/.//g}
GNU_CONFIGURE=	yes
MAN1=		wine.1
MAN5=		wine.conf.5
ONLY_FOR_ARCHS=	i386

.if !defined(NDEBUG)
STRIP=
CFLAGS+=	-g
.else
pre-extract:
	@${ECHO} "NDEBUG has been set, building without debug info..."
	@${ECHO} "This will save diskspace but it makes debugging harder."
	@${ECHO} "If for example wine crashes and you would like to send"
	@${ECHO} "the backtrace it then dumps to the developers (or"
	@${ECHO} "comp.emulators.ms-windows.wine) it will be much more useful"
	@${ECHO} "to them if you first rebuild without this and generate it again."
	@${ECHO} "(If you're _not_ low on diskspace there is not really a reason to"
	@${ECHO} "use this flag, the resulting wine won't use more VM or anything like"
	@${ECHO} "that when running, only when it has to enter the debugger...)"
.endif

post-configure:
	cd ${WRKSRC} && make depend

post-build:
	cd ${WRKSRC}/programs/regapi && ${MAKE}
	${SED} '1s/bash/sh/;s-\./\(reg.*\.pl\)-'${PREFIX}/lib/wine/reg/'\1-' <${WRKSRC}/programs/regapi/regSet.sh >${WRKDIR}/regSet.sh
	${SED} 's-\(Change directory to \)<dirs to wine>/tools$$-\1your program'"'"'s dir (or wherever you need to be to run it)-;s-\./\(bug_report\.pl\)-'${PREFIX}/lib/wine/'\1-' <${WRKSRC}/documentation/bugreports >${WRKDIR}/bugreports
	${SED} 's-\(look at the file \)<dirs to wine>/wine.ini-\1'${PREFIX}/etc/wine.conf.sample- <${WRKSRC}/documentation/config >${WRKDIR}/config

do-install:
	cd ${WRKSRC} && ${MAKE} install
	${INSTALL_SCRIPT} ${WRKDIR}/regSet.sh ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/wine.ini ${PREFIX}/etc/wine.conf.sample
	[ -f ${PREFIX}/etc/wine.conf ] \
		|| ${INSTALL_DATA} ${WRKSRC}/wine.ini ${PREFIX}/etc/wine.conf
	${INSTALL_DATA} ${WRKSRC}/documentation/wine.man ${PREFIX}/man/man1/wine.1
	${INSTALL_DATA} ${WRKSRC}/documentation/wine.conf.man ${PREFIX}/man/man5/wine.conf.5
	-@${MKDIR} ${PREFIX}/lib/wine/documentation ${PREFIX}/lib/wine/reg 2>/dev/null
	${INSTALL_DATA} ${WRKDIR}/bugreports ${WRKDIR}/config \
		${WRKSRC}/README \
		${WRKSRC}/ANNOUNCE \
		${WRKSRC}/AUTHORS \
		${WRKSRC}/LICENSE \
		${WRKSRC}/WARRANTY \
		${WRKSRC}/documentation/cdrom-labels \
		${WRKSRC}/documentation/debugging \
		${WRKSRC}/documentation/dlls \
		${WRKSRC}/documentation/fonts \
		${WRKSRC}/documentation/ioport-trace-hints \
		${WRKSRC}/documentation/no-windows \
		${WRKSRC}/documentation/printing \
		${WRKSRC}/documentation/psdriver \
		${WRKSRC}/documentation/psdrv.reg \
		${WRKSRC}/documentation/ttfserver \
		${PREFIX}/lib/wine/documentation
	${INSTALL_DATA} ${WRKSRC}/debugger/README \
		${PREFIX}/lib/wine/documentation/README.debugger
	${INSTALL_DATA} ${WRKSRC}/programs/regapi/README \
		${PREFIX}/lib/wine/documentation/README.regapi
	${INSTALL_SCRIPT} ${WRKSRC}/tools/bug_report.pl \
		${PREFIX}/lib/wine
	${INSTALL_SCRIPT} \
		${WRKSRC}/programs/regapi/regFixer.pl \
		${WRKSRC}/programs/regapi/regRestorer.pl \
		${PREFIX}/lib/wine/reg
	${INSTALL_DATA} ${FILESDIR}/README.patch \
		${FILESDIR}/patch-3.3-sys-ldtshare \
		${FILESDIR}/patch-3.3-sys-sigtrap \
		${FILESDIR}/patch-3.3-sys-fsgs \
		${PREFIX}/lib/wine
	${INSTALL_DATA} ${WRKSRC}/winedefault.reg ${PREFIX}/lib/wine
	${ECHO}
	@${SED} s+%%PREFIX%%+${PREFIX}+g <${PKGMESSAGE}

.include <bsd.port.mk>
