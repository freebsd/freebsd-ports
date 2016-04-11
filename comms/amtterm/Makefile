# $FreeBSD$

PORTNAME=	amtterm
PORTVERSION=	1.4
CATEGORIES=	comms
MASTER_SITES=	https://www.kraxel.org/releases/${PORTNAME}/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Serial-over-lan client for Intel AMT

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	p5-SOAP-Lite>=0.5:net/p5-SOAP-Lite

USES=		gmake dos2unix shebangfix
DOS2UNIX_FILES=	RedirectionConstants.h
SHEBANG_FILES=	amttool

MAKEFILE=	GNUmakefile
MAKE_ARGS+=	HAVE_GTK=no mandir=${STAGEDIR}${MANPREFIX}/man

PLIST_FILES=	bin/${PORTNAME} \
		bin/amttool \
		share/applications/gamt.desktop \
		man/man1/gamt.1.gz man/man1/${PORTNAME}.1.gz \
		man/man1/amttool.1.gz man/man7/amt-howto.7.gz

post-patch:
	@${REINPLACE_CMD} -e 's,/sbin/ldconfig -p,${LDCONFIG} -r,' \
		${WRKSRC}/mk/Autoconf.mk

.include <bsd.port.mk>
