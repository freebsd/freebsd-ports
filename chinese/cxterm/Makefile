# ex:ts=8
# Ports collection makefile for:  cxterm
# Date created:			  Sat Aug 10, 1996
# Whom:				  David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

PORTNAME=	cxterm
PORTVERSION=	5.0.3
CATEGORIES=	chinese x11
# unresponceive mastersite: ftp://ftp.ifcss.org/pub/software/x-win/cxterm/
MASTER_SITES=	ftp://ftp.cuhk.hk/pub/chinese/ifcss/software/x-win/cxterm/ \
		ftp://ftp.edu.tw/Chinese/ifcss/software/x-win/cxterm/  \
		ftp://ftp.mpi-sb.mpg.de/pub/chinese/mirror/ftp.ifcss.org/software/x-win/cxterm/
DISTNAME=	cxterm5.0.p3

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	cxterm-5.0.p3-color.patch.gz	# cxterm-5.0-hz-patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An xterm that speaks Chinese

BUILD_DEPENDS=	bdftopcf:${X_CLIENTS_PORT}
RUN_DEPENDS=	mkfontdir:${X_CLIENTS_PORT}

WRKSRC=		${WRKDIR}/cxterm-5.0
USE_IMAKE=	yes

MAN1=		cit2tit.1 cxterm.1 hzimctrl.1 tit2cit.1
MANCOMPRESSED=	yes

XMKMF=		xmkmf
ALL_TARGET=	xrelease Makefiles includes all

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/CXterm.sh  \
			${PREFIX}/bin/CXterm
	# standard X11 place
	${INSTALL_DATA} ${WRKDIR}/CXterm.ad  \
			${PREFIX}/lib/X11/app-defaults/CXterm
	# standard CXterm place
	${INSTALL_DATA} ${WRKDIR}/CXterm.ad  \
			${PREFIX}/lib/X11/cxterm.dic/
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/cxterm
	${INSTALL_DATA} ${WRKSRC}/Doc/CXTERM.FAQ ${PREFIX}/share/doc/cxterm
	${INSTALL_DATA} ${WRKSRC}/Doc/input.doc ${PREFIX}/share/doc/cxterm
.endif

.include <bsd.port.mk>
