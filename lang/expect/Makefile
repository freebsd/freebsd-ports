# New ports collection makefile for:	expect
# Date created:		20 November 1994
# Whom:			pst
#
# $FreeBSD$

PORTNAME=	expect
PORTVERSION=	5.43.0
PORTREVISION=	3
CATEGORIES=	lang tcl tk
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A sophisticated scripter based on tcl/tk

CONFLICTS=	expect-5.44* weather-[0-9]*

PORTSCOUT=	skipv:5.44.0,5.44.1	# These were recalled by NIST

EXPECT_VER=	5.43
LIBEXPECT_VER=	543

WRKSRC=		${WRKDIR}/expect-${EXPECT_VER}
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

PLIST_SUB+=	EXPECT_VER="${EXPECT_VER}"
PLIST_SUB+=	LIBEXPECT_VER="${LIBEXPECT_VER}"

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=	X11

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
LIB_DEPENDS?=	tk84.1:${PORTSDIR}/x11-toolkits/tk84
.else
LIB_DEPENDS?=	tcl84.1:${PORTSDIR}/lang/tcl84
.endif

.if ${PORT_OPTIONS:MX11}
TK_CONFIG_ARGS=	--with-tkconfig=${LOCALBASE}/lib/tk8.4 \
		--with-tkinclude=${LOCALBASE}/include/tk8.4
PLIST_SUB+=	XFILES=""
.else
TK_CONFIG_ARGS=
PLIST_SUB+=	XFILES="@comment "
.endif

CONFIGURE_ARGS?=--enable-shared \
		--with-tclconfig=${LOCALBASE}/lib/tcl8.4 \
		--with-tclinclude=${LOCALBASE}/include/tcl8.4 \
		${TK_CONFIG_ARGS}

.if !defined(NO_MAN_INSTALL)
MAN1=		autoexpect.1 cryptdir.1 decryptdir.1 dislocate.1 \
		expect.1 kibitz.1 mkpasswd.1 multixterm.1 passmass.1 \
		tknewsbiff.1 unbuffer.1 xkibitz.1
.if ${PORT_OPTIONS:MX11}
MAN1+=		expectk.1
.endif
MAN3=		libexpect.3
.endif

post-patch:
	${TOUCH} ${WRKSRC}/configure

post-install:
	${LN} -sf libexpect${LIBEXPECT_VER}.so.1 \
		${PREFIX}/lib/libexpect${LIBEXPECT_VER}.so

.include <bsd.port.mk>
