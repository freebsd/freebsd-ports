# New ports collection makefile for: bzflag
# Date created:		2000/08/12
# Whom:			makeport.pl
#
# $FreeBSD$
#

PORTNAME=	bzflag
PORTVERSION=	2.0.0
CATEGORIES=	games
# SourceForge mirroring for BZFlag-2 is broken at the moment
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
#MASTER_SITE_SUBDIR=	${PORTNAME}
MASTER_SITES=	http://www.pkix.net/mirror/sf.net/ \
		ftp://ftp.sucs.org/pub/linux/
DISTNAME=	${PORTNAME}-${PORTVERSION}.20050117

MAINTAINER=	chuck@pkix.net
COMMENT=	A multiplayer 3D tank battle game

BUILD_DEPENDS=	${LOCALBASE}/bin/curl-config:${PORTSDIR}/ftp/curl

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
