# Created by: alepulver
# $FreeBSD$

PORTNAME=	wxdfast
PORTVERSION=	0.6.0
PORTREVISION=	6
CATEGORIES=	ftp www
MASTER_SITES=	SF/dfast/wxDownload%20Fast/${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multithread and multi-platform download manager

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_WX=		2.8+
WX_CONF_ARGS=	relative
WX_UNICODE=	yes
USES=		gettext
USE_AUTOTOOLS=	aclocal automake autoconf libtoolize
ACLOCAL_ARGS=	-I ${LOCALBASE}/share/locale
AUTOMAKE_ARGS=	--add-missing --copy --force-missing --foreign
LIBTOOLIZE_ARGS=--copy --force
CONFIGURE_ENV=	WXRC="${WXRC_CMD}"

post-patch:
	@${REINPLACE_CMD} -e \
		's|pt_BR||' ${WRKSRC}/man/Makefile.am
	@${REINPLACE_CMD} -e \
		's|^CFLAGS |AM_CFLAGS | ; \
		 s|^CXXFLAGS |AM_CXXFLAGS | ; \
		 s|-O2 ||' ${WRKSRC}/src/Makefile.am

.include <bsd.port.mk>
