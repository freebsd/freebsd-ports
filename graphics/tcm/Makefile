# New ports collection makefile for:	tcm
# Date created:				18 July 2001
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	tcm
PORTVERSION=	2.01
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.cs.utwente.nl/pub/tcm/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org

USE_BISON=	yes
USE_MOTIF=	yes
USE_GMAKE=	yes
MAKE_ARGS+=	X11BASE="${X11BASE}" CFLAGS="${CXXFLAGS}" PREFIX="${PREFIX}"

MANPREFIX=	${PREFIX}/tcm
MAN1=		tucd.1 tatd.1 tcm.1 tcpd.1 tcrd.1 tdfd.1 tdpd.1 tefd.1 terd.1 \
		tesd.1 text2ps.1 tfet.1 tfrt.1 tgd.1 tgt.1 tgtt.1 tpsd.1 \
		trpg.1 tsnd.1 tssd.1 tstd.1 ttdt.1 ttut.1 psf.1

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	(cd ${WRKSRC}/src; ${LN} -sf Config.tmpl_freebsd Config.tmpl)
	@${RM} ${WRKSRC}/man/windex
	@${CHMOD} 0644 ${WRKSRC}/lib/colorrgb.txt

post-install:
	@${ECHO} "================================================================================"
	@${ECHO} "You need to set the environment variable TCM_HOME to ${PREFIX}/tcm"
	@${ECHO} "for tcm to be able to start. You may also want to add ${PREFIX}/tcm/man"
	@${ECHO} "in your manpath.config."
	@${ECHO} "================================================================================"

.include <bsd.port.mk>
