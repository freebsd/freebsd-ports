# ex:ts=8
# Ports collection makefile for:  cxterm
# Version required: 0.0
# Date created:			  Sat Aug 10, 1996
# Whom:				  David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

DISTNAME=	cxterm5.0.p3
PKGNAME=	zh-cxterm-5.0.3
CATEGORIES=	chinese x11
MASTER_SITES=	ftp://ftp.ifcss.org/pub/software/x-win/cxterm/  \
		ftp://ftp.cuhk.hk/pub/chinese/ifcss/software/x-win/cxterm/ \
		ftp://ftp.edu.tw/Chinese/ifcss/software/x-win/cxterm/  \
		ftp://ftp.mpi-sb.mpg.de/pub/chinese/mirror/ftp.ifcss.org/software/x-win/cxterm/

MAINTAINER=	obrien@FreeBSD.org

WRKSRC=		${WRKDIR}/cxterm-5.0
USE_IMAKE=	yes

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
