# $FreeBSD$

PORTNAME=	pmccabe
PORTVERSION=	2.6
CATEGORIES=	devel
MASTER_SITES=	http://ftp.de.debian.org/debian/pool/main/p/pmccabe/ \
		http://dist.codelabs.ru/fbsd/pmccabe/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	rea@FreeBSD.org
COMMENT=	Code complexity estimator

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}

BINARIES=	decomment pmccabe
SCRIPTS=	codechanges vifn
MAN1=		codechanges.1 decomment.1 pmccabe.1 vifn.1
PLIST_FILES=	${BINARIES:S,^,bin/,} \
		${SCRIPTS:S,^,bin/,}

NO_STAGE=	yes
do-install:
.for f in ${BINARIES}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
.for f in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
.if !defined(NO_INSTALL_MANPAGES)
. for f in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/${f} ${MANPREFIX}/man/man1
. endfor
.endif

.include <bsd.port.mk>
