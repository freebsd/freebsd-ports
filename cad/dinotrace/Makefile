# New ports collection makefile for:	dinotrace
# Date created:		July 05, 2004
# Whom:			Joachim Strombergson <watchman@ludd.ltu.se>
#
# $FreeBSD$
#

PORTNAME=	dinotrace
PORTVERSION=	9.2.b
CATEGORIES=	cad
MASTER_SITES=	http://www.veripool.com/ftp/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	watchman@ludd.luth.se
COMMENT=	A graphical signal trace waveform viewer

USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes
USE_MOTIF=	yes
USE_PERL5_BUILD=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes

INFO=		dinotrace
PLIST_FILES=	bin/dinotrace

.include <bsd.port.mk>
