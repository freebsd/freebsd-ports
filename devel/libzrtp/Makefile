# New ports collection makefile for:   libzrtp for freeswitch
# Date created:        3 December 2010
# Whom:                rneese@gmail.com
#
# $FreeBSD$
#

PORTNAME=	libzrtp
PORTVERSION=	0.81.514
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	# http://philzimmermann.com/zfone/EN/registration/index.html

MAINTAINER=	r.neese@gmail.com
COMMENT=	ZRTP library from the Zfone SDK

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=   yes

CFLAGS+=        -fPIC

PATCH_WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/projects/gnu

RESTRICTED=	Forbidden by license

.include <bsd.port.pre.mk>

# Check for sources
.if !exists(${DISTDIR}/${DISTFILES})
DISTFILE_INSTRUCTIONS=\n\
Due to licensing restrictions, certain files must be fetched manually.\n\n\
Please register to download the LINUX version of the Zfone SDK at\n\
http://philzimmermann.com/zfone/EN/registration/index.html\n\n\n\
After downloading the SDK, extract the library source\n\
${DISTFILES}\n\n\
place it in ${DISTDIR}, and restart the build.\n\n
.endif

pre-fetch:
.if defined(DISTFILE_INSTRUCTIONS) && !defined(PACKAGE_BUILDING)
	@${PRINTF} "${DISTFILE_INSTRUCTIONS}"
	@exit 1
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's|./configure CFLAGS="-O0 -g3"|./configure CFLAGS="-O0 -g3 -fPIC"|g' ${WRKDIR}/${PORTNAME}-${PORTVERSION}/third_party/bnlib/cfg.debug

post-patch:
	@cd ${PATCH_WRKSRC}/src && \
		${FIND} * -type f -exec ${REINPLACE_CMD} -i "" -e "s|<malloc.h>|<stdlib.h>|g" "{}" \; && \
			${FIND} * -type f -exec ${REINPLACE_CMD} -i "" -e "s|<stdint.h>|<inttypes.h>|g" "{}" \;
	@${REINPLACE_CMD} -e "s|-lpthread|${PTHREAD_LIBS}|g" ${WRKSRC}/${CONFIGURE_SCRIPT}

test:
	cd ${WRKDIR}/${PORTNAME}-${PORTVERSION}/projects/gnu && make check

.include <bsd.port.post.mk>
