# New ports collection makefile for: GP-jp
# Version required:	2.01jp
# Date created:		15 April 1997
# Whom:			Kiriyama Kazuhiko<kiri@kiri.toba-cmt.ac.jp>
#
# $Id: Makefile,v 1.1.1.1 1997/06/04 02:13:17 asami Exp $
#

DISTNAME=	GP-2.01jp
PKGNAME=	jp-gp-2.01
CATEGORIES=	japanese print
MASTER_SITES=	http://www.kamome.or.jp/hueda/GP/ \
		ftp://green.arailab.dnj.ynu.ac.jp/pub/AraiLab/GP/

MAINTAINER=	kiri@kiri.toba-cmt.ac.jp

RUN_DEPENDS=	wish4.2jp:${PORTSDIR}/japanese/tk42 \
		nup:${PORTSDIR}/japanese/dvi2ps \
		a2ps-j:${PORTSDIR}/japanese/a2ps \
		ghostview:${PORTSDIR}/print/ghostview

NO_BUILD=	yes

DOCDIR=		${PREFIX}/share/doc/GP-jp

pre-patch:
	@${MKDIR} ${PATCHDIR}
	@${SETENV} FILESDIR=${FILESDIR} PATCHDIR=${PATCHDIR} \
		PREFIX=${PREFIX} SED=${SED} X11BASE=${X11BASE} \
		/bin/sh ${FILESDIR}/pr-setup.sh

do-install:
	@${MKDIR} ${PREFIX}/etc/GP-jp
	@${INSTALL_SCRIPT} ${WRKSRC}/GP ${PREFIX}/bin/GP-j
	@${INSTALL_DATA} ${FILESDIR}/printer ${FILESDIR}/filetype  \
		${PREFIX}/etc/GP-jp

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	@${INSTALL_DATA} ${WRKSRC}/Doc/README ${WRKSRC}/Doc/Variables \
		 ${DOCDIR}
.endif

pre-clean:
	@${RM} -f ${FILESDIR}/filetype ${FILESDIR}/printer ${PATCHDIR}/patch-aa

.include <bsd.port.mk>
