# New ports collection makefile for:	xcircuit
# Date created:		3 Apr 1998
# Whom:			giffunip@asme.org
#
# $FreeBSD$
#

PORTNAME=	xcircuit
PORTVERSION=	2.0b4
CATEGORIES=	cad
MASTER_SITES=	ftp://bach.ece.jhu.edu/pub/tim/xcircuit/ \
		http://bach.ece.jhu.edu/~tim/programs/xcircuit/archive/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm
RUN_DEPENDS=	gs:${PORTSDIR}/print/ghostscript55

USE_BZIP2=	yes
USE_IMAKE=	yes
XMKMF=		xmkmf

MAN1=		xcircuit.1

post-patch:
	@${PERL} -pi -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/Imakefile

post-install:
	@${MKDIR} ${PREFIX}/share/examples/xcircuit
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/xcircuit

.include <bsd.port.mk>
