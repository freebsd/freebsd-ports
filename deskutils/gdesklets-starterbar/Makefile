# New ports collection makefile for:	gdesklets-starterbar
# Date created:				02 September 2003
# Whom:					Mezz <mezz7@cox.net>
#
# $FreeBSD$
#

PORTNAME=	starterbar
PORTVERSION=	0.22.1
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://gdesklets.gnomedesktop.org/files/
PKGNAMEPREFIX= gdesklets-
DISTNAME=	starterbar-desklet-${PORTVERSION}

MAINTAINER=	mezz7@cox.net
COMMENT=	An icon bar for GNOME 2.x where you can put starters into

RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/gdesklets-core.pc:${PORTSDIR}/deskutils/gdesklets

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes

NAME=		StarterBar
DATADIR=	${PREFIX}/share/gnome
LANG=		de fr pt sq sr sr@Latn sv

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		"Requires FreeBSD 5.0 or later, because of uuidgen command first appeared in FreeBSD 5.0"
.endif

do-build:
	@${WRKSRC}/Install_${NAME}_Sensor.bin --nomsg ${WRKSRC}
	@${PATCH} ${WRKSRC}/${NAME}/Icon.py < ${FILESDIR}/${NAME}::Icon.py
	@${PATCH} ${WRKSRC}/${NAME}/IconTheme.py < ${FILESDIR}/${NAME}::IconTheme.py
	@${PATCH} ${WRKSRC}/${NAME}/__init__.py < ${FILESDIR}/${NAME}::__init__.py
	@${REINPLACE_CMD} -e 's|%%X11BASE%%|${X11BASE}|g' \
		${WRKSRC}/${NAME}/IconTheme.py
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
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
