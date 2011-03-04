# New ports collection makefile for:	upnp
# Date created:				02 August 2002
# Whom:	      				Yen-Ming Lee <leeym@leeym.com>
#
# $FreeBSD$
#

PORTNAME=	upnp
PORTVERSION=	1.6.12
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	SF/p${PORTNAME}/p${PORTNAME}/libUPnP%20${PORTVERSION}
DISTNAME=	lib${PORTNAME}-${PORTVERSION}

MAINTAINER=	c0rn@o2.pl
COMMENT=	Universal Plug and Play Software Development Kit

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CONFIGURE_ENV+=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

.if defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--without-documentation
.else
CONFIGURE_ARGS+=	--with-documentation=${DOCSDIR}
PORTDOCS=	*
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

post-patch:	.SILENT
	${REINPLACE_CMD} '/^pkgconfigexecdir/s|$$(libdir)|$$(prefix)/libdata|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
