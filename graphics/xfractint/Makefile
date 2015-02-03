# Created by: cacho@mexicano.gdl.iteso.mx
# $FreeBSD$

PORTNAME=	xfractint
PORTVERSION=	20.04p12
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.fractint.org/ftp/current/linux/	\
		http://twegner.dyndns.org/fractint/ftp/current/linux/

MAINTAINER=	onemda@gmail.com
COMMENT=	The Unix port of fractint

USES=		gmake
USE_XORG=	x11 xft

ALL_TARGET=	${PORTNAME}

DESKTOP_ENTRIES+="Xfracint" "${COMMENT}" "" "${PORTNAME}" "" "false"

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/xfractint ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${INSTALL_MAN} ${WRKSRC}/unix/xfractint.man ${STAGEDIR}${PREFIX}/man/man1/${MAN1}
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/fractint.hlp ${STAGEDIR}${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/sstools.ini ${STAGEDIR}${DATADIR}
.for dir in formulas ifs lsystem maps pars
	@cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${STAGEDIR}${DATADIR}
.endfor

.include <bsd.port.mk>
