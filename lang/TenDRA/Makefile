# ex:ts=8
# New ports collection makefile for:	TenDRA
# Date created:		7 Apr 1998
# Whom:			Robert Nordier <rnordier@iafrica.com>
#
# $FreeBSD$
#

PORTNAME=	TenDRA
PORTVERSION=	4.1.2
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.uni-trier.de/pub/languages/c/implementation/TenDRA/ \
		ftp://ftp.fh-wiesbaden.de/pub/Languages/C/TenDRA/ \
		ftp://ftp.mayn.de/pub/unix/devel/compiler/tendra/

MAINTAINER=	obrien@FreeBSD.org

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400000
BROKEN=		"Does not compile."
.endif

ONLY_FOR_ARCHS=	i386
OSRELEASE!=	uname -r
PLIST_SUB=	OSRELEASE=${OSRELEASE}

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
	${CHMOD} a+x INSTALL.build && \
	${CHMOD} a-x INSTALL)

do-build:
	@(PATH=${WRKSRC}/bin:$$PATH && \
	cd ${WRKSRC} && \
	./INSTALL.build)
	@${ECHO} "Bootstrapping the compiler ..."
	@${RM} -fr ${WRKSRC}/work
	@(PATH=${WRKSRC}/bin:$$PATH && \
	cd ${WRKSRC} && \
	./INSTALL.build -tcc)

pre-install:
	@(cd ${WRKSRC} && \
	${SED}	-e 's:^\(BASE_DIR=\).*:\1${WRKSRC}:' \
		-e 's:^\(PUBLIC_BIN=\).*:\1${PREFIX}/bin:' \
		-e 's:^\(INSTALL_DIR=\).*:\1${PREFIX}/lib/TenDRA:' \
		-e 's:^\(MAN_DIR=\).*:\1${PREFIX}/man:' \
		INSTALL >INSTALL.install && \
	${CHMOD} a+x INSTALL.install)

do-install:

post-install:
	@${MKDIR} ${PREFIX}/lib/TenDRA
	@(PATH=${WRKSRC}/bin:$$PATH && \
	cd ${WRKSRC} && \
	./INSTALL.install -tcc -strip)
	@(cd ${PREFIX}/bin && \
	${CHOWN} ${BINOWN}:${BINGRP} tcc tchk tspec && \
	${CHMOD} ${BINMODE} tcc tchk tspec)
	@(cd ${PREFIX} && \
	${CHOWN} -R ${BINOWN}:${BINGRP} lib/TenDRA && \
	find -X lib/TenDRA -type d | xargs ${CHMOD} 755 && \
	${GREP} '^lib/' ${TMPPLIST} | xargs ${CHMOD} ${SHAREMODE} && \
	${GREP} '/bin/' ${TMPPLIST} | xargs ${CHMOD} ${BINMODE})
	@(cd ${PREFIX}/man/man1 && \
	${CHOWN} ${MANOWN}:${MANGRP} ${MAN1} && \
	${CHMOD} ${MANMODE} ${MAN1})
	@(cd ${PREFIX}/man/man5 && \
	${CHOWN} ${MANOWN}:${MANGRP} ${MAN5} && \
	${CHMOD} ${MANMODE} ${MAN5})

.include <bsd.port.post.mk>
