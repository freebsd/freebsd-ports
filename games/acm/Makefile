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
USE_PERL5=	build
USE_XORG=	x11 xext
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --x-includes=${LOCALBASE}/include \
		--x-libraries=${LOCALBASE}/lib
CONFIGURE_ENV=	ac_cv_lib_Xm_XmCreateBulletinBoard=no \
		ac_cv_lib_gdbm_dbm_fetch=no
MAKE_ARGS=	prefix=${STAGEDIR}${PREFIX}/ OBVDIR=${STAGEDIR}${DATADIR}/

OPTIONS_DEFINE=	SOUND

SOUND_LIB_DEPENDS=	libaudio.so:audio/nas
SOUND_CONFIGURE_ENV_OFF=	ac_cv_lib_audio_AuCloseServer=no

.include <bsd.port.mk>
