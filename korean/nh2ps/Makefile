# New ports collection makefile for:    nh2ps-2.3
# Version required:     2.3
# Date created:         2 Apr 1997
# Whom:                 Choi Jun Ho <junker@jazz.snu.ac.kr>
#
# $Id: Makefile,v 1.4 1997/11/10 11:28:34 asami Exp $
#

DISTNAME=	nh2ps-2.3
PKGNAME=	ko-nh2ps-2.3
CATEGORIES=	korean print
MASTER_SITES=	ftp://jazz.snu.ac.kr/pub/unix/util/nh2ps/

MAINTAINER=	junker@jazz.snu.ac.kr

RUN_DEPENDS=    ${PREFIX}/share/ghostscript/5.10ft/hangul:${PORTSDIR}/korean/ftghostscript5

MAN1=		nh2ps.1

pre-install:
	@(cd ${WRKSRC}; make install.man)

post-install:
	strip ${PREFIX}/bin/nh2ps
	@${MKDIR} ${PREFIX}/share/doc/nh2ps
	${INSTALL_DATA} ${WRKSRC}/README.nh2ps ${PREFIX}/share/doc/nh2ps/
	${INSTALL_DATA} ${WRKSRC}/README.font ${PREFIX}/share/doc/nh2ps/
	${INSTALL_DATA} ${WRKSRC}/README.filtering_with_gs \
		${PREFIX}/share/doc/nh2ps/

.include <bsd.port.mk>
