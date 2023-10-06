PORTNAME=	libasr
PORTVERSION=	201602131606
PORTREVISION=	4
CATEGORIES=	dns
MASTER_SITES=	http://www.opensmtpd.org/archives/
PKGNAMESUFFIX=	-devel

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Asynchronous DNS resolver library (development snapshot)
WWW=		https://github.com/OpenSMTPD/libasr

LICENSE=	ISCL BSD4CLAUSE BSD3CLAUSE BSD2CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		cpe groff libtool

CONFLICTS=	libasr

CPE_VENDOR=	openbsd

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-mantype="man"
INSTALL_TARGET=	install-strip

post-patch:
	${REINPLACE_CMD} -e '/opensslv.h/d' ${WRKSRC}/openbsd-compat/includes.h

.include <bsd.port.mk>
