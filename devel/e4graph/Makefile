# ex:ts=8
# Ports collection makefile for:	e4graph
# Date created:			Jul 16, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	e4graph
PORTVERSION=	1.0a6
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

BROKEN=		"Does not compile"

BUILD_DEPENDS=	${LOCALBASE}/lib/libmk4.a:${PORTSDIR}/databases/metakit
LIB_DEPENDS=	tcl83.1:${PORTSDIR}/lang/tcl83 \
		expat.4:${PORTSDIR}/textproc/expat2

USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/all
CONFIGURE_ARGS=	--with-metakit=${PREFIX} \
		--with-tcl=${PREFIX} --enable-tcl \
		--with-expat=${PREFIX} --enable-xml
MAKEFILE=	makefile
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
