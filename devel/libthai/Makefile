# New ports collection makefile for:    libthai
# Date created:        28 March 2006
# Whom:                Thawatchai Piyawat <piyawat@usablelabs.com>
#
# $FreeBSD$
#

PORTNAME=	libthai
PORTVERSION=	0.1.5
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://www.usablelabs.com/download/

MAINTAINER=	piyawat@usablelabs.com
COMMENT=	Thai language support library

INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	automake:15 autoconf:261 libtool:15

ALL_TARGET=	all check

MAN3=	libthai.3 thctype.3 wtt.3

post-patch:
	@${REINPLACE_CMD} -E 's,^(pkgconfigdir = ).*$$,\1$$(prefix)/libdata/pkgconfig,' \
		${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e 's,15,-1.5,' -e 's,259,-2.61,' \
		${WRKSRC}/autogen.sh

pre-configure:
	@${SH} ${WRKSRC}/autogen.sh

.include <bsd.port.mk>
