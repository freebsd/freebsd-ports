# ports collection makefile for:   libmikmod
# Version required:    3.1.6
# Date created:        Sun Apr 11 13:06:01 PDT 1999
# Whom:                Michael Haro <mharo@area51.fremont.ca.us>
#
# $Id$
#

DISTNAME=	libmikmod-3.1.6
CATEGORIES=	audio
MASTER_SITES=	http://www.multimania.com/miodrag/mikmod/

MAINTAINER=	mharo@area51.fremont.ca.us

BUILD_DEPENDS=	libtool:${PORTSDIR}/devel/libtool

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

pre-build:
	${RM} -rf ${WRKSRC}/info/mikmod.info*

pre-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
	if [ ! -f ${PREFIX}/info/dir ]; then \
		${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi

.include <bsd.port.mk>
