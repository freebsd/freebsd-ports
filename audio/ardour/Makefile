# New ports collection makefile for:	ardour
# Date created:		2006-12-04
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	ardour
DISTVERSION=	2.0beta12
CATEGORIES=	audio
MASTER_SITES=	http://ardour.org/files/releases/

MAINTAINER=	trasz@freebsd.org
COMMENT=	Ardour - a digital audio workstation

LIB_DEPENDS=	lrdf.2:${PORTSDIR}/textproc/liblrdf \
		raptor.2:${PORTSDIR}/textproc/raptor \
		samplerate.1:${PORTSDIR}/audio/libsamplerate \
		jack.0:${PORTSDIR}/audio/jack \
		sndfile.1:${PORTSDIR}/audio/libsndfile \
		boost_date_time.3:${PORTSDIR}/devel/boost \
		gnomecanvasmm-2.6:${PORTSDIR}/graphics/libgnomecanvasmm26 \
		sqlite3:${PORTSDIR}/databases/sqlite3 \
		lo.6:${PORTSDIR}/audio/liblo \
		SoundTouch.0:${PORTSDIR}/audio/soundtouch

USE_SCONS=	yes
SCONS_ENV+=	SYSLIBS=yes PREFIX=${PREFIX} NLS=yes FPU_OPTIMIZATION=0
USE_BZIP2=	yes
USE_GNOME=	gtk20 libxslt libgnomecanvas intltool
USE_GETTEXT=	yes
USE_LDCONFIG=	${PREFIX}/lib/ardour2 ${PREFIX}/lib/ardour2/surfaces
TEMPLATESDIR=	${PREFIX}/share/ardour2/templates
PLIST_SUB=	DISTVERSION=${DISTVERSION}

.include <bsd.port.pre.mk>

# Upstream uses these flags by default.
.if !defined(WITHOUT_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -fomit-frame-pointer -ffast-math -fstrength-reduce
.endif

CFLAGS:=	${CFLAGS:N-fno-strict-aliasing}

post-patch:
	${REINPLACE_CMD} -e "s|%%CFLAGS%%|${CFLAGS}|" ${WRKSRC}/SConstruct
	${REINPLACE_CMD} -e "s|alsa_pcm|oss|g" ${WRKSRC}/templates/*.template

post-install:
	${CHOWN} -R 0:0 ${PREFIX}/lib/ardour2/
	${CHMOD} -R a+rX ${PREFIX}/lib/ardour2/
	${CHOWN} -R 0:0 ${PREFIX}/etc/ardour2/
	${CHMOD} -R a+rX ${PREFIX}/etc/ardour2/
	${CHOWN} -R 0:0 ${PREFIX}/share/ardour2/
	${CHMOD} -R a+rX ${PREFIX}/share/ardour2/
	${MKDIR} ${TEMPLATESDIR}
	${INSTALL_DATA} ${WRKSRC}/templates/*.template ${TEMPLATESDIR}/

.include <bsd.port.post.mk>
