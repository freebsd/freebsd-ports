# New ports collection makefile for:	upnp
# Date created:				02 August 2002
# Whom:	      				Yen-Ming Lee <leeym@leeym.com>
#
# $FreeBSD$
#

PORTNAME=	upnp
PORTVERSION=	1.4.3
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pupnp
DISTNAME=	lib${PORTNAME}-${PORTVERSION}

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	Universal Plug and Play Software Development Kit

CONFLICTS=	upnp-1.0.*
USE_BZIP2=	yes

.include <bsd.port.pre.mk>

NOT_FOR_ARCH=	amd64 sparc64
GNU_CONFIGURE=	yes
USE_DOS2UNIX=	yes
MAKE_ENV=	PTHREAD_LIBS=${PTHREAD_LIBS}
USE_LDCONFIG=	yes
CONFIGURE_ENV+=	LIBS="-llwres -lcompat"

.if defined(NOPORTDOCS)
CONFIGURE_ARGS=	--without-docdir
.else
CONFIGURE_ARGS=	--with-docdir=${DOCSDIR}
.endif

post-patch:
	${FIND} ${WRKSRC} -type f | \
		${XARGS} ${REINPLACE_CMD} -e 's,malloc.h,stdlib.h,'
	${REINPLACE_CMD} -Ee 's,^(pkgconfigexecdir = ).*,\1${PREFIX}/libdata/pkgconfig,' \
		${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
