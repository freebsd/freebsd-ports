# New ports collection makefile for:	eterm-bg
# Date created:        99/06/12
# Whom:                Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	eterm-bg
PORTVERSION=	0.9
CATEGORIES=	graphics x11
MASTER_SITES=	ftp://ftp.enlightenment.org/pub/enlightenment/Eterm/ \
		ftp://ftp.dti.ad.jp/pub/X/enlightenment/Eterm/ \
		ftp://ftp.kddlabs.co.jp/.10/X11/window_manager/enlightenment/Eterm/ \
		ftp://ftp.sogang.ac.kr/.c/tools/X11/Enlightenment/Eterm/
DISTNAME=	Eterm-bg-${PORTVERSION}

MAINTAINER=	taoka@FreeBSD.org

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_X_PREFIX=	yes
RM_FILES1=	014.jpg 40.jpg backwave.jpg blackstone.jpg circuit.jpg nebula.jpg
RM_FILES2=	fourthday.jpg gaia.jpg galleon.jpg nebula.jpg night_of_the_dragon.jpg

post-extract:
	cd ${WRKSRC}/bg/tile; ${RM} ${RM_FILES1}
	cd ${WRKSRC}/bg/scale; ${RM} ${RM_FILES2}

do-install:
	${MKDIR} ${PREFIX}/share/Eterm/pix
	cd ${WRKSRC}; ${INSTALL_DATA} bg/scale/*  ${PREFIX}/share/Eterm/pix
	cd ${WRKSRC}; ${INSTALL_DATA} bg/tile/*  ${PREFIX}/share/Eterm/pix

dd-i:
	for dist in ${DISTFILES}; do \
		${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
			${DISTDIR}/$${dist} \
			${EXTRACT_AFTER_ARGS} -C ${PREFIX}/share/Eterm; \
	done;

.include <bsd.port.mk>
