# New ports collection makefile for:	my2cego
# Date created:				Aug 18, 2010
# Whom:					Kurt Jaeger <fbsd-ports@opsec.eu>
#
# $FreeBSD$

PORTNAME=	my2cego
PORTVERSION=	1.0.2
CATEGORIES=	databases
MASTER_SITES=	http://www.lemke-it.com/

MAINTAINER=	fbsd-ports@opsec.eu
COMMENT=	Imports mysqldump files into cego

LIB_DEPENDS=	lfc.1:${PORTSDIR}/devel/lfc \
		lfcxml.1:${PORTSDIR}/devel/lfcxml \
		cego.1:${PORTSDIR}/databases/cego

LICENSE=	GPLv2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	autoconf:env
PLIST_FILES=	bin/my2cego

.include <bsd.port.mk>
