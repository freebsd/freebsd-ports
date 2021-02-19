# Created by: cacho@mexicano.gdl.iteso.mx
# $FreeBSD$

PORTNAME=	xfractint
PORTVERSION=	20.04p16
CATEGORIES=	graphics
MASTER_SITES=	http://www.fractint.net/ftp/current/linux/ \
		http://www.fractint.org/ftp/current/linux/

MAINTAINER=	onemda@gmail.com
COMMENT=	Unix port of FractInt

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig

USES=		gmake xorg
USE_XORG=	x11 xft

ALL_TARGET=	${PORTNAME}

DESKTOP_ENTRIES=	"Xfracint" \
			"${COMMENT}" \
			"" \
			"${PORTNAME}" \
			"" \
			"false"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xfractint ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/unix/xfractint.man \
		${STAGEDIR}${MANPREFIX}/man/man1/xfractint.1
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/fractint.hlp ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/sstools.ini ${STAGEDIR}${DATADIR}
.for dir in formulas ifs lsystem maps pars
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${STAGEDIR}${DATADIR}
.endfor

.include <bsd.port.mk>
