# New ports collection makefile for:	TenDRA
# Version required:	4.1.2
# Date created:		7 Apr 1998
# Whom:			Robert Nordier <rnordier@iafrica.com>
#
# $Id: Makefile,v 1.2 1998/04/14 11:49:14 rnordier Exp $
#

DISTNAME=	TenDRA-4.1.2
CATEGORIES=	lang
MASTER_SITES=	ftp://alph.dera.gov.uk/pub/TenDRA/

MAINTAINER=	rnordier@FreeBSD.ORG

OSREL!=		uname -r
PLIST=		${WRKDIR}/PLIST
MAN1=		calculus.1 disp.1 lexi.1 pl.1 sid.1 tcc.1 tchk.1 \
		tcpplus.1 tdfc2.1 tld.1 tnc.1 trans.1 tspec.1
MAN5=		tccenv.5

pre-configure:
	@(cd ${WRKSRC} && \
	${MKDIR} bin lib man && \
	${SED}	-e 's:^\(BASE_DIR=\).*:\1${WRKSRC}:' \
		-e 's:^\(PUBLIC_BIN=\).*:\1$${BASE_DIR}/bin:' \
		-e 's:^\(INSTALL_DIR=\).*:\1$${BASE_DIR}/lib/TenDRA:' \
		-e 's:^\(MAN_DIR=\).*:\1$${BASE_DIR}/man:' \
		-e 's:completed:to build directory completed:' \
		INSTALL >INSTALL.build && \
	chmod a+x INSTALL.build && \
	chmod a-x INSTALL)
	@${SED} 's:%OSREL%:${OSREL}:' ${PKGDIR}/PLIST >${PLIST}

do-build:
	@(PATH=${WRKSRC}/bin:$$PATH && \
	cd ${WRKSRC} && \
	./INSTALL.build 2>&1 | tee ${.CURDIR}/mklog && \
	${RM} -f ${.CURDIR}/mklog)
	@${ECHO} "Bootstrapping the compiler ..."
	@${RM} -fr ${WRKSRC}/work
	@(PATH=${WRKSRC}/bin:$$PATH && \
	cd ${WRKSRC} && \
	./INSTALL.build -tcc 2>&1 | tee ${.CURDIR}/mklog && \
	${RM} -f ${.CURDIR}/mklog)

pre-install:
	@(cd ${WRKSRC} && \
	${SED}	-e 's:^\(BASE_DIR=\).*:\1${WRKSRC}:' \
		-e 's:^\(PUBLIC_BIN=\).*:\1${PREFIX}/bin:' \
		-e 's:^\(INSTALL_DIR=\).*:\1${PREFIX}/lib/TenDRA:' \
		-e 's:^\(MAN_DIR=\).*:\1${PREFIX}/man:' \
		INSTALL >INSTALL.install && \
	chmod a+x INSTALL.install)

do-install:
	@${MKDIR} ${PREFIX}/lib/TenDRA
	@(PATH=${WRKSRC}/bin:$$PATH && \
	cd ${WRKSRC} && \
	./INSTALL.install -tcc -strip 2>&1 | tee ${.CURDIR}/mklog && \
	${RM} -f ${.CURDIR}/mklog)
	@(cd ${PREFIX}/bin && \
	chown ${BINOWN}:${BINGRP} tcc tchk tspec && \
	chmod ${BINMODE} tcc tchk tspec)
	@(cd ${PREFIX} && \
	chown -R ${BINOWN}:${BINGRP} lib/TenDRA && \
	find -X lib/TenDRA -type d | xargs chmod 755 && \
	${GREP} '^lib/' ${PLIST} | xargs chmod ${SHAREMODE} && \
	${GREP} '/bin/' ${PLIST} | xargs chmod ${BINMODE})
	@(cd ${PREFIX}/man/man1 && \
	chown ${MANOWN}:${MANGRP} ${MAN1} && \
	chmod ${MANMODE} ${MAN1})
	@(cd ${PREFIX}/man/man5 && \
	chown ${MANOWN}:${MANGRP} ${MAN5} && \
	chmod ${MANMODE} ${MAN5})

.include <bsd.port.mk>
