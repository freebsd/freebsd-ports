# $FreeBSD$

PORTNAME=	usogres
PORTVERSION=	0.8.1
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://usogres.good-day.net/download/

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Real-time backup utility for PostgreSQL

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		gmake
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

# To avoid syslogd load, add this parameter.
#MAKE_ARGS=	NDEBUG=yes

post-patch:
	cd ${WRKSRC}; ${CP} usogresrc usogresrc.sample

.include <bsd.port.mk>
