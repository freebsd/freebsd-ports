# New ports collection makefile for:	florist
# Date created:		1 Sep 2002
# Whom:			Vadim Godunko <vgodunko@vipmail.ru>
#
# $FreeBSD$
#

PORTNAME=	florist
PORTVERSION=	3.15p
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://cs.nyu.edu/pub/gnat/${PORTVERSION}/
DISTNAME=	florist-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	vgodunko@vipmail.ru
COMMENT=	FSU implementation of POSIX.5

BUILD_DEPENDS=	adagcc:${PORTSDIR}/lang/gnat

USE_AUTOCONF_VER=	213
USE_GMAKE=	yes
CONFIGURE_ARGS=	--enable-threads
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} ${PTHREAD_CFLAGS}" \
		LIBS="${LIBS} ${PTHREAD_LIBS}"
MAKEFILE=	"${FILESDIR}/Makefile.bsd"
MAKE_ARGS=	GMAKE=${GMAKE} PORTVERSION=${PORTVERSION} LN=${LN} \
		RM=${RM}
INSTALLS_SHLIB=	yes

post-extract:
# add FreeBSD configuration
	@${CP} ${FILESDIR}/pconfig.FreeBSD \
		${WRKSRC}/configs

do-install:
	@${MKDIR} ${PREFIX}/lib/florist
	@${INSTALL_DATA} ${WRKSRC}/floristlib/*.ad[sb] \
		${WRKSRC}/floristlib/*.ali \
		${PREFIX}/lib/florist
	@${INSTALL_DATA} ${WRKSRC}/floristlib/libflorist.a ${PREFIX}/lib
	@${INSTALL_DATA} ${WRKSRC}/libflorist-${PORTVERSION}.so.1 ${PREFIX}/lib
	@${LN} -sf ${PREFIX}/lib/libflorist-${PORTVERSION}.so.1 \
		${PREFIX}/lib/libflorist-${PORTVERSION}.so

.include <bsd.port.mk>
