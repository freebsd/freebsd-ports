# New ports collection makefile for:	RealTimeBattle
# Date created:				30 June 2000
# Whom:				Dishanker Rajakulendren <draj@oceanfree.net>
#
# $FreeBSD$
#

PORTNAME=	RealTimeBattle
PORTVERSION=	1.0.6
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.lysator.liu.se/realtimebattle/Download/
MASTER_SITE_SUBDIR=	${PORTNAME:L}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Robot programming game for UNIX

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnometarget gtk20 lthack
USE_GETOPT_LONG=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=13
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

CPPFLAGS=	-I${LOCALBASE}/include -DHAVE_DECL_GETOPT
LDFLAGS=	-L${LOCALBASE}/lib

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/RealTimeBattle.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
