# Created by: alepulver
# $FreeBSD$

PORTNAME=	wxdfast
PORTVERSION=	0.6.0
PORTREVISION=	12
CATEGORIES=	ftp www
MASTER_SITES=	SF/dfast/wxDownload%20Fast/${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multithread and multi-platform download manager

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_armv6=		fails to compile: no matching member function for call to 'Read'
BROKEN_armv7=		fails to compile: no matching member function for call to 'Read'

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		autoreconf compiler:c++11-lang gettext libtool
USE_WX=		2.8+
WX_CONF_ARGS=	relative
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	WXRC="${WXRC_CMD}"
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e \
		's|pt_BR||' ${WRKSRC}/man/Makefile.am
	@${REINPLACE_CMD} -e \
		's|^CFLAGS |AM_CFLAGS | ; \
		 s|^CXXFLAGS |AM_CXXFLAGS | ; \
		 s|-O2 ||' ${WRKSRC}/src/Makefile.am

.include <bsd.port.mk>
