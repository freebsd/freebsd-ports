# New ports collection makefile for:   Wah!Cade
# Date created:		24 August 2006
# Whom:			Nathaniel Roark <robb_force@holybuffalo.net>
#
# $FreeBSD$
#

PORTNAME=	wahcade
PORTVERSION=	0.16
CATEGORIES=	emulators
MASTER_SITES=	http://www.anti-particle.com/projects/wahcade/

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	A frontend for almost any emulator (MameWAH clone)

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pygtk.pth:${PORTSDIR}/x11-toolkits/py-gtk2 \
		${PYTHON_SITELIBDIR}/cElementTree.so:${PORTSDIR}/devel/py-celementtree

USE_PYTHON=	2.4+
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS=	MPLAYER "Install mplayer for movie playback" off \
		PSYCHO "Enable psycho optimization" on

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if defined(WITH_MPLAYER)
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
.endif

.if !defined(WITHOUT_PSYCHO) && ${ARCH} == "i386"
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psyco/_psyco.so:${PORTSDIR}/devel/py-psyco
.endif

do-build:
	@(${ECHO_CMD} "#!${SH}"; \
	  ${ECHO_CMD} "cd ${DATADIR} || exit 1"; \
	  ${ECHO_CMD} 'exec ${PYTHON_CMD} ${PORTNAME}.py "$$@"') \
	  > ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
.for f in *.py config.dist glade locale pixmaps templates
	${CP} -R ${WRKSRC}/${f} ${DATADIR}
.endfor
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop \
		${PREFIX}/share/applications
	@${FIND} ${DATADIR} -type d -print0 | ${XARGS} -0 ${CHMOD} ${BINMODE}
	@${FIND} ${DATADIR} -type f -print0 | ${XARGS} -0 ${CHMOD} ${SHAREMODE}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/* ${DOCSDIR}
	@${FIND} ${DOCSDIR} -type d -print0 | ${XARGS} -0 ${CHMOD} ${BINMODE}
	@${FIND} ${DOCSDIR} -type f -print0 | ${XARGS} -0 ${CHMOD} ${SHAREMODE}
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
