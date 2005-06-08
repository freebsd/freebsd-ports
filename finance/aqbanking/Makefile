# New ports collection makefile for:	aqbanking
# Date created:		June 2005
# Whom:                 Sam Lawrance <lawrance@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aqbanking
PORTVERSION=	1.0.11
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	aqbanking

MAINTAINER=	lawrance@FreeBSD.org
COMMENT=	Online banking interface and financial data framework

LIB_DEPENDS=	gwenhywfar.30:${PORTSDIR}/devel/gwenhywfar

OPTIONS=	OFX		"LibOFX support"	off	\
		KTOBLZCHECK	"KtoBlzCheck support"	off

CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_LIBTOOL_VER=15
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GCC=	3.4+
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_OFX)
LIB_DEPENDS+=	ofx.1:${PORTSDIR}/finance/libofx
CONFIGURE_ARGS+=--enable-libofx
PLIST_SUB+=	OFX=""
.else
CONFIGURE_ARGS+=--disable-libofx
PLIST_SUB+=	OFX="@comment "
.endif

# no configure option to disable ktoblzcheck support (yet)
.if defined(WITH_KTOBLZCHECK) || exists(${LOCALBASE}/lib/libktoblzcheck.so.1)
LIB_DEPENDS+=	ktoblzcheck.1:${PORTSDIR}/finance/ktoblzcheck
.endif

.include <bsd.port.post.mk>
