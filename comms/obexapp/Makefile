PORTNAME=	obexapp
PORTVERSION=	1.4.15
PORTREVISION=	5
CATEGORIES=	comms net
MASTER_SITES=	https://people.freebsd.org/~emax/obexapp/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Obex application to transfer objects to mobile equipment
WWW=		https://people.freebsd.org/~emax/

LICENSE=	BSD-2-Clause

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libopenobex.so:comms/openobex

USES=		iconv readline uidfix

MAKE_ENV+=	MK_WERROR=no

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/obexapp \
		share/man/man1/obexapp.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's/-liconv/${ICONV_LIB}/' ${WRKSRC}/Makefile

.include <bsd.port.mk>
