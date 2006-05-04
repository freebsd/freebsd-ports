# New ports collection makefile for:	gdesklets-starterbar
# Date created:				02 September 2003
# Whom:					Mezz <mezz7@cox.net>
#
# $FreeBSD$
#

PORTNAME=	starterbar
PORTVERSION=	0.31.2
PORTREVISION=	2
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://gdesklets.gnomedesktop.org/files/
PKGNAMEPREFIX=	gdesklets-
DISTNAME=	starterbar-desklet-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An icon bar for GNOME 2.x where you can put starters into

RUN_DEPENDS=	gdesklets:${PORTSDIR}/deskutils/gdesklets \
		${PYTHON_SITELIBDIR}/xdg/__init__.py:${PORTSDIR}/devel/py-xdg

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_X_PREFIX=	yes

NAME=		StarterBar
DATADIR=	${PREFIX}/share/gnome
PKGMESSAGE=	${WRKDIR}/pkg-message
LANG=		ca cs de es fr hr nl pt pt_BR sq sr sr@Latn sv

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
RUN_DEPENDS+=	uuid:${PORTSDIR}/misc/ossp-uuid
.endif

do-build:
	@${WRKSRC}/Install_${NAME}_Sensor.bin --nomsg ${WRKSRC}
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's|uuidgen|uuid|g' \
		${WRKSRC}/${NAME}/IconSet.py
.endif
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${FIND} ${WRKSRC} -name '*.bak' -delete

do-install:
	@${MKDIR} ${DATADIR}/gdesklets/Displays/${NAME}/gfx
.for ii in ${LANG}
	@${MKDIR} ${DATADIR}/gdesklets/Sensors/${NAME}/locale/${ii}/LC_MESSAGES
	@${INSTALL_DATA} ${WRKSRC}/${NAME}/locale/${ii}/LC_MESSAGES/*.mo \
		${DATADIR}/gdesklets/Sensors/${NAME}/locale/${ii}/LC_MESSAGES/
.endfor
	@${INSTALL_DATA} ${WRKSRC}/${NAME}/*.py ${DATADIR}/gdesklets/Sensors/${NAME}/
	@${INSTALL_DATA} ${WRKSRC}/${NAME}/*.desktop ${DATADIR}/gdesklets/Sensors/${NAME}/
	@${CP} ${WRKSRC}/${NAME}/.order ${DATADIR}/gdesklets/Sensors/${NAME}/
	@${INSTALL_DATA} ${WRKSRC}/${NAME}/ChangeLog ${DATADIR}/gdesklets/Sensors/${NAME}/
	@${INSTALL_DATA} ${WRKSRC}/*.display ${DATADIR}/gdesklets/Displays/${NAME}/
	@${INSTALL_DATA} ${WRKSRC}/gfx/*.png ${DATADIR}/gdesklets/Displays/${NAME}/gfx/
	@${INSTALL_DATA} ${WRKSRC}/README ${DATADIR}/gdesklets/Displays/${NAME}/
	@${LN} -s ${DATADIR}/gdesklets/Displays/${NAME}/README \
		${DATADIR}/gdesklets/Sensors/${NAME}/README

post-install:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${DATADIR}/gdesklets/Sensors/${NAME}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${DATADIR}/gdesklets/Sensors/${NAME}
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g ; s|%%NAME%%|${NAME}|g' \
		${FILESDIR}/pkg-message.in > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
