# New ports collection makefile for:	gdeskcal-skins
# Date created:		04 May 2003
# Whom:			Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
#
# $FreeBSD$
#

PORTNAME=	gdeskcal-skins
PORTVERSION=	0.56
PORTREVISION=	3
CATEGORIES=	deskutils python gnome
MASTER_SITES=	http://www.pycage.de/download/skins/gdeskcal/
DISTNAME=
DISTFILES=	gnometheme.tar.gz \
		SimpleForDark.tar.gz \
		e_01.tar.gz \
		light_01.tar.gz \
		light_02.tar.gz \
		tnf.tar.gz \
		redskin.tar.gz \
		tiny_and_simple.tar.gz \
		LCD.tar.gz \
		grey_skin.tar.gz \
		gorillerat.tar.gz \
		august.tar.gz \
		august_big.tar.gz \
		XFCE.tar.gz \
		miderat_RTL.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Skins for gdeskcal

RUN_DEPENDS=	${X11BASE}/bin/gdeskcal:${PORTSDIR}/deskutils/gdeskcal

USE_PYTHON=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix
NO_BUILD=	yes

DATA_DIRS=	GNOME Grey_skin LCD Red_skin SimpleForDark XFCE august \
		august_big_no_backgr e gorillerat light_01 light_02 \
		miderat_RTL tiny_and_simple tnf

do-install:
	@${MKDIR} ${PREFIX}/share/gnome/gdeskcal
.for d in ${DATA_DIRS}
		@${MKDIR} ${PREFIX}/share/gnome/gdeskcal/skins/${d}
		@cd ${WRKSRC}/${d} && ${FIND} . | \
	    		${CPIO} --quiet -pdm -L -R ${LIBOWN}:${LIBGRP}  \
			${PREFIX}/share/gnome/gdeskcal/skins/${d}
.endfor

.include <bsd.port.mk>
