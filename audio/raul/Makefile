# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	raul
PORTVERSION=	0.8.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://download.drobilla.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ utility library primarily aimed at audio/musical applications

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

LIB_DEPENDS=	boost_date_time:${PORTSDIR}/devel/boost-libs

USE_BZIP2=	yes
USE_GNOME=	glib20
USE_PYTHON_BUILD=yes
USE_LDCONFIG=	yes

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
	@(cd ${WRKSRC} && ./waf ${WAF_VERBOSE} --prefix=${PREFIX} configure)

do-build:
	@(cd ${WRKSRC} && ./waf ${WAF_VERBOSE} ${WAF_JOBS} build)

do-install:
	@(cd ${WRKSRC} && ./waf ${WAF_VERBOSE} install)

.include <bsd.port.post.mk>
