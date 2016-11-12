# Created by: joerg
# $FreeBSD$

PORTNAME=	acm
PORTVERSION=	5.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Aerial combat simulator for X11

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		perl5
USE_XORG=	x11 xext
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--x-includes=${LOCALBASE}/include \
		--x-libraries=${LOCALBASE}/lib
CONFIGURE_ENV=	ac_cv_lib_Xm_XmCreateBulletinBoard=no \
		ac_cv_lib_gdbm_dbm_fetch=no
USE_PERL5=	build
MAKE_ARGS+=	prefix=${STAGEDIR}${PREFIX}/ OBVDIR=${STAGEDIR}${DATADIR}/

BROKEN_aarch64=	Fails to compile: machine/limits.h not found

OPTIONS_DEFINE=	SOUND

SOUND_LIB_DEPENDS=	libaudio.so:audio/nas

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MSOUND)
CONFIGURE_ENV+=	ac_cv_lib_audio_AuCloseServer=no
.endif

.include <bsd.port.mk>
