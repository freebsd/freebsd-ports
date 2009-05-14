# New ports collection makefile for:	aqbanking
# Date created:		June 2005
# Whom:                 Sam Lawrance <lawrance@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aqbanking
PORTVERSION=	3.8.1
PORTREVISION=	1
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Online banking interface and financial data framework

LIB_DEPENDS=	gwenhywfar.53:${PORTSDIR}/devel/gwenhywfar \
		gmp.8:${PORTSDIR}/math/libgmp4

OPTIONS=	KTOBLZCHECK	"KtoBlzCheck support"	off

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_QT_VER=	3
QT_NONSTANDARD=	special flags for threading

CFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
CONFIGURE_ENV+=	LIBS="${QTCFGLIBS} ${PTHREAD_LIBS}"
CONFIGURE_ENV+=	QTDIR="${QT_PREFIX}"
CONFIGURE_ARGS+=	--with-frontends="cbanking qbanking"

USE_LDCONFIG=	${PREFIX}/lib/aqbanking/plugins/20/bankinfo \
		${PREFIX}/lib/aqbanking/plugins/20/frontends/qbanking/cfgmodules\
		${PREFIX}/lib/aqbanking/plugins/20/imexporters \
		${PREFIX}/lib/aqbanking/plugins/20/providers \
		${PREFIX}/lib

.include <bsd.port.pre.mk>

# no configure option to disable ktoblzcheck support (yet)
.if defined(WITH_KTOBLZCHECK) || exists(${LOCALBASE}/lib/libktoblzcheck.so.4)
LIB_DEPENDS+=	ktoblzcheck.6:${PORTSDIR}/finance/ktoblzcheck
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|echo aout|echo elf|g" ${WRKSRC}/configure

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
