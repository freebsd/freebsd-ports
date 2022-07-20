PORTNAME=	parchive
PORTVERSION=	1.1
CATEGORIES=	archivers
MASTER_SITES=	SF/${PORTNAME}/par/${PORTVERSION}
DISTNAME=	par-v${PORTVERSION}

MAINTAINER=	ak@FreeBSD.org
COMMENT=	Parity Archiver - makes multiple parity volumes from a set of files

LICENSE=	GPLv2

USES=		uidfix
MAKEFILE=	${FILESDIR}/Makefile
PLIST_FILES=	bin/parchive
WRKSRC=		${WRKDIR}/par-cmdline

.include <bsd.port.mk>
