# New ports collection makefile for:	CommonC++
# Date created:				25 July 2000
# Whom:					David Sugar <dyfet@gnu.org>
#
# $FreeBSD$
#

PORTNAME=	commoncpp2
PORTVERSION=	1.0.13
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU} \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	commonc++ cplusplus

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU project portable class framework for C++

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2

USE_GETOPT_LONG=yes
USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib" \
		MAKEINFO="makeinfo --no-split"
CONFIGURE_ARGS=	--with-ftp
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

INFO=		commoncpp2

post-extract:
	@${RM} -f ${WRKSRC}/doc/${PORTNAME}.info*

post-install:
	@(cd ${WRKSRC} && ${GMAKE} man)
	@(cd ${WRKSRC}/doc/man3 && ${LS} *.3cc | \
		${SED} 's@^@man/man3/@'>> ${TMPPLIST})

.include <bsd.port.mk>
