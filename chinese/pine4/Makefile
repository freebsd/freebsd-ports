# New ports collection makefile for:	pine
# Version required:     4.00
# Date created:		19 Nov1997
# Whom:			Wu Ching-hong <woju@FreeBSD.ee.Ntu.edu.TW>
#
# $Id: Makefile,v 1.4 1998/07/21 15:27:41 asami Exp $
#

DISTNAME=       pine4.02
PKGNAME=        zh-pine-4.02
CATEGORIES=     chinese mail news
MASTER_SITES=	ftp://ftp.cac.washington.edu/pine/

MAINTAINER=	avatar@www.mmlab.cse.yzu.edu.tw

NO_LATEST_LINK=	yes

MAN1= 		pine.1 pico.1 pilot.1

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ./build bsf)

do-install:
	${INSTALL} ${COPY} -o ${LIBOWN} -g ${LIBGRP} -m ${LIBMODE} \
		 ${WRKSRC}/bin/libpico.so.1.3 ${PREFIX}/lib/libpico.so.1.3
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pico ${PREFIX}/bin/pico
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pilot ${PREFIX}/bin/pilot
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pine ${PREFIX}/bin/pine
	${INSTALL_SCRIPT} ${FILESDIR}/pgpencrypt ${PREFIX}/bin/pgpencrypt
	${INSTALL_SCRIPT} ${FILESDIR}/pgpdecode ${PREFIX}/bin/pgpdecode
	${INSTALL_SCRIPT} ${FILESDIR}/pgpsign ${PREFIX}/bin/pgpsign
	${INSTALL_DATA} ${FILESDIR}/dot.pinerc.sample \
			${PREFIX}/etc/dot.pinerc.sample
	${INSTALL_DATA} ${FILESDIR}/dot.pinerc.pgp.sample \
			${PREFIX}/etc/dot.pinerc.pgp.sample
	${INSTALL_DATA} ${FILESDIR}/pine.conf ${PREFIX}/etc/pine.conf
	${INSTALL_MAN} ${WRKSRC}/doc/pico.1 ${PREFIX}/man/man1/pico.1
	${INSTALL_MAN} ${WRKSRC}/doc/pilot.1 ${PREFIX}/man/man1/pilot.1
	${INSTALL_MAN} ${WRKSRC}/doc/pine.1 ${PREFIX}/man/man1/pine.1
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} \
			${PREFIX}/share/doc/pine/tech-notes
	${INSTALL_DATA} ${WRKSRC}/doc/brochure.txt ${PREFIX}/share/doc/pine
	${INSTALL_DATA} ${WRKSRC}/doc/tech-notes.txt ${PREFIX}/share/doc/pine
	${INSTALL_DATA} ${WRKSRC}/doc/tech-notes/*.html \
			${PREFIX}/share/doc/pine/tech-notes/
.endif

post-install:
	${LDCONFIG} -m ${PREFIX}/lib/

.include <bsd.port.mk>
