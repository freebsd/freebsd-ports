# ex:ts=8
# Ports collection makefile for:  wgetpro
# Date created:			May 18, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	wgetpro
PORTVERSION=	0.1.2
CATEGORIES=	ftp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Wget with "PRO" features

USE_GETOPT_LONG=	yes
USE_OPENSSL=	yes
USE_GETTEXT=	yes
USE_PERL5_BUILD=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lintl"
USE_GMAKE=	yes

PLIST_FILES=	bin/wpro

post-patch:
	@${TOUCH} ${WRKSRC}/configure

post-install:
	@${FIND} ${PREFIX}/share/locale -name "wpro.mo" | \
		${SED} -e "s,^${PREFIX}/,," >> ${TMPPLIST}

.include <bsd.port.mk>
