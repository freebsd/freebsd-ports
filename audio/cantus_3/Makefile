# Created by: asa@gascom.ru
# $FreeBSD$

PORTNAME=	cantus
PORTVERSION=	3.0.2
PORTREVISION=	9
DISTVERSIONSUFFIX=	-testing.src
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/Testing%20%28unstable%29/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for tagging and renaming MP3 and OGG/Vorbis files

LIB_DEPENDS=	libgtkmm-2.4.so:${PORTSDIR}/x11-toolkits/gtkmm24 \
		libglademm-2.4.so:${PORTSDIR}/devel/libglademm24 \
		libogg.so:${PORTSDIR}/audio/libogg \
		libsigc-2.0.so:${PORTSDIR}/devel/libsigc++20 \
		libvorbis.so:${PORTSDIR}/audio/libvorbis

CONFLICTS=	cantus-1*

LATEST_LINK=	${PORTNAME}3

NO_STAGE=	yes
USES=		gmake pathfix gettext pkgconfig
USE_GNOME=	gnomeprefix libglade2 glib20
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform-name="" --disable-static
WRKSRC=		${WRKDIR}/${DISTNAME:S/.src//}

NO_PACKAGE=	hangs on pointyhat

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
