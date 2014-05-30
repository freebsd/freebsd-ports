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

MAN1=		${PORTNAME}.1

DESKTOP_ENTRIES+="Xfracint" "${COMMENT}" "" "${PORTNAME}" "" "false"

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
EXTRA_PATCHES+=	${FILESDIR}/extra-unix__fpu087.c
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/xfractint ${PREFIX}/bin/${PORTNAME}
	@${INSTALL_MAN} ${WRKSRC}/unix/xfractint.man ${PREFIX}/man/man1/${MAN1}
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/fractint.hlp ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/sstools.ini ${DATADIR}
.for dir in formulas ifs lsystem maps pars
	@cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${DATADIR}
.endfor

.include <bsd.port.post.mk>
