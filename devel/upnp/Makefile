# New ports collection makefile for:	upnp
# Date created:				02 August 2002
# Whom:	      				Yen-Ming Lee <leeym@leeym.com>
#
# $FreeBSD$
#

PORTNAME=	upnp
PORTVERSION=	1.6.8
PORTREVISION=	1
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
CONFIGURE_ARGS=	--without-documentation
.else
CONFIGURE_ARGS=	--with-documentation=${DOCSDIR}

PORTDOCS=	*
.endif

post-patch:	.SILENT
	${REINPLACE_CMD} '/^pkgconfigexecdir/s|$$(libdir)|$$(prefix)/libdata|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.pre.mk>

# strndup(3) was added in 7.2-RELEASE
.if ${OSVERSION} < 702000
EXTRA_PATCHES+=	${FILESDIR}/extra-upnp-src-api-UpnpString.c
.endif

.include <bsd.port.post.mk>
