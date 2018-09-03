# $FreeBSD$

PORTNAME=	pmccabe
PORTVERSION=	2.6
CATEGORIES=	devel
MASTER_SITES=	http://ftp.de.debian.org/debian/pool/main/p/pmccabe/ \
		http://dist.codelabs.ru/fbsd/pmccabe/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Code complexity estimator

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}

BINARIES=	decomment pmccabe
SCRIPTS=	codechanges vifn
MANPAGE=	codechanges.1 decomment.1 pmccabe.1 vifn.1

do-install:
.for f in ${BINARIES}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
.for f in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
.for f in ${MANPAGE}
	${INSTALL_MAN} ${WRKSRC}/${f} ${STAGEDIR}${MANPREFIX}/man/man1
.endfor

.include <bsd.port.mk>
