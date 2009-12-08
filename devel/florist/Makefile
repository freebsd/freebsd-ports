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
MASTER_SITES=	http://www.cs.fsu.edu/~baker/ftp/
DISTNAME=	florist-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FSU implementation of POSIX.5, the POSIX Ada binding

BUILD_DEPENDS=	gnatgcc:${PORTSDIR}/lang/gnat

USE_AUTOTOOLS=	autoconf:213
USE_GMAKE=	yes
CONFIGURE_ARGS=	--enable-threads
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} ${PTHREAD_CFLAGS}" \
		LIBS="${LIBS} ${PTHREAD_LIBS}"
MAKEFILE=	"${FILESDIR}/Makefile.bsd"
MAKE_ARGS=	GMAKE=${GMAKE} PORTVERSION=${PORTVERSION} LN=${LN} \
		RM=${RM}
USE_LDCONFIG=	yes

BROKEN= 	Does not build after gpl 2009 update to lang/gnat
DEPRECATED=	has been broken for 3 months
EXPIRATION_DATE=2010-01-08

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
