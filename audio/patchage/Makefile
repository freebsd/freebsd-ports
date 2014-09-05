# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	patchage
PORTVERSION=	0.5.0
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://download.drobilla.net/ \
		http://frugalware.mirrors.tds.net/pub/linux/frugalware/frugalware-current/source/xmultimedia-extra/patchage/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modular patch bay for Jack

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

LIB_DEPENDS=	libjack.so:${PORTSDIR}/audio/jack \
		libraul.so:${PORTSDIR}/audio/raul \
		libboost_date_time.so:${PORTSDIR}/devel/boost-libs \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libglibmm-2.4.so:${PORTSDIR}/devel/glibmm \
		libglademm-2.4.so:${PORTSDIR}/devel/libglademm24 \
		libflowcanvas.so:${PORTSDIR}/x11-toolkits/flowcanvas

USES=		pkgconfig tar:bzip2
USE_PYTHON_BUILD=yes
INSTALLS_ICONS=	yes

CFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.pre.mk>

.if defined(BATCH) || defined(PACKAGE_BUILDING)
WAF_VERBOSE=	--verbose
.endif

WAF_JOBS=	--jobs=${MAKE_JOBS_NUMBER}

post-patch:
	@${REINPLACE_CMD} -e \
		"s|$$[{]LIBDIRNAME[}]/pkgconfig|libdata/pkgconfig| ; \
		 s|-fshow-column'|-fshow-column ${CXXFLAGS}'|" \
			${WRKSRC}/autowaf/autowaf.py

do-configure:
	@(cd ${WRKSRC} && ./waf ${WAF_VERBOSE} --prefix=${PREFIX} \
		--mandir=${MANPREFIX}/man --no-alsa --no-lash configure)

do-build:
	@(cd ${WRKSRC} && ./waf ${WAF_VERBOSE} ${WAF_JOBS} build)

do-install:
	@(cd ${WRKSRC} && ./waf ${WAF_VERBOSE} --destdir=${STAGEDIR} install)

.include <bsd.port.post.mk>
