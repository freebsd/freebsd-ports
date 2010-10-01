# New ports collection makefile for:	xfractint
# Date created:		7 Sept 1995
# Whom:			cacho@mexicano.gdl.iteso.mx
#
# $FreeBSD$
#

PORTNAME=	xfractint
PORTVERSION=	20.04p09
CATEGORIES=	graphics
MASTER_SITES=	http://www.fractint.org/ftp/current/linux/ \
		http://twegner.dyndns.org/fractint/ftp/current/linux/

MAINTAINER=	onemda@gmail.com
COMMENT=	The Unix port of fractint

USE_GMAKE=	yes
USE_GZIP=	yes
USE_XORG=	x11

ALL_TARGET=	${PORTNAME}

MAN1=		${PORTNAME}.1

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/xfractint ${PREFIX}/bin/${PORTNAME}
	@${INSTALL_MAN} ${WRKSRC}/unix/xfractint.man ${PREFIX}/man/man1/${MAN1}
	@${MKDIR} ${DATADIR}
	@${CP} ${WRKSRC}/fractint.hlp ${DATADIR}
	@${CP} ${WRKSRC}/sstools.ini ${DATADIR}
	@${CP} -R ${WRKSRC}/formulas ${DATADIR}
	@${CP} -R ${WRKSRC}/ifs ${DATADIR}
	@${CP} -R ${WRKSRC}/lsystem ${DATADIR}
	@${CP} -R ${WRKSRC}/maps ${DATADIR}
	@${CP} -R ${WRKSRC}/pars ${DATADIR}

.include <bsd.port.mk>
