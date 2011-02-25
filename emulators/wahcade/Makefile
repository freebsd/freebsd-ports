# New ports collection makefile for:   Wah!Cade
# Date created:		24 August 2006
# Whom:			Nathaniel Roark <robb_force@holybuffalo.net>
#
# $FreeBSD$
#

PORTNAME=	wahcade
PORTVERSION=	0.28
PORTREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	http://www.anti-particle.com/projects/wahcade/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A frontend for almost any emulator (MameWAH clone)

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2 \
		${PYTHON_SITELIBDIR}/cElementTree.so:${PORTSDIR}/devel/py-celementtree \
		${PYTHON_SITELIBDIR}/chardet/__init__.py:${PORTSDIR}/textproc/py-chardet

USE_PYTHON=	2.5+
WANT_GSTREAMER=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS=	GSTREAMER "Install gstreamer for video & music playback" on \
		PSYCHO "Enable psycho optimization" on \
		PYGAME "Install pygame for joystick support" off

WRAPPERS=	wahcade wahcade-layout-editor wahcade-setup

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GSTREAMER)
USE_GSTREAMER=	python
.endif

.if !defined(WITHOUT_PSYCHO) && ${ARCH} == "i386"
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psyco/_psyco.so:${PORTSDIR}/devel/py-psyco
.endif

.if defined(WITH_PYGAME)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game
.endif

post-extract:
	@cd ${WRKSRC} && ${RM} install && ${MV} *.desktop ..

do-build:
	@${MKDIR} ${WRKDIR}/bin
.for f in ${WRAPPERS}
	@(${ECHO_CMD} "#!${SH}"; \
	  ${ECHO_CMD} "cd ${DATADIR} || exit 1"; \
	  ${ECHO_CMD} 'exec ${PYTHON_CMD} ${f}.py "$$@"') \
	  > ${WRKDIR}/bin/${f}
.endfor

do-install:
.for f in ${WRAPPERS}
	${INSTALL_SCRIPT} ${WRKDIR}/bin/${f} ${PREFIX}/bin
.endfor
	${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/* ${DATADIR}
# Needs write permission for the user as they are copied to "~/.wahcade".
	@${FIND} ${DATADIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@${FIND} ${DATADIR} -type f -print0 | ${XARGS} -0 ${CHMOD} 644
.if !defined(NOPORTDOCS)
	${LN} -sf ${DATADIR}/doc ${DOCSDIR}
.endif
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKDIR}/*.desktop ${PREFIX}/share/applications
	${LN} -sf ${DATADIR}/pixmaps/wahcade.png ${PREFIX}/share/pixmaps

.include <bsd.port.post.mk>
