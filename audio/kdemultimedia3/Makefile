# New ports collection makefile for:	KDE2 Multimedia
# Date created:				Saturday 2 September 2000
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdemultimedia
PORTVERSION=	2.2.2
PORTREVISION=	2
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org

BUILD_DEPENDS=	autoconf213:${PORTSDIR}/devel/autoconf213 \
		automake14:${PORTSDIR}/devel/automake14
LIB_DEPENDS=	ogg.3:${PORTSDIR}/audio/libogg \
		vorbis.1:${PORTSDIR}/audio/libvorbis
RUN_DEPENDS=	xanim:${PORTSDIR}/graphics/xanim

USE_KDELIBS_VER=2
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-qt-includes=${X11BASE}/include/qt2 \
		--with-qt-libraries=${X11BASE}/lib

_NO_KDE_FINAL=	yes
.include "${.CURDIR}/../../x11/kde2/Makefile.kde"

USE_GMAKE=	yes
MAKE_ENV=	${CONFIGURE_ENV}

.include <bsd.port.pre.mk>

pre-configure:
	${PERL} -pi -e "s@all_includes=\"@all_includes=\"-I/usr/include @g" \
		${WRKSRC}/acinclude.m4 ${WRKSRC}/aclocal.m4
	${PERL} -pi -e \
		's,kscd_compile=no,kscd_compile=yes,g; \
		s,kde_artsplug_compiles = xno,kde_artsplug_compiles = x,g' \
		${WRKSRC}/kscd/configure.in.in
	${MKDIR} ${WRKSRC}/auto-bin
.for AC in autoconf autoheader
	${LN} -sf ${LOCALBASE}/bin/${AC}213 ${WRKSRC}/auto-bin/${AC}
.endfor
.for AM in automake aclocal
	${LN} -sf ${LOCALBASE}/bin/${AM}14 ${WRKSRC}/auto-bin/${AM}
.endfor
	cd ${WRKSRC} && env PATH=${WRKSRC}/auto-bin:$$PATH \
		${GMAKE} -f Makefile.cvs

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
