# ex:ts=8
# New ports collection makefile for:    wine
# Date created:         Sa   9 Nov 1996 00:52:22 MET
# Whom:			se
#
# $FreeBSD$
#

PORTNAME=	wine
PORTVERSION=	2002.01.22
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	ALPHA/wine/development
DISTNAME=	Wine-${PORTVERSION:S/.//g}

MAINTAINER=	pfeifer@dbai.tuwien.ac.at

WRKSRC=		${WRKDIR}/wine-${PORTVERSION:S/.//g}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-opengl
CONFIGURE_ENV=	LIBS=-Wl,-rpath,${PREFIX}/lib/wine
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/wine
MAN1=		wine.1 winemaker.1 wmc.1 wrc.1
MAN5=		wine.conf.5
ONLY_FOR_ARCHS=	i386
USE_XPM=	yes
#USE_MESA=	yes
USE_GMAKE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400000
BROKEN=		"Not supported on systems prior to FreeBSD 4.x"
.endif

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

post-patch:
.for D in ./ ../library ../tsx11 ../unicode advapi32 avifil32 comctl32 commdlg crtdll dciman32 ddraw dinput dplay dplayx dsound gdi icmp imagehlp imm32 kernel lzexpand mpr msacm msnet32 msvideo odbc32 ole32 oleaut32 olecli oledlg olepro32 olesvr opengl32 psapi rasapi32 richedit rpcrt4 serialui setupapi shell32 shfolder shlwapi tapi32 ttydrv urlmon user version win32s winaspi wineps wininet winmm winmm/joystick winmm/mcianim winmm/mciavi winmm/mcicda winmm/mciseq winmm/mciwave winmm/midimap winmm/wavemap winmm/wineoss winsock winspool wow32 wsock32 x11drv
	@${PERL} -pi.sofix -e 's/SOVERSION = 1.0/SOVERSION = 1/g' \
		${WRKSRC}/dlls/${D}/Makefile.in
.endfor

post-configure:
	cd ${WRKSRC} && make depend

post-build:
	#cd ${WRKSRC}/programs/regapi && ${GMAKE}
	${SED} '1s/bash/sh/;s-\./\(reg.*\.pl\)-'${PREFIX}/lib/wine/reg/'\1-' <${WRKSRC}/programs/regapi/regSet.sh >${WRKDIR}/regSet.sh

do-install:
	cd ${WRKSRC} && ${GMAKE} install
	${INSTALL_SCRIPT} ${WRKDIR}/regSet.sh ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/documentation/samples/config ${PREFIX}/etc/wine.conf.sample
	[ -f ${PREFIX}/etc/wine.conf ] \
		|| ${INSTALL_DATA} ${PREFIX}/etc/wine.conf.sample ${PREFIX}/etc/wine.conf
	${INSTALL_MAN} ${WRKSRC}/documentation/wine.man ${PREFIX}/man/man1/wine.1
	${INSTALL_MAN} ${WRKSRC}/documentation/wine.conf.man ${PREFIX}/man/man5/wine.conf.5
.if !defined(NOPORTDOCS)
	-@${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
.for i in README ANNOUNCE AUTHORS LICENSE WARRANTY documentation/psdrv.reg
	@${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/${PORTNAME}
.endfor
	${INSTALL_DATA} ${WRKSRC}/debugger/README \
		${PREFIX}/share/doc/${PORTNAME}/README.debugger
	${INSTALL_DATA} ${WRKSRC}/programs/regapi/README \
		${PREFIX}/share/doc/${PORTNAME}/README.regapi
.endif
	-@${MKDIR} ${PREFIX}/lib/wine
	-@${MKDIR} ${PREFIX}/lib/wine/reg
	${INSTALL_SCRIPT} ${WRKSRC}/tools/bug_report.pl \
		${PREFIX}/lib/wine
	${INSTALL_SCRIPT} \
		${WRKSRC}/programs/regapi/regFixer.pl \
		${WRKSRC}/programs/regapi/regRestorer.pl \
		${PREFIX}/lib/wine/reg
	${INSTALL_DATA} ${WRKSRC}/winedefault.reg ${PREFIX}/lib/wine
	${ECHO}
	@${SED} s+%%PREFIX%%+${PREFIX}+g <${PKGMESSAGE}

.include <bsd.port.post.mk>
