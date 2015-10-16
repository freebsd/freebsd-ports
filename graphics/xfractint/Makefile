# Created by: cacho@mexicano.gdl.iteso.mx
# $FreeBSD$

PORTNAME=	xfractint
PORTVERSION=	20.04p14
CATEGORIES=	graphics
MASTER_SITES=	http://www.fractint.org/ftp/current/linux/ \
		http://twegner.dyndns.org/fractint/ftp/current/linux/

MAINTAINER=	onemda@gmail.com
COMMENT=	Unix port of FractInt

USES=		gmake
USE_XORG=	x11 xft

ALL_TARGET=	${PORTNAME}

DESKTOP_ENTRIES=	"Xfracint" "${COMMENT}" "" "${PORTNAME}" "" "false"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000034
EXTRA_PATCHES=	${FILESDIR}/pre-1000034-libm-patch
.endif

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

.include <bsd.port.post.mk>
