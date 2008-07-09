# New ports collection makefile for:	aqbanking
# Date created:		June 2005
# Whom:                 Sam Lawrance <lawrance@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aqbanking
PORTVERSION=	2.3.3
PORTREVISION=	2
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	aqbanking

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Online banking interface and financial data framework

LIB_DEPENDS=	gwenhywfar.48:${PORTSDIR}/devel/gwenhywfar

OPTIONS=	KTOBLZCHECK	"KtoBlzCheck support"	off
#		OFX		"LibOFX support"	off

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GCC=	3.4+
USE_QT_VER=	3
QT_NONSTANDARD=	special flags for threading

CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib \
	${PTHREAD_CFLAGS}"
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include -L${LOCALBASE}/lib \
	${QTCPPFLAGS} ${PTHREAD_CFLAGS}"
CONFIGURE_ENV+=	LIBS="${QTCFGLIBS} ${PTHREAD_LIBS}"
CONFIGURE_ENV+=	QTDIR="${QT_PREFIX}"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--with-backends="aqhbci aqdtaus"
CONFIGURE_ARGS+=--with-qt-includes=${QT_PREFIX}/include \
		--with-qt-libraries=${QT_PREFIX}/lib \
		--with-extra-libs=${LOCALBASE}/lib \
		--with-extra-includes=${LOCALBASE}/include

.include <bsd.port.pre.mk>

#.if defined(WITH_OFX)
#LIB_DEPENDS+=	ofx.3:${PORTSDIR}/finance/libofx
#CONFIGURE_ARGS=	--with-backends="aqhbci aqdtaus aqofxconnect"
#CONFIGURE_ARGS+=--enable-libofx
#PLIST_SUB+=	OFX=""
#.else
CONFIGURE_ARGS+=--disable-libofx
PLIST_SUB+=	OFX="@comment "
#.endif

CONFIGURE_ARGS+= --with-frontends="cbanking qbanking"

# no configure option to disable ktoblzcheck support (yet)
.if defined(WITH_KTOBLZCHECK) || exists(${LOCALBASE}/lib/libktoblzcheck.so.4)
LIB_DEPENDS+=	ktoblzcheck.6:${PORTSDIR}/finance/ktoblzcheck
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|echo aout|echo elf|g" ${WRKSRC}/configure

.include <bsd.port.post.mk>
