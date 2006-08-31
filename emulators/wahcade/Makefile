# New ports collection makefile for:   Wah!Cade
# Date created:		24 August 2006
# Whom:			Nathaniel Roark <robb_force@holybuffalo.net>
#
# $FreeBSD$
#

PORTNAME=		wahcade
PORTVERSION=		0.11
CATEGORIES=		emulators
MASTER_SITES=		http://www.anti-particle.com/projects/wahcade/
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}
DISTNAME=		${PORTNAME}-${PORTVERSION}

MAINTAINER=		robb_force@holybuffalo.net
COMMENT=		A frontend for almost any emulator (MameWAH clone)

RUN_DEPENDS=		${PYTHON_SITELIBDIR}/pygtk.pth:${PORTSDIR}/x11-toolkits/py-gtk2 \
			${PYTHON_SITELIBDIR}/cElementTree.so:${PORTSDIR}/devel/py-celementtree

WRKSRC=			${WRKDIR}/${PORTNAME}
USE_PYTHON=		2.4+
NO_BUILD=		yes
OPTIONS=		MPLAYER "For movie playback." off
# Bypass infrasructure bug (taken from www/py-turbogears)
OPTIONSFILE=		${PORT_DBDIR}/py-${PORTNAME}/options
BINDIR=			${PREFIX}/bin

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
WITHOUT_PSYCO=		yes
.endif

# required for PSYCO
.ifndef(WITHOUT_PSYCO)
RUN_DEPENDS+=		${PYTHON_SITELIBDIR}/psyco/_psyco.so:${PORTSDIR}/devel/py-psyco
.endif

.if defined(WITH_MPLAYER)
RUN_DEPENDS+=		mplayer:${PORTSDIR}/multimedia/mplayer
.endif

pre-everything::
.ifndef(WITHOUT_PSYCO)
	@${ECHO_MSG} '===> Define WITHOUT_PSYCO to disable devel/py-psyco optimization'
.endif

# setup.py seems to be for windows, so run the patched install script
do-install:
	#wahcade start script
	echo "#!${BINDIR}/bash" > ${BINDIR}/${PORTNAME}
	echo "cd ${DATADIR}" >> ${BINDIR}/${PORTNAME}
	echo "python ${PORTNAME} \$*" >> ${BINDIR}/${PORTNAME}
	${CHMOD} 755 ${BINDIR}/${PORTNAME}

	#install files
	${INSTALL} -d -v ${DATADIR}
	${INSTALL} -m 644 ${WRKSRC}/*.py ${DATADIR}
	${INSTALL} -m 755 ${WRKSRC}/${PORTNAME} ${DATADIR}
	${INSTALL} -d -v ${DATADIR}/config.dist
	${INSTALL} -d -v ${DATADIR}/config.dist/ctrlr
	${INSTALL} -d -v ${DATADIR}/config.dist/files
	${INSTALL} -d -v ${DATADIR}/config.dist/ini
	${INSTALL} -d -v ${DATADIR}/config.dist/layouts
	${INSTALL} -d -v ${DATADIR}/config.dist/layouts/classic\ 640x480
	${INSTALL} -d -v ${DATADIR}/config.dist/layouts/classic\ 800x600
	${INSTALL} -d -v ${DATADIR}/config.dist/layouts/classic\ 1024x768
	${INSTALL} -d -v ${DATADIR}/config.dist/layouts/cpviewer
	${INSTALL} -d -v ${DATADIR}/pixmaps
	${INSTALL} -m 644 ${WRKSRC}/config.dist/*.ini ${DATADIR}/config.dist
	${INSTALL} -m 644 ${WRKSRC}/config.dist/ctrlr/*.ini ${DATADIR}/config.dist/ctrlr
	#${INSTALL} -m 644 ${WRKSRC}/config.dist/files/* ${DATADIR}/config.dist/files
	${INSTALL} -m 644 ${WRKSRC}/config.dist/ini/*.ini ${DATADIR}/config.dist/ini
	${INSTALL} -m 644 ${WRKSRC}/config.dist/layouts/classic\ 640x480/* ${DATADIR}/config.dist/layouts/classic\ 640x480
	${INSTALL} -m 644 ${WRKSRC}/config.dist/layouts/classic\ 800x600/* ${DATADIR}/config.dist/layouts/classic\ 800x600
	${INSTALL} -m 644 ${WRKSRC}/config.dist/layouts/classic\ 1024x768/* ${DATADIR}/config.dist/layouts/classic\ 1024x768
	${INSTALL} -m 644 ${WRKSRC}/config.dist/layouts/cpviewer/* ${DATADIR}/config.dist/layouts/cpviewer
	${INSTALL} -m 644 ${WRKSRC}/pixmaps/*.png ${DATADIR}/pixmaps

	#compile everything python
	${PYTHON_CMD} -c "import compileall; compileall.compile_dir('${DATADIR}')"

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
