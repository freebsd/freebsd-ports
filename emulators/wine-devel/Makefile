# ex:ts=8
# New ports collection makefile for:    wine
# Date created:         Sa   9 Nov 1996 00:52:22 MET
# Whom:			se
#
# $FreeBSD$
#

PORTNAME=	wine
PORTVERSION=	2002.12.19
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	ALPHA/wine/development
DISTNAME=	Wine-${PORTVERSION:S/.//g}

MAINTAINER=	gerald@FreeBSD.org

WRKSRC=		${WRKDIR}/wine-${PORTVERSION:S/.//g}
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS=-Wl,-rpath,${PREFIX}/lib/wine
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/wine
MAN1=		wine.1 winemaker.1 wmc.1 wrc.1
MAN5=		wine.conf.5
ONLY_FOR_ARCHS=	i386
USE_XPM=	yes
#USE_MESA=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

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
.for D in ../library ../unicode
	@${REINPLACE_CMD} -e 's/SOVERSION = 1.0/SOVERSION = 1/g' \
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
.for i in README ANNOUNCE AUTHORS LICENSE
	@${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/${PORTNAME}
.endfor
	${INSTALL_DATA} ${WRKSRC}/programs/regapi/README \
		${PREFIX}/share/doc/${PORTNAME}/README.regapi
	${INSTALL_DATA} ${WRKSRC}/tools/winedump/README \
		${PREFIX}/share/doc/${PORTNAME}/README.winedump
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
