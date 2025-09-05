PORTNAME=	ccid
PORTVERSION=	1.6.2
CATEGORIES=	devel
MASTER_SITES=	https://ccid.apdu.fr/files/
PKGNAMEPREFIX=	lib

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generic USB CCID and ICCD driver
WWW=		https://ccid.apdu.fr/ \
		https://github.com/LudovicRousseau/CCID

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpcsclite.so:devel/pcsc-lite

USES=		meson perl5 pkgconfig tar:xz
USE_PERL5=	build

MESON_ARGS=	-Dclass=false \
		-Dcomposite-as-multislot=false \
		-Dembedded=false \
		-Denable-extras=true \
		-Dos_log=false \
		-Dpcsclite=true \
		-Dserial=false \
		-Dzlp=false

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/_build/Kobil_mIDentity_switch ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/_build/RSA_SecurID_getpasswd ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/contrib/RSA_SecurID/RSA_SecurID_getpasswd.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/contrib/Kobil_mIDentity_switch/Kobil_mIDentity_switch.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
