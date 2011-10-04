# ex:ts=8
# Ports collection makefile for:  cxterm
# Date created:			  Sat Aug 10, 1996
# Whom:				  David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

PORTNAME=	cxterm
PORTVERSION=	5.0.3
PORTREVISION=	3
CATEGORIES=	chinese x11
MASTER_SITES=	ftp://ftp.cuhk.hk/pub/chinese/ifcss/software/x-win/cxterm/ \
		http://www.525183.com/freebsd/cxterm/ \
		http://www.chinatinco.com/freebsd/cxterm/ \
		http://525183.serverbox.org/freebsd/cxterm/
DISTNAME=	cxterm5.0.p3

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	cxterm-5.0.p3-color.patch.gz	# cxterm-5.0-hz-patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	sunrychen@gmail.com
COMMENT=	An xterm that speaks Chinese

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

BROKEN=		does not compile

WRKSRC=		${WRKDIR}/cxterm-5.0
USE_IMAKE=	yes
USE_XORG=	x11 xext xpm xmu xaw xt sm ice

PORTDOCS=	CXTERM.FAQ input.doc

MAN1=		cit2tit.1 cxterm.1 hzimctrl.1 tit2cit.1
MANCOMPRESSED=	yes

XMKMF=		xmkmf
ALL_TARGET=	xrelease Makefiles includes all
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		Coredump during build on ia64
.endif

.if ${OSVERSION} > 900007
BROKEN=		fails to build with new utmpx
.endif

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/CXterm.sh ${PREFIX}/bin/CXterm
	# standard X11 place
	${INSTALL_DATA} ${WRKDIR}/CXterm.ad ${PREFIX}/lib/X11/app-defaults/CXterm
	# standard CXterm place
	${INSTALL_DATA} ${WRKDIR}/CXterm.ad ${PREFIX}/lib/X11/cxterm.dic/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/Doc && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
