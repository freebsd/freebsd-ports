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

BUILD_DEPENDS=	${LOCALBASE}/lib/libmk4.so:${PORTSDIR}/databases/metakit
LIB_DEPENDS=	tcl83.1:${PORTSDIR}/lang/tcl83 \
		expat.4:${PORTSDIR}/textproc/expat2
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${DISTNAME}/all

USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-metakit=${LOCALBASE} \
		--with-tcl=${LOCALBASE} --enable-tcl \
		--with-expat=${LOCALBASE} --enable-xml
CFLAGS+=	-fpermissive
MAKEFILE=	makefile
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
