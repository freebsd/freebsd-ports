# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	patchage
PORTVERSION=	0.5.0
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://download.drobilla.net/ \
		http://frugalware.mirrors.tds.net/pub/linux/frugalware/frugalware-current/source/xmultimedia-extra/patchage/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modular patch bay for Jack

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

LIB_DEPENDS=	jack.0:${PORTSDIR}/audio/jack \
		raul.10:${PORTSDIR}/audio/raul \
		boost_date_time:${PORTSDIR}/devel/boost-libs \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		glibmm-2.4.1:${PORTSDIR}/devel/glibmm \
		glademm-2.4:${PORTSDIR}/devel/libglademm24 \
		flowcanvas.5:${PORTSDIR}/x11-toolkits/flowcanvas

USE_BZIP2=	yes
USE_PYTHON_BUILD=yes
INSTALLS_ICONS=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		patchage.1

CFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.pre.mk>

.if defined(BATCH) || defined(PACKAGE_BUILDING)
WAF_VERBOSE=	--verbose
.endif

.if defined(MAKE_JOBS_NUMBER)
WAF_JOBS=	--jobs=${MAKE_JOBS_NUMBER}
.endif

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
	@(cd ${WRKSRC} && ./waf ${WAF_VERBOSE} install)

.include <bsd.port.post.mk>
