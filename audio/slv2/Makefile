# New ports collection makefile for:	slv2
# Date created:		2008-11-25
# Whom:			xaimus <xaimus@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	slv2
PORTVERSION=	0.6.6
CATEGORIES=	audio
MASTER_SITES=	http://download.drobilla.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LV2 Application Support Library

LICENSE=	GPLv2 # (or later)
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/lv2.h:${PORTSDIR}/audio/lv2core
LIB_DEPENDS=	jack.0:${PORTSDIR}/audio/jack \
		rdf.0:${PORTSDIR}/textproc/redland

USE_BZIP2=	yes
USE_PYTHON_BUILD=	yes
USE_LDCONFIG=	yes
USE_PKGCONFIG=	yes
MAKE_JOBS_SAFE=	yes

.include <bsd.port.pre.mk>

.if defined(BATCH) || defined(PACKAGE_BUILDING)
WAF_VERBOSE=	--verbose
.endif

.if defined(MAKE_JOBS_NUMBER)
WAF_JOBS=	--jobs=${MAKE_JOBS_NUMBER}
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/pkgconfig/s|$${LIBDIRNAME}|libdata|' ${WRKSRC}/autowaf.py
	@${REINPLACE_CMD} -e \
		'/autowaf.build_dox/s|^|#| ; \
		 /HTMLDIR/s|^|#| ; \
		 /MANDIR/s|^|#|' ${WRKSRC}/wscript
	@${REINPLACE_CMD} -e \
		's|^#define _XOPEN_SOURCE .*||' ${WRKSRC}/src/plugin.c

do-configure:
	@(cd ${WRKSRC} && ./waf ${WAF_VERBOSE} --prefix=${PREFIX} configure)

do-build:
	@(cd ${WRKSRC} && ./waf ${WAF_VERBOSE} ${WAF_JOBS} build)

do-install:
	@(cd ${WRKSRC} && ./waf ${WAF_VERBOSE} install)
.for file in lv2_inspect lv2_jack_host lv2_list lv2_simple_jack_host
	@${STRIP_CMD} ${PREFIX}/bin/${file}
.endfor

.include <bsd.port.post.mk>
