# ex:ts=8
# Ports collection makefile for:	e4graph
# Date created:			Jul 16, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	e4graph
PORTVERSION=	1.0a8
PORTREVISION=	1
CATEGORIES=	devel tcl84
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C++ library that persistently stores graph like data

BUILD_DEPENDS=	${LOCALBASE}/lib/libmk4.so:${PORTSDIR}/databases/metakit
LIB_DEPENDS=	tcl84.1:${PORTSDIR}/lang/tcl84 \
		expat.4:${PORTSDIR}/textproc/expat2
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${DISTNAME}/all

USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-metakit=${LOCALBASE} \
		--with-tcl=${LOCALBASE}/lib/tcl8.4 --enable-tcl \
		--with-expat=${LOCALBASE} --enable-xml
CFLAGS+=	-fpermissive -I${LOCALBASE}/include/tcl8.4
MAKEFILE=	makefile
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|=-O$$|="$${CFLAGS}"|g' ${WRKSRC}/configure

.include <bsd.port.mk>
