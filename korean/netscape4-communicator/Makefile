# New ports collection makefile for:	netscape3-intl-ko
# Version required:     3.04/ko
# Date created:		6 Apr 1995
# Whom:			CHOI Junho <junker@jazz.snu.ac.kr>
#
# $Id: Makefile,v 1.7 1998/11/23 07:49:49 asami Exp $
#

DISTNAME=	netscape-3.04
PKGNAME=	ko-netscape-3.04
CATEGORIES=	korean www
MASTER_SITES=	ftp://archive:oldies@archive.netscape.com/archive/navigator/intl/3.01/unix/ko/ \
		http://www.bpel.tutics.tut.ac.jp/~take/Netscape/etc/
DISTFILES=	netscape-ko-v301.alpha-dec-osf2.0.tar.gz NLS.tar.gz

MAINTAINER=	junker@jazz.snu.ac.kr

RUN_DEPENDS=	${PREFIX}/bin/netscape:${PORTSDIR}/www/netscape3 \
		${X11BASE}/lib/X11/fonts/local/hgm12.pcf.gz:${PORTSDIR}/korean/hanyangfonts

BROKEN=		upgrade

DIST_SUBDIR=	netscape3
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

# This directory is hard-coded into the netscape binary
LIBDIR=         /usr/local/lib/netscape
BINDIR=         ${PREFIX}/bin
NLSDIR=         ${LIBDIR}/nls
RESSUB=         ko_KR.EUC
RESDIR=         ${LIBDIR}/${RESSUB}

NLSSRC=		${WRKDIR}/netscape-ko
MISCFILES=	README about splash license mail.msg

STARTFILE=      netscape.sh
STARTFILE_SRC=  ${FILESDIR}/netscape.sh

do-configure:
	@${SED} -e "s;@X11BASE@;${X11BASE};g" -e "s;@PREFIX@;${PREFIX};g" \
		${STARTFILE_SRC} >${WRKDIR}/${STARTFILE}

do-install:
	-@${MV} ${BINDIR}/netscape ${BINDIR}/netscape.orig
	@${INSTALL_SCRIPT} ${WRKDIR}/${STARTFILE} ${BINDIR}/netscape
	@${MKDIR} ${NLSDIR}/local_im_tbl
	@${INSTALL_DATA} ${WRKDIR}/nls/*.*  ${LIBDIR}/nls
	@${INSTALL_DATA} ${WRKDIR}/nls/C  ${LIBDIR}/nls
	@${RM} -f ${LIBDIR}/nls/*.orig
	@${INSTALL_DATA} ${WRKDIR}/nls/local_im_tbl/* ${LIBDIR}/nls/local_im_tbl
	@${MKDIR} ${RESDIR}
	@${INSTALL_DATA} ${NLSSRC}/Netscape.ad-ko ${RESDIR}/Netscape
	@for i in ${MISCFILES}; do \
		${INSTALL_DATA} ${NLSSRC}/$$i ${RESDIR}; \
	done
	${INSTALL_DATA} ${NLSSRC}/icons/*.xpm ${RESDIR}

# This port is based on 'japanese/netscape3.language(ja-netscape-3.04)'
# by sada@e-mail.ne.jp

post-install:
	@${CAT} ${PKGDIR}/DESCR

.include <bsd.port.mk>
