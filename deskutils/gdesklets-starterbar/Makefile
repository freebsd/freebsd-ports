# $FreeBSD$

PORTNAME=	starterbar
PORTVERSION=	0.31.3
PORTREVISION=	3
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://www.gdesklets.info/archive/
PKGNAMEPREFIX=	gdesklets-
DISTNAME=	starterbar-desklet-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An icon bar for GNOME 2.x where you can put starters into

RUN_DEPENDS=	gdesklets:${PORTSDIR}/deskutils/gdesklets \
		${PYTHON_SITELIBDIR}/xdg/__init__.py:${PORTSDIR}/devel/py-xdg

USE_PYTHON=	yes

SUB_FILES=	pkg-message
SUB_LIST=	NAME="${NAME}"

DATADIR=	${PREFIX}/share/gdesklets
NAME=		StarterBar

LANG=		ca cs de en_CA en_GB es fr hr nl pt pt_BR sq sr sr@Latn sv

do-build:
	@${WRKSRC}/Install_${NAME}_Sensor.bin --nomsg ${WRKSRC}

do-install:
	@${MKDIR} ${DATADIR}/Displays/${NAME}
	${INSTALL_DATA} ${WRKSRC}/README ${DATADIR}/Displays/${NAME}
	${INSTALL_DATA} ${WRKSRC}/*.display ${DATADIR}/Displays/${NAME}
	@${MKDIR} ${DATADIR}/Displays/${NAME}/gfx
	${INSTALL_DATA} ${WRKSRC}/gfx/*.png ${DATADIR}/Displays/${NAME}/gfx
	@${MKDIR} ${DATADIR}/Sensors/${NAME}
	${INSTALL_DATA} ${WRKSRC}/${NAME}/ChangeLog ${DATADIR}/Sensors/${NAME}
	${INSTALL_DATA} ${WRKSRC}/${NAME}/*.desktop ${DATADIR}/Sensors/${NAME}
	${INSTALL_DATA} ${WRKSRC}/${NAME}/*.py ${DATADIR}/Sensors/${NAME}
	@${CP} ${WRKSRC}/${NAME}/.order ${DATADIR}/Sensors/${NAME}
.for ii in ${LANG}
	@${MKDIR} ${DATADIR}/Sensors/${NAME}/locale/${ii}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/${NAME}/locale/${ii}/LC_MESSAGES/*.mo \
		${DATADIR}/Sensors/${NAME}/locale/${ii}/LC_MESSAGES
.endfor
	@${LN} -s ${DATADIR}/Displays/${NAME}/README \
		${DATADIR}/Sensors/${NAME}/README

post-install:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${DATADIR}/Sensors/${NAME}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${DATADIR}/Sensors/${NAME}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
