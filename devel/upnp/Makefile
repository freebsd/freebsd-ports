# New ports collection makefile for:	upnp
# Date created:				02 August 2002
# Whom:	      				Yen-Ming Lee <leeym@leeym.com>
#
# $FreeBSD$
#

PORTNAME=	upnp
PORTVERSION=	1.4.0
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pupnp
DISTNAME=	lib${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Universal Plug and Play Software Development Kit

CONFLICTS=	upnp-1.0.*

.include <bsd.port.pre.mk>

.if ${ARCH}==amd64
BROKEN=does not compile on amd64
.endif

GNU_CONFIGURE=	yes
USE_DOS2UNIX=	yes
MAKE_ENV=	PTHREAD_LIBS=${PTHREAD_LIBS}
NOT_FOR_ARCHS=	sparc64
USE_LDCONFIG=	yes

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
