# ex:ts=8
# New ports collection makefile for:    wine
# Date created:         Sa   9 Nov 1996 00:52:22 MET
# Whom:			se
#
# $FreeBSD$
#

PORTNAME=	wine
PORTVERSION=	0.9.7
PORTEPOCH=	1
CATEGORIES=	emulators
MASTER_SITES=	http://ibiblio.org/pub/linux/system/emulators/wine/ \
		${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gerald@FreeBSD.org
COMMENT=	Microsoft Windows compatibility layer for Unix-like systems

# wine/dlls/glut32/ depends on the presence of libglut.
LIB_DEPENDS=	lcms.1:${PORTSDIR}/graphics/lcms \
		glut.4:${PORTSDIR}/graphics/libglut

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS=-I${PREFIX}/include LDFLAGS=-L${PREFIX}/lib LIBS=-Wl,-rpath,${PREFIX}/lib/wine
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/wine
MAN1=		widl.1 wine.1 winebuild.1 winedbg.1 winedump.1 winegcc.1 \
		winemaker.1 wineserver.1 wmc.1 wrc.1
ONLY_FOR_ARCHS=	i386
USE_BISON=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GL=		yes
USE_XPM=	yes

SUB_FILES=	pkg-message wine.sh
PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 503000
IGNORE=		fails to work on versions of FreeBSD before 5.3 (due to problems with threading support)
.endif

pre-build:
	cd ${WRKSRC} && make depend

post-install:
	-@${MKDIR} ${PREFIX}/etc/rc.d
	${RM} ${PREFIX}/man/man1/wineg++.1
.if !defined(NOPORTDOCS)
	-@${MKDIR} ${DOCSDIR}
.for i in README ANNOUNCE AUTHORS LICENSE
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.for i in progman uninstaller wcmd winedbg winemine
	${INSTALL_DATA} ${WRKSRC}/programs/${i}/README ${DOCSDIR}/README.${i}
.endfor
	${INSTALL_DATA} ${WRKSRC}/tools/winedump/README ${DOCSDIR}/README.winedump
.endif
	@${INSTALL_SCRIPT} ${WRKSRC}/tools/bug_report.pl ${PREFIX}/lib/wine
	@${INSTALL_SCRIPT} ${WRKDIR}/wine.sh ${PREFIX}/etc/rc.d/000.wine.sh
	@${ECHO}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
