# New ports collection makefile for:	KDE2 Multimedia
# Date created:				Saturday 2 September 2000
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdemultimedia
PORTVERSION=	3.0
PORTREVISION=	1
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org

RUN_DEPENDS=	xanim:${PORTSDIR}/graphics/xanim
LIB_DEPENDS+=	ogg.3:${PORTSDIR}/audio/libogg \
		vorbis.1:${PORTSDIR}/audio/libvorbis

USE_KDELIBS_VER=3
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
.if defined(PARALLEL_PACKAGE_BUILD) || defined(WANT_KDE_NDEBUG)
CONFIGURE_ARGS+=--disable-debug
.endif
USE_GMAKE=	yes
MAKE_ENV=	${CONFIGURE_ENV}

# spurious, but i don't care
.include <bsd.port.pre.mk>

post-install:
	@${ECHO_MSG}
	@${ECHO_MSG} "In order to run the kscd program properly, please run as root:"
	@${ECHO_MSG}
	@${ECHO_MSG} " # ${LN} -sf <cdrom_device> /dev/cdrom"
	@${ECHO_MSG} " # ${CHMOD} 666 <cdrom_device>"
	@${ECHO_MSG}
	@${ECHO_MSG} "to link and give permission to access the CD-ROM device."
	@${ECHO_MSG} "For example, if you have an IDE/ATAPI CD-ROM device:"
	@${ECHO_MSG}
	@${ECHO_MSG} " # ${LN} -sf /dev/racd0c /dev/cdrom"
	@${ECHO_MSG} " # ${CHMOD} 666 /dev/racd0c"
	@${ECHO_MSG}

.include <bsd.port.post.mk>
