# New ports collection makefile for:	my2cego
# Date created:				Aug 18, 2010
# Whom:					Kurt Jaeger <fbsd-ports@opsec.eu>
#
# $FreeBSD$

PORTNAME=	my2cego
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.lemke-it.com/

MAINTAINER=	fbsd-ports@opsec.eu
COMMENT=	Imports mysqldump files into cego

LIB_DEPENDS=	Base.1:${PORTSDIR}/devel/cego-base \
		XML.1:${PORTSDIR}/devel/cego-xml \
		cego.1:${PORTSDIR}/databases/cego

LICENSE=	GPLv2
WRKSRC=		${WRKDIR}/my2cego
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	autoconf:267:env
PLIST_FILES=	bin/my2cego

.include <bsd.port.mk>
