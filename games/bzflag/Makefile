# New ports collection makefile for: bzflag
# Date created:		2000/08/12
# Whom:			makeport.pl
#
# $FreeBSD$
#

PORTNAME=	bzflag
PORTVERSION=	2.0.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}.20050318

MAINTAINER=	chuck@pkix.net
COMMENT=	A multiplayer 3D tank battle game

LIB_DEPENDS=	curl.3:${PORTSDIR}/ftp/curl

USE_BZIP2=	yes
USE_SDL=	yes
USE_GL=		yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" LDFLAGS="${PTHREAD_LIBS}"
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

MAN5=	bzw.5
MAN6=	bzadmin.6 bzflag.6 bzfquery.6 bzfs.6

post-patch:
	@${REINPLACE_CMD} -e 's|@LINUX_TRUE@||g ; \
		 s|@LINUX_FALSE@|#|g' ${WRKSRC}/src/platform/Makefile.in

.include <bsd.port.mk>
