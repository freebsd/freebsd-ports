# New ports collection makefile for:	vilearn
# Date created:		12 Dec 1997
# Whom:			Ian Vaudrey <i.vaudrey@bigfoot.com>
#
# $FreeBSD$
#

PORTNAME=	vilearn
PORTVERSION=	1.0
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.funet.fi/pub/Linux/util/networking/util-swan/pub/misc/ \
		ftp://ftp.mcc.ac.uk/pub/linux/fi.mirror/util/networking/util-swan/pub/misc/ \
		ftp://ftp.tu-chemnitz.de/pub/linux/funet-mirror/util/networking/util-swan/pub/misc/
DISTFILES=	${PORTNAME}.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An interactive tutorial for the vi editor

EXTRACT_CMD=	uncompress
EXTRACT_BEFORE_ARGS=	-c
EXTRACT_AFTER_ARGS=	| tail -n 1759 | sh

MAKE_ARGS=	BINDIR="${PREFIX}/bin" \
		MANDIR="${MAN1PREFIX}/man" \
		TUTORIALS="${DATADIR}"

MAN1=		vilearn.1

.include <bsd.port.mk>
