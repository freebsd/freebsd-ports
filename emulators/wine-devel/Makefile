# ex:ts=8
# New ports collection makefile for:    wine
# Date created:         Sa   9 Nov 1996 00:52:22 MET
# Whom:			se
#
# $FreeBSD$
#

PORTNAME=	wine
PORTVERSION=	20031016
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	ALPHA/wine/development
DISTNAME=	Wine-${PORTVERSION}

MAINTAINER=	gerald@FreeBSD.org
COMMENT=	Microsoft Windows 3.1/95/98/NT/2000 emulator for Unix

WRKSRC=		${WRKDIR}/wine-${PORTVERSION}
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS=-L${PREFIX}/lib LIBS=-Wl,-rpath,${PREFIX}/lib/wine
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/wine
MAN1=		wine.1 winebuild.1 winemaker.1 wmc.1 wrc.1
MAN5=		wine.conf.5
ONLY_FOR_ARCHS=	i386
USE_XPM=	yes
USE_BISON=	yes
USE_GMAKE=	yes
USE_GCC=	3.3
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400000
BROKEN=		"Not supported on systems prior to FreeBSD 4.x"
.endif

.if defined(DEBUG)
STRIP=
.else
CFLAGS=	-O2

pre-extract:
	@${ECHO} "DEBUG has not been set, building without debug info."
	@${ECHO} "This makes the disk footprint and packages much smaller,"
	@${ECHO} "but debugging harder. If Wine crashes and you need to"
	@${ECHO} "generate a backtrace, please rebuild with DEBUG defined."
.endif

post-extract:
	@${SED} -e "s=%%PREFIX%%=${PREFIX}=g" ${FILESDIR}/wine.sh \
		> ${WRKSRC}/wine.sh

post-configure:
	cd ${WRKSRC} && make depend

post-build:
	${SED} 's-\./\(reg.*\.pl\)-'${PREFIX}/lib/wine/reg/'\1-' \
		${WRKSRC}/programs/regapi/regSet.sh > ${WRKDIR}/regSet.sh

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
.for i in regapi wcmd winedbg
	${INSTALL_DATA} ${WRKSRC}/programs/${i}/README \
		${PREFIX}/share/doc/${PORTNAME}/README.${i}
.endfor
	${INSTALL_DATA} ${WRKSRC}/tools/winedump/README \
		${PREFIX}/share/doc/${PORTNAME}/README.winedump
.endif
	-@${MKDIR} ${PREFIX}/lib/wine/reg
	${INSTALL_SCRIPT} ${WRKSRC}/tools/bug_report.pl \
		${PREFIX}/lib/wine
	${INSTALL_PROGRAM} ${WRKSRC}/programs/regapi/regapi.exe.so ${PREFIX}/lib/wine
	${INSTALL_SCRIPT} \
		${WRKSRC}/programs/regapi/regFixer.pl \
		${WRKSRC}/programs/regapi/regRestorer.pl \
		${PREFIX}/lib/wine/reg
	${INSTALL_DATA} ${WRKSRC}/winedefault.reg ${PREFIX}/lib/wine
	${ECHO}
	@${SED} s+%%PREFIX%%+${PREFIX}+g <${PKGMESSAGE}

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/wine.sh ${PREFIX}/etc/rc.d/000.wine.sh

.include <bsd.port.post.mk>
