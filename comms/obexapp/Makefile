# $FreeBSD$

PORTNAME=	obexapp
PORTVERSION=	1.4.15
PORTREVISION=	4
CATEGORIES=	comms net
MASTER_SITES=	http://people.freebsd.org/~emax/obexapp/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Obex application to transfer objects to mobile equipment

LIB_DEPENDS=	libopenobex.so:comms/openobex \
		libexpat.so:textproc/expat2

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		iconv readline uidfix
PLIST_FILES=	bin/obexapp man/man1/obexapp.1.gz

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1300134
MAKE_ENV+=	NO_WERROR=yes
.else
MAKE_ENV+=	MK_WERROR=no
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/-liconv/${ICONV_LIB}/' ${WRKSRC}/Makefile

.include <bsd.port.post.mk>
