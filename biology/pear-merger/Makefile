# Newer versions require registration to download and the site is unreliable.

PORTNAME=	pear
DISTVERSION=	0.9.6
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	https://depot.galaxyproject.org/software/pear/
PKGNAMESUFFIX=	-merger
DISTNAME=	${PORTNAME}_${PORTVERSION}_src_all

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Memory-efficient and highly accurate paired-end read merger
WWW=		https://sco.h-its.org/exelixis/web/software/pear/

LICENSE=	CC-BY-NC-SA-3.0

GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-src

PLIST_FILES=	bin/pearRM share/man/man1/pearRM.1.gz

.include <bsd.port.options.mk>

.if ${ARCH} != amd64 && ${ARCH} != i386
USE_GCC=	yes
.endif

do-install:
	@${CP} ${WRKSRC}/man/pear.1 ${WRKSRC}/man/pearRM.1
	${INSTALL_PROGRAM} ${WRKSRC}/src/pear ${STAGEDIR}${PREFIX}/bin/pearRM
	${INSTALL_MAN} ${WRKSRC}/man/pearRM.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
