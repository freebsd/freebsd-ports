# Created by: max
# $FreeBSD$

PORTNAME=	nkf
PORTVERSION=	2.1.4
PORTEPOCH=	1
CATEGORIES=	japanese perl5
MASTER_SITES=	OSDN/${PORTNAME}
PKGNAMEPREFIX=	ja-p5-

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Perl extension module to use NKF

LICENSE=	ZLIB NKF
LICENSE_COMB=	multi
LICENSE_NAME_NKF=	NKF License
LICENSE_FILE_ZLIB=	${WRKSRC}/NKF.pm
LICENSE_FILE_NKF=	${WRKSRC}/NKF.xs
LICENSE_PERMS_NKF=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		perl5
USE_PERL5=	configure
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/NKF.mod

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/NKF/NKF.so

.include <bsd.port.mk>
