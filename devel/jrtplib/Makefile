# New ports collection makefile for:   jrtplib
# Date created:        4 March 2003
# Whom:                Petr Holub <hopet@ics.muni.cz>
#
# $FreeBSD$
#

PORTNAME=	jrtplib
PORTVERSION=	3.1.0
CATEGORIES=	devel
MASTER_SITES=	http://research.edm.luc.ac.be/jori/jrtplib/

MAINTAINER=	hopet@ics.muni.cz
COMMENT=	Object-oriented RTP library written in C++

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
NO_FILTER_SHLIBS=	yes
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--disable-jthread

.include <bsd.port.mk>
