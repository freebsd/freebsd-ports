# Created by: Muhammad Moinur Rahman <bofh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vpcs
PORTVERSION=	0.8
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Virtual PC Simulator

LICENSE=	BSD2CLAUSE

BROKEN_FreeBSD_13=	ld: error: duplicate symbol: vpc
BROKEN_FreeBSD_14=	ld: error: duplicate symbol: vpc
ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	non-portable

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		tar:tbz
PLIST_FILES=	bin/vpcs man/man1/vpcs.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|i386|${ARCH}|g' ${WRKSRC}/src/Makefile.fbsd

do-build:
	cd ${WRKSRC}/src && ${BSDMAKE} -f Makefile.fbsd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/vpcs ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/vpcs.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
