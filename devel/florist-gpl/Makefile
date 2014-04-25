# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	florist-gpl
PORTVERSION=	2012
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://downloads.dragonlace.net/src/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	marino@FreeBSD.org
COMMENT=	POSIX Ada binding, IEEE Standards 1003.5(b,c)

LICENSE=	GPLv3

USES=		ada tar:tgz
GNU_CONFIGURE=	yes

post-extract:
	${CP} ${FILESDIR}/pconfig.* ${WRKSRC}/configs

.include <bsd.port.mk>
