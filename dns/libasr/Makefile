# Created by: Ashish SHUKLA <ashish@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libasr
PORTVERSION=	1.0.4
CATEGORIES=	dns
MASTER_SITES=	http://www.opensmtpd.org/archives/

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Asynchronous DNS resolver library

LICENSE=	ISCL BSD4CLAUSE BSD3CLAUSE BSD2CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		cpe groff libtool

CONFLICTS=	libasr-devel-[0-9]*

CPE_VENDOR=	openbsd

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-mantype="man"

post-patch:
#	Obsoleted on RFC 2553bis-02
	${REINPLACE_CMD} 's|EAI_NODATA|EAI_NONAME|g' \
		 ${WRKSRC}/src/getaddrinfo_async.c

.include <bsd.port.mk>
