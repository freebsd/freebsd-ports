# New ports collection makefile for:	brainworkshop
# Date created:		27 Oct 2008
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	brainworkshop
PORTVERSION=	4.4
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Brain%20Workshop%20${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Free open-source version of the Dual N-Back mental exercise

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pyglet/__init__.py:${PORTSDIR}/graphics/py-pyglet

USE_ZIP=	yes
NO_BUILD=	yes
USE_DOS2UNIX=	brainworkshop.pyw

USE_PYTHON=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

PORTSCOUT=	skipv:4.22

post-patch:
	@${REINPLACE_CMD} -e '/^FOLDER_RES = / s|res|${DATADIR}|; \
		/^FOLDER_DATA = / s|.data.|os.environ["HOME"]+"/.brainworkshop"|' \
		${WRKSRC}/brainworkshop.pyw

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/brainworkshop.pyw ${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/res/* ${DATADIR}/

.include <bsd.port.mk>
