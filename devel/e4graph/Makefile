# ex:ts=8
# Ports collection makefile for:	e4graph
# Date created:			Jul 16, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	e4graph
PORTVERSION=	1.0a6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/all
CONFIGURE_ARGS=	--with-metakit=${PREFIX} \
		--with-tcl=${PREFIX} --enable-tcl \
		--with-expat=${PREFIX} --enable-xml
MAKEFILE=	makefile
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
