# New ports collection Makefile for: nab
# Date created:         Sept. 10, 2000
# Whom:                 M. L. Dodson <bdodson@scms.utmb.edu>
# $FreeBSD$

PORTNAME=	nab
PORTVERSION=	4.2
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.scripps.edu/pub/case/

MAINTAINER=	bdodson@scms.utmb.edu

NO_WRKSUBDIR=	yes
MAKE_ENV+=	WRKSRC=${WRKSRC} PREFIX=${PREFIX} \
		NABHOME=${PREFIX}/share/nab ARCH= \
		INSTALL_MAN="${INSTALL_MAN}"
MAN1=		nab.1
MANCOMPRESSED=	yes

post-extract:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}
	@${CP} ${FILESDIR}/Makefile.doc ${WRKSRC}/doc/Makefile
	@${CP} ${FILESDIR}/config.h ${WRKSRC}

pre-install:
	@-mkdir -p ${PREFIX}/share/nab
.if !defined(${NOPORTDOCS})
	@cd ${WRKSRC} && (tar cf - examples test | \
		(cd ${PREFIX}/share/nab; tar xf -))
	@-mkdir -p ${PREFIX}/share/doc/nab
	${INSTALL_MAN} ${WRKSRC}/doc/NAB.pdf ${PREFIX}/share/doc/nab
.endif
	@cd ${WRKSRC} && (tar cf - dgdb reslib | \
		(cd ${PREFIX}/share/nab; tar xf -))
	@(cd ${PREFIX}/share; ${CHOWN} -R ${SHAREOWN}.${SHAREGRP} nab; \
		${CHMOD} -R ugo+rX-w nab)
	@-(cd ${PREFIX}/share/nab; ${RM} -f coords && ${LN} -s ../NDB coords)

post-install:
	@(cd ${PREFIX}/bin; \
	${RM} -f nab && ${MV} ${PREFIX}/share/nab/bin/nab . ; \
	${RM} -f nab2c && ${MV} ${PREFIX}/share/nab/bin/nab2c . ; \
	${CHOWN} ${BINOWN}:${BINGRP} nab nab2c teLeap ; \
	strip nab nab2c teLeap ; \
	${RMDIR} ${PREFIX}/share/nab/bin)
	@${CAT} ${PKGMESSAGE}

test:	all
	@cd ${WRKSRC}/src && make test

.include <bsd.port.mk>
