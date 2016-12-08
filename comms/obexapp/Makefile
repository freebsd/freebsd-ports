# $FreeBSD$

PORTNAME=	obexapp
PORTVERSION=	1.4.15
PORTREVISION=	2
CATEGORIES=	comms net
MASTER_SITES=	http://people.freebsd.org/~emax/obexapp/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Obex application to transfer objects to mobile equipment

LIB_DEPENDS=	libopenobex.so:comms/openobex \
		libexpat.so:textproc/expat2

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		iconv readline uidfix
PLIST_FILES=	bin/obexapp man/man1/obexapp.1.gz

MAKE_ENV+=	NO_WERROR=yes

post-patch:
	@${REINPLACE_CMD} -e 's/-liconv/${ICONV_LIB}/' ${WRKSRC}/Makefile

.include <bsd.port.mk>
