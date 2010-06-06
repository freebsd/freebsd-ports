# New ports collection makefile for:	cantus_3
# Date created:				18 May 2004
# Whom:					asa@gascom.ru
#
# $FreeBSD$
#

PORTNAME=	cantus
PORTVERSION=	3.0.2
PORTREVISION=	7
DISTVERSIONSUFFIX=	-testing.src
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/Testing%20%28unstable%29/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for tagging and renaming MP3 and OGG/Vorbis files

LIB_DEPENDS=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24 \
		glademm-2.4.1:${PORTSDIR}/devel/libglademm24 \
		ogg.7:${PORTSDIR}/audio/libogg \
		sigc-2.0.0:${PORTSDIR}/devel/libsigc++20 \
		vorbis.4:${PORTSDIR}/audio/libvorbis

CONFLICTS=	cantus-1*

LATEST_LINK=	${PORTNAME}3

USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix libglade2 glib20
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--program-transform-name="" --disable-static
WRKSRC=		${WRKDIR}/${DISTNAME:S/.src//}

post-patch:
	@${REINPLACE_CMD} -Ee 's|-ldld||g;s|-ldl||g;/ALL_LINGUAS=/s|=(.*)|="\1"|;\
		/LIBS=/s|-lgthr|${PTHREAD_LIBS} &|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-ldl||;s|-lrt||' ${WRKSRC}/source/cantus/Makefile.in
	@${REINPLACE_CMD} -e 's|PACKAGE_LIB_DIR "cantus-3.glade"|PACKAGE_DATA_DIR "/cantus/glade/cantus.glade"|'\
		${WRKSRC}/source/cantus/gui_controller.cc
	@${FIND} ${WRKSRC} -name "*.h" -o -name "*.cc" | ${XARGS} \
		${REINPLACE_CMD} -e 's|SigC::Slot3|sigc::slot3|g ; \
			s|SigC::Signal|sigc::signal|g ; \
			s|SigC::Object|sigc::trackable|g'

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
IGNORE=		includes i386 asm
.endif

.include <bsd.port.post.mk>
